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
#include "levels/intro/header.h"


extern u16 sRenderedFramebuffer;
extern u8 gFBE;

s32 sCurBlur = 0;
s32 sGoalBlur = 0;

FBEffects sFBEffects = {
    .r = 255,
    .g = 255,
    .b = 255,
    .a = 255,
    .type = FBE_EFFECT_MULT,
};

#define FUNNY_FBE_COLOR 0xFF00
#define MOTION_BLUR_APP_RATE 8

static u8 checkingFBE = 0;
static u8 checkedFBE = FALSE;
s32 check_fbe(void) {

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

void set_motion_blur(s32 goalAmount) {
    sGoalBlur = goalAmount;
    sFBEffects.a = CLAMP_U8(goalAmount);
}

void set_fb_effect_type(u32 type) {
    sFBEffects.type = type;
}

void set_fb_effect_col(u8 r, u8 g, u8 b) {
    sFBEffects.r = r;
    sFBEffects.g = g;
    sFBEffects.b = b;
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
    }
    num = 2;
    // Find the height mask
    while (TRUE) {
        if ((s32) num == imH) {
            break;
        }
        num *= 2;
        maskH++;
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
            qs102(posW),
            qs102(posH),
            qs102((posW + imW) - mOne),
            qs102((posH + imH) - mOne),
            G_TX_RENDERTILE,
            0,
            0,
            qs510(1),
            qs510(1)
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
                posW, // uls
                posH, // ult
                ((posW + imW) - 1), // lrs
                gIsConsole ? (height - 1) : ((posH + imH) - 1), // lrt
                0,
                (G_TX_NOMIRROR | G_TX_WRAP),
                (G_TX_NOMIRROR | G_TX_WRAP),
                6,
                5,
                0,
                0
            );
            gSPScisTextureRectangle(gDisplayListHead++,
                qs102(posW),
                qs102(posH),
                qs102((posW + imW) - mOne),
                qs102((posH + imH) - mOne),
                G_TX_RENDERTILE,
                0,
                0,
                qs510(1),
                qs510(1)
            );
        }
    }
}



void render_motion_blur(void) {
    if (sFBEffects.type == FBE_EFFECT_BRIGHTEN) {
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

    gDPSetEnvColor(gDisplayListHead++, sFBEffects.r, sFBEffects.g, sFBEffects.b, sFBEffects.a);
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

static s32 sVerifiedFBE = FALSE; 

void render_fb_effects(void) {
    check_fbe();
    if (!checkedFBE) return;

    if (sGoalBlur > 200) {
        sFBEffects.a = approach_s16_asymptotic(sFBEffects.a, sGoalBlur, 18);
    } else {
        sFBEffects.a = approach_s32_symmetric(sFBEffects.a, sGoalBlur, MOTION_BLUR_APP_RATE);
    }
    
    if (sFBEffects.a > 0) {
        render_motion_blur();
    }
    sGoalBlur = 0;
    if (!sVerifiedFBE) {
        render_fbe_warning();
    }
}

s32 render_fbe_warning(void) {
    if (gFBE || !checkedFBE) return FALSE;

    f32 s = sins(gGlobalTimer*DEGREES(4));
    s = 1.0f - sqr(sqr(s));
    s32 bloob = roundf(120 - ((s / 2.0f) * 120.0f));

    gDPSetEnvColor(gDisplayListHead++, bloob, 0, 0, 255);

    gDPSetCombineLERP(gDisplayListHead++,
        NOISE, 0, ENVIRONMENT, TEXEL0,
        0, 0, 0, 1,
        NOISE, 0, ENVIRONMENT, TEXEL0,
        0, 0, 0, 1
    );

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gDPSetColorDither(gDisplayListHead++, G_CD_NOISE);
    gDPSetAlphaDither(gDisplayListHead++, G_AD_NOISE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);

    u8 *emu_tex = segmented_to_virtual(fbe_warning);
    render_tiled_screen_effect(emu_tex, SCREEN_WIDTH, SCREEN_HEIGHT, G_CYC_1CYCLE);

    gDPSetColorDither(gDisplayListHead++, G_CD_MAGICSQ);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    return FALSE;
}

s32 script_check_fbe_warning(UNUSED s16 arg) {
    if (!checkedFBE) return FALSE;
    if (gFBE) {
        sVerifiedFBE = TRUE;
        return TRUE;
    }
    if (
        (gPlayer1Controller->buttonDown & (Z_TRIG | A_BUTTON | START_BUTTON)) == (Z_TRIG | A_BUTTON | START_BUTTON) &&
        (gPlayer1Controller->buttonPressed & (Z_TRIG | A_BUTTON | START_BUTTON))
    ) {
        sVerifiedFBE = TRUE;
        return TRUE;
    }

    return FALSE;
}
