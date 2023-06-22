#include "sm64.h"
#include "debug.h"
#include "game_init.h"
#include "ingame_menu.h"
#include "level_update.h"
#include "object_list_processor.h"
#include "one_challenges.h"
#include "one_text.h"
#include "puppyprint.h"
#include "audio/external.h"
#include "engine/math_util.h"
#include "segment2.h"

#include "one_text_strings.c.in"

u32 typeTimerArray[CHALLENGE_NAME_TOTAL] = {0};

u32 challengeTypeDisplayTimer = -1U;

static oneflags_t sObtainedChallengeFlagsLast = CHALLENGE_FLAG_NONE;
static oneflags_t sFailureFlagsLast = CHALLENGE_FLAG_NONE;
u32 gChallengesPrintTimer = -1U;

#ifdef ENABLE_CHALLENGE_SELECTIONS
s32 gChallengeWarpPauseIndex = 1;
s32 gChallengeScroll = 2;

static s8 dpadUpHeldFrames = 0;
static s8 dpadDownHeldFrames = 0;
static s8 dpadLeftHeldFrames = 0;
static s8 dpadRightHeldFrames = 0;

#define DISPLAY_MAX MIN(ARRAY_COUNT(gChallengeLevelData), 12)
#define SCROLL_FRAMES 10
s32 print_debug_challenge_select(void) {
    print_set_envcolour(0xFF, 0xFF, 0xFF, gDialogTextAlpha);
    print_small_text(SCREEN_WIDTH / 2, 48, "Debug Challenge Select", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_DEFAULT, TRUE);
    s32 lastIndex = gChallengeWarpPauseIndex;

    if ((gPlayer3Controller->rawStickY > 60) || gPlayer1Controller->buttonDown & (U_CBUTTONS | U_JPAD)) {
        if (dpadUpHeldFrames >= SCROLL_FRAMES || dpadUpHeldFrames == 0) {
            gChallengeWarpPauseIndex--;
            gChallengeScroll--;
        }
        dpadUpHeldFrames++;
        if (dpadUpHeldFrames > SCROLL_FRAMES) {
            dpadUpHeldFrames -= 2;
        }
    } else {
        dpadUpHeldFrames = 0;
    }
    if ((gPlayer3Controller->rawStickY < -60) || gPlayer1Controller->buttonDown & (D_CBUTTONS | D_JPAD)) {
        if (dpadDownHeldFrames >= SCROLL_FRAMES || dpadDownHeldFrames == 0) {
            gChallengeWarpPauseIndex++;
            gChallengeScroll++;
        }
        dpadDownHeldFrames++;
        if (dpadDownHeldFrames > SCROLL_FRAMES) {
            dpadDownHeldFrames -= 2;
        }
    } else {
        dpadDownHeldFrames = 0;
    }
    if ((gPlayer3Controller->rawStickX < -60) || gPlayer1Controller->buttonDown & (L_CBUTTONS | L_JPAD)) {
        if (dpadLeftHeldFrames >= SCROLL_FRAMES || dpadLeftHeldFrames == 0) {
            gChallengeWarpPauseIndex -= 10;
            gChallengeScroll -= 10;
        }
        dpadLeftHeldFrames++;
        if (dpadLeftHeldFrames > SCROLL_FRAMES) {
            dpadLeftHeldFrames -= 2;
        }
    } else {
        dpadLeftHeldFrames = 0;
    }
    if ((gPlayer3Controller->rawStickX > 60) || gPlayer1Controller->buttonDown & (R_CBUTTONS | R_JPAD)) {
        if (dpadRightHeldFrames >= SCROLL_FRAMES || dpadRightHeldFrames == 0) {
            gChallengeWarpPauseIndex += 10;
            gChallengeScroll += 10;
        }
        dpadRightHeldFrames++;
        if (dpadRightHeldFrames > SCROLL_FRAMES) {
            dpadRightHeldFrames -= 2;
        }
    } else {
        dpadRightHeldFrames = 0;
    }

    if (gChallengeWarpPauseIndex < 1) {
        gChallengeWarpPauseIndex = 1;
    } else if (gChallengeWarpPauseIndex >= ARRAY_COUNT(gChallengeLevelData)) {
        gChallengeWarpPauseIndex = ARRAY_COUNT(gChallengeLevelData) - 1;
    }

    if (gChallengeScroll < 2) {
        gChallengeScroll = 2;
    } else if (gChallengeScroll > (DISPLAY_MAX - 1) - 2) {
        gChallengeScroll = (DISPLAY_MAX - 1) - 2;
    }
    if ((ARRAY_COUNT(gChallengeLevelData) - 1) - gChallengeWarpPauseIndex < 2) {
        gChallengeScroll = DISPLAY_MAX - ((ARRAY_COUNT(gChallengeLevelData) - 1) - gChallengeWarpPauseIndex) - 1;
    }
    if (gChallengeWarpPauseIndex - 1 < 2) {
        gChallengeScroll = gChallengeWarpPauseIndex - 1;
    }

    s32 scrollStart = gChallengeWarpPauseIndex - gChallengeScroll;
    for (s32 i = 0; i < DISPLAY_MAX; i++, scrollStart++) {
        char buffer[128];

        sprintf(buffer, "%d: %s", scrollStart, gChallengeLevelData[scrollStart].challengeName);

        if (i == gChallengeScroll) {
            print_set_envcolour(0xFF, 0x7F, 0x00, gDialogTextAlpha);
            print_small_text((SCREEN_WIDTH / 4) - 6, (12 * i) + 72, "-", PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_DEFAULT, FALSE);
            print_set_envcolour(0xFF, 0x7F, 0x00, gDialogTextAlpha);
        } else {
            print_set_envcolour(0xFF, 0xFF, 0xFF, gDialogTextAlpha);
        }
        print_small_text(SCREEN_WIDTH / 4, (12 * i) + 72, buffer, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_DEFAULT, FALSE);
    }

    if (lastIndex != gChallengeWarpPauseIndex) {
        play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource);
    }

    if (gPlayer3Controller->buttonPressed & (A_BUTTON | B_BUTTON | START_BUTTON)) {
        dpadUpHeldFrames = 0;
        dpadDownHeldFrames = 0;
        dpadLeftHeldFrames = 0;
        dpadRightHeldFrames = 0;

        if (gPlayer3Controller->buttonPressed & A_BUTTON) { // B and Start should both just unpause
            return gChallengeWarpPauseIndex;
        }
    }

    return 0;
}
#undef DISPLAY_MAX
#undef SCROLL_FRAMES

#endif

static void loser_text(void) {
    if (gChallengeStatus != CHALLENGE_STATUS_LOSE) {
        return;
    }

    print_small_text(SCREEN_WIDTH / 2, 12, LOSER_STRING, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_DEFAULT, TRUE);
}

static void update_timer(void) {
    if (!((get_challenge_required_flags() | get_challenge_enforced_flags()) & CHALLENGE_FLAG_TIMER)) {
        return;
    }
    
    if (sCurrPlayMode != PLAY_MODE_PAUSED && is_challenge_active() && !((gTimeStopState & (TIME_STOP_ENABLED | TIME_STOP_ALL_OBJECTS)) == (TIME_STOP_ENABLED | TIME_STOP_ALL_OBJECTS))) {
        gChallengeTimer--;

        if (gChallengeTimer < 0) {
            add_challenge_flags(CHALLENGE_FLAG_TIMER);
            gChallengeTimer = 0;
        }
    }

    s32 seconds = gChallengeTimer / 30;
    s32 decaseconds = (gChallengeTimer % 30) / 3;

    char str[16];
    sprintf(str, "%d.%d", seconds, decaseconds);

    print_small_text(16, 12, str, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_DEFAULT, TRUE);
}

static char* get_challenge_type_text_entry(u8 typeIndex) {
    s32 arrayVal = 0;
    oneflags_t enforcedFlags = get_challenge_enforced_flags();
    oneflags_t requiredFlags = get_challenge_required_flags();

    // Stupid way of getting an array index, but it works for 2 entries that combine into a third...
    if (enforcedFlags & (1ULL << typeIndex)) {
        arrayVal |= (1 << 0);
    }
    if (requiredFlags & (1ULL << typeIndex)) {
        arrayVal |= (1 << 1);
    }
    arrayVal--;

    if (arrayVal < 0) {
        return NULL; // Not being used in the challenge
    }

    return gChallengeTypesArr[arrayVal][typeIndex];
}

static void print_challenge_type_images(s32 x, s32 y, u8 typeIndex, u8 alphaFrames) {
    x -= 28; // Size of image + 4px padding
    y -= 6;

    ColorRGBA color = {0xFF, 0xFF, 0xFF, 0xFF};
    Color alpha;

    oneflags_t typeFlag = (1ULL << typeIndex);
    oneflags_t obtainedFlags = get_challenge_obtained_flags();
    oneflags_t enforcedFlags = get_challenge_enforced_flags();
    oneflags_t requiredFlags = get_challenge_required_flags();
    oneflags_t failureFlags = get_challenge_failure_flags();

    if (challengeTypeDisplayTimer < alphaFrames) {
        color[3] = 255.0f * (challengeTypeDisplayTimer / (f32) alphaFrames); // Fade in
    }

    alpha = color[3];

    if (failureFlags & typeFlag) {
        if (!(sFailureFlagsLast & typeFlag)) {
            typeTimerArray[typeIndex] = 0;
        }

        color[0] = 0xFF;
        color[1] = 0x00;
        color[2] = 0x00;
        alpha = alpha * 0.8f;

        if (typeTimerArray[typeIndex] < 14) {
            x += 0.5f + 1.0f * sins((0x10000 * typeTimerArray[typeIndex]) / 4);
        }
    } else if (obtainedFlags & typeFlag) {
        if (!(sObtainedChallengeFlagsLast & typeFlag)) {
            typeTimerArray[typeIndex] = 0;
        }

        if (enforcedFlags & typeFlag) {
            color[0] = 0xDF;
            color[1] = 0xDF;
            color[2] = 0x00;
            alpha = alpha * 0.8f;
        } else if (requiredFlags & typeFlag) {
            color[0] = 0x00;
            color[1] = 0xFF;
            color[2] = 0x00;
            alpha = alpha * 0.8f;
        } 

        if (typeTimerArray[typeIndex] < 6) {
            y += 0.5f + 2.0f * sins(0x8000 + ((0x8000 * typeTimerArray[typeIndex]) / 6)); // Acquire an objective, animate it if required
        }
    } else if (requiredFlags & typeFlag) {
        color[0] = 0x0F;
        color[1] = 0x0F;
        color[2] = 0x0F;
        alpha = alpha * 0.67f;
    } else if (enforcedFlags & typeFlag) {
        color[0] = 0xBF;
        color[1] = 0xBF;
        color[2] = 0xBF;
        alpha = alpha * 0.8f;
    }

    Gfx *circle = segmented_to_virtual(circle_init_dl);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, color[0], color[1], color[2], alpha);
    gSPDisplayList(gDisplayListHead++, circle);
    gSPScisTextureRectangle(
        gDisplayListHead++,
        qs102(x), qs102(y),
        qs102(x + 24), qs102(y + 24),
        G_TX_RENDERTILE,
        0, 0, // s/t low
        qs510(1), qs510(1) 
    );
    gDPPipeSync(gDisplayListHead++);

    if (obtainedFlags & typeFlag || !(requiredFlags & typeFlag)) {
        gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 255, color[3]);
    } else {
        gDPSetPrimColor(gDisplayListHead++, 0, 0, 127, 127, 127, (u8) (color[3] * 0.5f));
    }

    gDPSetCombineLERP(
        gDisplayListHead++,
        0, 0, 0, TEXEL0,
        TEXEL0, 0, PRIMITIVE, 0,
        0, 0, 0, TEXEL0,
        TEXEL0, 0, PRIMITIVE, 0
    );

    Texture *(*icons)[] = segmented_to_virtual(&one_challenge_icons);
    gDPLoadTextureTile(
        gDisplayListHead++,
        (*icons)[typeIndex],
        G_IM_FMT_RGBA,
        G_IM_SIZ_16b,
        24, 24, // w/h
        0, 0, // uls,ult
        24, 24, // lrs,lrt
        0,
        (G_TX_NOMIRROR | G_TX_CLAMP), (G_TX_NOMIRROR | G_TX_CLAMP),
        0, 0,
        G_TX_NOLOD, G_TX_NOLOD);
    gSPScisTextureRectangle(
        gDisplayListHead++,
        qs102(x), qs102(y),
        qs102(x + 24), qs102(y + 24),
        G_TX_RENDERTILE,
        0, 0, // s/t low
        qs510(1), qs510(1) 
    );
    gDPPipeSync(gDisplayListHead++);

    if (typeTimerArray[typeIndex] != -1U) {
        typeTimerArray[typeIndex]++;
    }
    
    gSPDisplayList(gDisplayListHead++, dl_hud_img_end);
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
    gDPPipeSync(gDisplayListHead++);
}


void clear_challenge_print_timers(void) {
    bzero(typeTimerArray, sizeof(typeTimerArray));
    sObtainedChallengeFlagsLast = get_challenge_obtained_flags();
    sFailureFlagsLast = get_challenge_failure_flags();

    gChallengesPrintTimer = 0;
}

#define FADE_IN_FRAMES 30
#define FADE_OUT_FRAMES 30
#define FADE_OUT_AFTER_FRAMES (FADE_IN_FRAMES + 150)
void print_challenge_types(void) {
    if (gChallengeStatus == CHALLENGE_STATUS_NOT_PLAYING) {
        return;
    }

    u8 alpha = 0;
    if (gChallengesPrintTimer < FADE_OUT_AFTER_FRAMES + FADE_OUT_FRAMES) {
        alpha = 255;

        if (gChallengesPrintTimer < FADE_IN_FRAMES) {
            alpha = 255.0f * (gChallengesPrintTimer / (f32) FADE_IN_FRAMES);
        } else if (gChallengesPrintTimer > FADE_OUT_AFTER_FRAMES) {
            alpha = 255.0f * (((FADE_OUT_AFTER_FRAMES + FADE_OUT_FRAMES) - gChallengesPrintTimer) / (f32) FADE_OUT_FRAMES);
        }
    }

    if (
        gChallengesPrintTimer != -1U && (gChallengesPrintTimer < FADE_IN_FRAMES ||
        !(
            (gTimeStopState & TIME_STOP_ENABLED) ||
            sCurrPlayMode == PLAY_MODE_PAUSED
        ))
    ) {
        gChallengesPrintTimer++;
    }

    if (sCurrPlayMode == PLAY_MODE_PAUSED) {
        alpha = 255;
        if (gChallengesPrintTimer > FADE_OUT_AFTER_FRAMES) {
            gChallengesPrintTimer = FADE_OUT_AFTER_FRAMES;
        }
    }

    // Actual display stuff yay
    const s32 lineSpacing = 32;

    const s32 x = 24 + 8 + (4*2); // Image width + 8px border + 4px border on both sides of image
    s32 y = SCREEN_HEIGHT - 12 - (24 / 2) - 8; // screen height - puppyprint text height - half of image height - 8px border

    for (s32 i = 0; i < CHALLENGE_NAME_TOTAL; i++) {
        char *str = get_challenge_type_text_entry(i);
        if (str == NULL) {
            continue;
        }

        print_challenge_type_images(x, y, i, FADE_IN_FRAMES);

        if (alpha != 0) {
            print_set_envcolour(0xFF, 0xFF, 0xFF, alpha);
            print_small_text(x, y, str, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_DEFAULT, TRUE);
        }

        y -= lineSpacing;
    }

    if (gChallengeStatus == CHALLENGE_STATUS_LOSE) {
        print_set_envcolour(0xFF, 0xFF, 0xFF, 0xFF);
        loser_text();
    } else {
        char strBuf[16];
        sprintf(strBuf, "Challenge %d", gChallengeLevel);
        print_set_envcolour(0xFF, 0xFF, 0xFF, 0xFF);
        print_small_text(SCREEN_WIDTH / 2, 12, strBuf, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_DEFAULT, TRUE);
        print_set_envcolour(0xFF, 0xFF, 0xFF, alpha);
        print_small_text(SCREEN_WIDTH / 2, 29, gChallengeLevelData[gChallengeLevel].challengeName, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_DEFAULT, TRUE);
    }

    update_timer();
}
#undef FADE_IN_FRAMES
#undef FADE_OUT_FRAMES
#undef FADE_OUT_AFTER_FRAMES

void update_last_print_vars(oneflags_t obtained, oneflags_t failure) {
    sObtainedChallengeFlagsLast = obtained;
    sFailureFlagsLast = failure;
}
