#include "sm64.h"
#include "debug.h"
#include "game_init.h"
#include "level_update.h"
#include "one_challenges.h"
#include "one_text.h"
#include "puppyprint.h"
#include "audio/external.h"
#include "engine/math_util.h"
#include "segment2.h"

#include "one_text_strings.c.in"

u32 typeTimerArray[CHALLENGE_NAME_TOTAL] = {0};

u32 challengeTypeDisplayTimer = -1U;

static u32 sObtainedChallengeFlagsLast = CHALLENGE_FLAG_NONE;
static u32 sFailureFlagsLast = CHALLENGE_FLAG_NONE;
static u32 sChallengesPrintTimer = -1U;


static char* get_challenge_type_text_entry(u8 typeIndex) {
    s32 arrayVal = 0;
    u32 enforcedFlags = get_challenge_enforced_flags();
    u32 requiredFlags = get_challenge_required_flags();

    // Stupid way of getting an array index, but it works for 2 entries that combine into a third...
    if (enforcedFlags & (1U << typeIndex)) {
        arrayVal |= (1 << 0);
    }
    if (requiredFlags & (1U << typeIndex)) {
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

    u32 typeFlag = (1U << typeIndex);
    u32 obtainedFlags = get_challenge_obtained_flags();
    u32 enforcedFlags = get_challenge_enforced_flags();
    u32 requiredFlags = get_challenge_required_flags();
    u32 failureFlags = get_challenge_failure_flags();

    if (challengeTypeDisplayTimer < alphaFrames) {
        color[3] = 255.0f * (challengeTypeDisplayTimer / (f32) alphaFrames); // Fade in
    }

    if (failureFlags & typeFlag) {
        if (!(sFailureFlagsLast & typeFlag)) {
            typeTimerArray[typeIndex] = 0;
        }

        color[0] = 0xFF;
        color[1] = 0x00;
        color[2] = 0x00;
        color[3] = color[3] * 0.8f;

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
            color[3] = color[3] * 0.8f;
        } else if (requiredFlags & typeFlag) {
            color[0] = 0x00;
            color[1] = 0xFF;
            color[2] = 0x00;
            color[3] = color[3] * 0.8f;
        } 

        if (typeTimerArray[typeIndex] < 6) {
            y += 0.5f + 2.0f * sins(0x8000 + ((0x8000 * typeTimerArray[typeIndex]) / 6)); // Acquire an objective, animate it if required
        }
    } else if (requiredFlags & typeFlag) {
        color[0] = 0x0F;
        color[1] = 0x0F;
        color[2] = 0x0F;
        color[3] = color[3] * 0.67f;
    } else if (enforcedFlags & typeFlag) {
        color[0] = 0xBF;
        color[1] = 0xBF;
        color[2] = 0xBF;
        color[3] = color[3] * 0.8f;
    }

    Gfx *circle = segmented_to_virtual(circle_init_dl);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, color[0], color[1], color[2], color[3]);
    gSPDisplayList(gDisplayListHead++, circle);
    gSPScisTextureRectangle(
        gDisplayListHead++,
        qs102(x), qs102(y),
        qs102(x + 24), qs102(y + 24),
        G_TX_RENDERTILE,
        0, 0, // s/t low
        qs510(1), qs510(1) 
    );

    if (typeTimerArray[typeIndex] != -1U) {
        typeTimerArray[typeIndex]++;
    }
    
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
    gDPPipeSync(gDisplayListHead++);
}


void clear_challenge_print_timers(void) {
    bzero(typeTimerArray, sizeof(typeTimerArray));
    sObtainedChallengeFlagsLast = get_challenge_obtained_flags();
    sFailureFlagsLast = get_challenge_failure_flags();

    sChallengesPrintTimer = 0;
}

#define FADE_IN_FRAMES 30
#define FADE_OUT_FRAMES 30
#define FADE_OUT_AFTER_FRAMES (FADE_IN_FRAMES + 150)
void print_challenge_types(void) {
    if (gChallengeStatus == CHALLENGE_STATUS_NOT_PLAYING) {
        return;
    }

    u8 alpha = 0;
    if (sChallengesPrintTimer < FADE_OUT_AFTER_FRAMES + FADE_OUT_FRAMES) {
        alpha = 255;

        if (sChallengesPrintTimer < FADE_IN_FRAMES) {
            alpha = 255.0f * (sChallengesPrintTimer / (f32) FADE_IN_FRAMES);
        } else if (sChallengesPrintTimer > FADE_OUT_AFTER_FRAMES) {
            alpha = 255.0f * (((FADE_OUT_AFTER_FRAMES + FADE_OUT_FRAMES) - sChallengesPrintTimer) / (f32) FADE_OUT_FRAMES);
        }
    }

    if (sChallengesPrintTimer != -1U) {
        sChallengesPrintTimer++;
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
            print_small_text(x, y, str, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_DEFAULT);
        }

        y -= lineSpacing;
    }

    print_set_envcolour(0xFF, 0xFF, 0xFF, 0xFF);
    print_small_text(SCREEN_WIDTH / 2, 12, gChallengeHeaderText[gChallengeLevel], PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_DEFAULT);
    print_set_envcolour(0xFF, 0xFF, 0xFF, alpha);
    print_small_text(SCREEN_WIDTH / 2, 29, gChallengeHeaderBodyText[gChallengeLevel], PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_DEFAULT);
}
#undef FADE_IN_FRAMES
#undef FADE_OUT_FRAMES
#undef FADE_OUT_AFTER_FRAMES

void update_last_print_vars(u32 obtained, u32 failure) {
    sObtainedChallengeFlagsLast = obtained;
    sFailureFlagsLast = failure;
}
