#include "sm64.h"
#include "debug.h"
#include "game_init.h"
#include "level_update.h"
#include "one_challenges.h"
#include "one_text.h"
#include "puppyprint.h"
#include "audio/external.h"

#include "one_text_strings.c.in"

u32 challengeTypeDisplayTimer = -1U;
u32 challengeTypeStatusLast = CHALLENGE_STATUS_NOT_PLAYING;

static char* get_challenge_type_text_entry(u8 typeIndex) {
    s32 arrayVal = 0;
    u32 requiredFlags = get_challenge_required_flags();
    u32 enforcedFlags = get_challenge_enforced_flags();

    if (requiredFlags & (1U << typeIndex)) {
        arrayVal += (1 << 0);
    }

    if (enforcedFlags & (1U << typeIndex)) {
        arrayVal += (1 << 1);
    }

    arrayVal--;

    if (arrayVal < 0) {
        return NULL; // Not being used in the challenge
    }

    return gChallengeTypesArr[arrayVal][typeIndex];
}

#define FADE_IN_FRAMES 30
#define FADE_OUT_FRAMES 30
#define FADE_OUT_AFTER_FRAMES (FADE_IN_FRAMES + 150)
void print_challenge_types(void) {
    static u32 timer = -1U;

    if (gChallengeStatus != challengeTypeStatusLast) {
        challengeTypeStatusLast = gChallengeStatus;
        if (gChallengeStatus == CHALLENGE_STATUS_PLAYING) {
            timer = 0;
        }
    }

    if (gChallengeStatus == CHALLENGE_STATUS_NOT_PLAYING) {
        return;
    }

    u8 alpha = 0;
    if (timer < FADE_OUT_AFTER_FRAMES + FADE_OUT_FRAMES) {
        alpha = 255;

        if (timer < FADE_IN_FRAMES) {
            alpha = 255.0f * (timer / (f32) FADE_IN_FRAMES);
        } else if (timer > FADE_OUT_AFTER_FRAMES) {
            alpha = 255.0f * (((FADE_OUT_AFTER_FRAMES + FADE_OUT_FRAMES) - timer) / (f32) FADE_OUT_FRAMES);
        }
    }

    if (timer != -1U) {
        timer++;
    }

    if (alpha == 0) {
        return;
    }

    // Actual display stuff yay
    const s32 lineSpacing = 32;

    const s32 x = 24 + 8 + (4*2); // Image width + 8px border + 4px border on both sides of image
    s32 y = SCREEN_HEIGHT - 12 - (24 / 2) - 8 - 4; // screen height - puppyprint text height - half of image height - 8px border - 4px bottom margin

    for (s32 i = 0; i < CHALLENGE_NAME_TOTAL; i++) {
        char *str = get_challenge_type_text_entry(i);
        if (str == NULL) {
            continue;
        }

        print_set_envcolour(0xFF, 0xFF, 0xFF, alpha);

        print_small_text(x, y, str, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_OUTLINE);

        y -= lineSpacing;
    }
}
#undef FADE_IN_FRAMES
#undef FADE_OUT_FRAMES
#undef FADE_OUT_AFTER_FRAMES
