#include <ultra64.h>
#include <PR/gs2dex.h>

#include "types.h"
#include "game_init.h"
#include "fb_effects.h"
#include "buffers/framebuffers.h"
#include "buffers/zbuffer.h"
#include "puppyprint.h"
#include "engine/math_util.h"
#include "segment2.h"
#include "print.h"


extern u16 sRenderedFramebuffer;
extern u8 gFBE;

s32 sCurBlur = 0;
s32 sGoalBlur = 0;
u32 sFBEType = FBE_EFFECT_BRIGHTEN;


#define FUNNY_FBE_COLOR 0xFF00
#define MOTION_BLUR_APP_RATE 8

s32 check_fbe(void) {
    static u8 checkingFBE = 0;
    static u8 checkedFBE = FALSE;

    if (checkedFBE) return gFBE;
    else if (!checkedFBE && (gIsConsole || gCacheEmulated)) {
        checkedFBE = gFBE = TRUE;
        return TRUE;
    }

    if (checkingFBE == 0) {
        checkingFBE = TRUE;
        gFramebuffers[0][12] = FUNNY_FBE_COLOR;
    } else if (checkingFBE < 3) {
        checkingFBE++;
    } else {
        checkedFBE = TRUE;
        gFBE = gFramebuffers[0][12] != FUNNY_FBE_COLOR;
    }

    return gFBE;
}

void run_motion_blur(s32 goalAmount) {
    sGoalBlur = goalAmount;
}

void render_tiled_screen_effect(Texture *image, s32 width, s32 height, s32 mode) {
    s32 posW, posH, imW, imH, mOne;
    s32 i     = 0;
    s32 num   = 256;
    s32 maskW = 1;
    s32 maskH = 1;

    if (mode == G_CYC_COPY) {
        gDPSetCycleType( gDisplayListHead++, mode);
        gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
        mOne   = 1;
    } else {
        gDPSetCycleType( gDisplayListHead++, mode);
        gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        mOne   = 0;
    }

    // Find how best to seperate the horizontal. Keep going until it finds a whole value.
    while (TRUE) {
        f32 val = (f32)width / (f32)num;

        if ((s32)val == val && (s32) val >= 1) {
            imW = num;
            break;
        }
        num /= 2;
    }
    // Find the tile height
    imH = 64 / (imW / 32); // This gets the vertical amount.

    num = 2;
    // Find the width mask
    while (TRUE) {
        if ((s32) num == imW) {
            break;
        }
        num *= 2;
        maskW++;
        if (maskW == 9) {
            print_text(32, 32, "WIDTH MASK FAILURE");
            return;
        }
    }
    num = 2;
    // Find the height mask
    while (TRUE) {
        if ((s32) num == imH) {
            break;
        }
        num *= 2;
        maskH++;
        if (maskH == 9) {
            print_text(32, 32, "HEIGHT MASK FAILURE");
            return;
        }
    }
    num = height;
    // Find the height remainder
    s32 peakH  = height - (height % imH);
    s32 cycles = (width * peakH) / (imW * imH);

    // Pass 1
    for (i = 0; i < cycles; i++) {
        posW = 0;
        posH = i * imH;
        while (posH >= peakH) {
            posW += imW;
            posH -= peakH;
        }

        gDPLoadSync(gDisplayListHead++);
        gDPLoadTextureTile(gDisplayListHead++,
            image,
            G_IM_FMT_RGBA,
            G_IM_SIZ_16b,
            width,
            height,
            posW,
            posH,
            ((posW + imW) - 1),
            ((posH + imH) - 1),
            0,
            (G_TX_NOMIRROR | G_TX_WRAP),
            (G_TX_NOMIRROR | G_TX_WRAP),
            6,
            5,
            0,
            0
        );
        gSPScisTextureRectangle(gDisplayListHead++,
            posW << 2,
            posH << 2,
            ((posW + imW) - mOne) << 2,
            ((posH + imH) - mOne) << 2,
            G_TX_RENDERTILE,
            0,
            0,
            1 << 10,
            1 << 10
        );
    }
    // If there's a remainder on the vertical side, then it will cycle through that too.
    if (height-peakH != 0) {
        posW = 0;
        posH = peakH;
        for (i = 0; i < (width / imW); i++) {
            posW = i * imW;
            gDPLoadSync(gDisplayListHead++);
            gDPLoadTextureTile(gDisplayListHead++,
                image,
                G_IM_FMT_RGBA,
                G_IM_SIZ_16b,
                width,
                height,
                posW,
                posH,
                ((posW + imW) - 1),
                (height - 1),
                0,
                (G_TX_NOMIRROR | G_TX_WRAP),
                (G_TX_NOMIRROR | G_TX_WRAP),
                6,
                5,
                0,
                0
            );
            gSPScisTextureRectangle(gDisplayListHead++,
                posW << 2,
                posH << 2,
                ((posW + imW) - mOne) << 2,
                ((posH + imH) - mOne) << 2,
                G_TX_RENDERTILE, 0, 0,
                1 << 10,
                1 << 10
            );
        }
    }
}



void render_motion_blur(s32 amount) {
    if (sFBEType == FBE_EFFECT_BRIGHTEN) {
        gDPSetCombineLERP(gDisplayListHead++,
            1, TEXEL0, ENVIRONMENT, TEXEL0,
            0, 0, 0, ENVIRONMENT,
            1, TEXEL0, ENVIRONMENT, TEXEL0,
            0, 0, 0, ENVIRONMENT
        );
    } else {
        gDPSetCombineLERP(gDisplayListHead++,
            TEXEL0, 0, ENVIRONMENT, 0,
            0, 0, 0, ENVIRONMENT,
            TEXEL0, 0, ENVIRONMENT, 0,
            0, 0, 0, ENVIRONMENT
        );
    }

    gDPSetEnvColor(gDisplayListHead++, 0, 100, 150, amount);
    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gDPSetColorDither(gDisplayListHead++, G_CD_NOISE);
    gDPSetAlphaDither(gDisplayListHead++, G_AD_NOISE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);

    if (gFBE) {
        render_tiled_screen_effect((u8 *)gFramebuffers[sRenderedFramebuffer], SCREEN_WIDTH, SCREEN_HEIGHT, G_CYC_1CYCLE);
    } else {
        u8 *emu_tex = segmented_to_virtual(youre_emu);
        render_tiled_screen_effect(emu_tex, SCREEN_WIDTH, SCREEN_HEIGHT, G_CYC_1CYCLE);
    }

    gDPSetColorDither(gDisplayListHead++, G_CD_MAGICSQ);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
}

void render_fb_effects(void) {
    check_fbe();
    // if (!check_fbe()) {
    //     return;
    // }

    if (sGoalBlur > 200) {
        sCurBlur = approach_s32_symmetric(sCurBlur, sGoalBlur, MOTION_BLUR_APP_RATE);
        sCurBlur = approach_s16_asymptotic(sCurBlur, sGoalBlur, 10);
    } else {
        sCurBlur = approach_s32_symmetric(sCurBlur, sGoalBlur, MOTION_BLUR_APP_RATE);
    }
    
    if (sCurBlur > 0) {
        render_motion_blur(sCurBlur);
    }
    sGoalBlur = 0;
}
