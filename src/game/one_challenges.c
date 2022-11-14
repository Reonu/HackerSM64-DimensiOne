#include "sm64.h"
#include "game_init.h"
#include "level_update.h"
#include "one_challenges.h"
#include "one_text.h"
#include "puppyprint.h"
#include "audio/external.h"

// Actual data for all challenges
static struct OneChallengeLevel sChallengeLevels[sizeof(u32)*8] = {
    {    /*00*/
        (CHALLENGE_FLAG_COIN | CHALLENGE_FLAG_JUMP), // Requirements (i.e. "At least one of")
        (CHALLENGE_FLAG_COIN | CHALLENGE_FLAG_B_PRESS), // Enforcements (i.e. "No more than one of")
    }, { /*01*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*02*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*03*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*04*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*05*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*06*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*07*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*08*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*09*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*10*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*11*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*12*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*13*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*14*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*15*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*16*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*17*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*18*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*19*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*20*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*21*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*22*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*23*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*24*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*25*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*26*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*27*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*28*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*29*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*30*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }, { /*31*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_NONE), // Enforcements
    }
};


// What is the current level of the challenge?
u8 gChallengeLevel = (u8) -1; // ONE_TODO: Save file support?

// What is the current status of the challenge?
u32 gChallengeStatus = CHALLENGE_STATUS_NOT_PLAYING;
// u32 gChallengeStatus = CHALLENGE_STATUS_NOT_PLAYING;

// Flags of which challenge conditions have been met by the player
u32 sObtainedChallengeFlags = CHALLENGE_FLAG_NONE;

// Which challenges are being enforced? (i.e. if one of these conditions is met more than once e.g. pressing A twice, automatically fail the challenge)
u32 sEnforcedChallengeFlags = CHALLENGE_FLAG_NONE;

// Which of these challenges are required in order to beat the level? (e.g. must collect one coin, or must kill one goomba)
u32 sRequiredChallengeFlags = CHALLENGE_FLAG_NONE;

// Which flags have been overacquired?
u32 sFailureFlags = CHALLENGE_FLAG_NONE;


static u32 lastMarioAction = ACT_UNINITIALIZED;
static u8 hasLeftGround = FALSE;


static u8 is_challenge_active(void) {
    return (
        gChallengeStatus == CHALLENGE_STATUS_PLAYING ||
        gChallengeStatus == CHALLENGE_STATUS_CAN_WIN
    );
}

static void can_win_challenge(void) {
    if (gChallengeStatus != CHALLENGE_STATUS_PLAYING) {
        return;
    }

    gChallengeStatus = CHALLENGE_STATUS_CAN_WIN;
    // ONE_TODO: cutscene trigger or something?
}

static void lose_challenge(void) {
    if (!is_challenge_active()) {
        return;
    }

    gChallengeStatus = CHALLENGE_STATUS_LOSE;
    // ONE_TODO: more loser stuffs
}

static void check_flag_conditions(void) {
    struct MarioState *m = gMarioState;

    if (m == NULL) {
        return;
    }

    // CHALLENGE_FLAG_GROUND
    if (m->action != lastMarioAction) {
        lastMarioAction = m->action;

        // Allow water for this; not technically ground but it's good enough.
        if (lastMarioAction & ACT_FLAG_AIR) {
            hasLeftGround = TRUE;
            add_challenge_flags(CHALLENGE_FLAG_GROUND);
        } else if (hasLeftGround) {
            // This should cause the challenge to fail
            add_challenge_flags(CHALLENGE_FLAG_GROUND);
        }
    }

    // CHALLENGE_FLAG_A_PRESS
    if (gPlayer1Controller->buttonPressed & A_BUTTON) {
        add_challenge_flags(CHALLENGE_FLAG_A_PRESS);
    }

    // CHALLENGE_FLAG_B_PRESS
    if (gPlayer1Controller->buttonPressed & B_BUTTON) {
        add_challenge_flags(CHALLENGE_FLAG_B_PRESS);
    }
}


// What is the current status of the challenge?
u32 get_challenge_obtained_flags(void) {
    return sObtainedChallengeFlags;
}

// Flags of which challenge conditions have been met by the player
u32 get_challenge_enforced_flags(void) {
    return sEnforcedChallengeFlags;
}

// Which challenges are being enforced? (i.e. if one of these conditions is met more than once e.g. pressing A twice, automatically fail the challenge)
u32 get_challenge_required_flags(void) {
    return sRequiredChallengeFlags;
}

// Which of these challenges are required in order to beat the level? (e.g. must collect one coin, or must kill one goomba)
u32 get_challenge_failure_flags(void) {
    return sFailureFlags;
}

// Clear all obtained challenge flags
void reset_challenge(void) {
    gChallengeStatus = CHALLENGE_STATUS_NOT_PLAYING;

    sObtainedChallengeFlags = CHALLENGE_FLAG_NONE;
    sFailureFlags = CHALLENGE_FLAG_NONE;

    sRequiredChallengeFlags = sChallengeLevels[gChallengeLevel].requiredFlags;
    sEnforcedChallengeFlags = sChallengeLevels[gChallengeLevel].enforcedFlags;

    hasLeftGround = FALSE;
    lastMarioAction = ACT_UNINITIALIZED;

    update_last_print_vars(sObtainedChallengeFlags, sFailureFlags);
}

// Increase the challenge level and start next challenge
void start_next_challenge_level(void) {
    gChallengeLevel++;

    if (gChallengeLevel >= sizeof(u32) * 8) {
        gChallengeLevel = (sizeof(u32) * 8) - 1;
    }

    start_challenge();
}

// Start up a new challenge level
void start_challenge(void) {
    if (gChallengeLevel == 0xFF) {
        start_next_challenge_level();
        return;
    }

    reset_challenge();

    // ONE_TODO: Warp?

    gChallengeStatus = CHALLENGE_STATUS_PLAYING;
}

// Apply a challenge flag or flags when a condition is met; overall challenge success/failure can be determined here automatically. Return true if flags were newly applied.
u8 add_challenge_flags(u32 flags) {
    u32 existingFlags;
    u32 existingRequiredFlags;

    // Don't set a flag if challenge is not currently active
    if (!is_challenge_active()) {
        return FALSE;
    }

    existingFlags = sObtainedChallengeFlags & flags;

    // Has a flag already been used?
    if (existingFlags) {
        // Player has unacceptably acquired a flag twice, automatic loss!
        if (sEnforcedChallengeFlags & existingFlags) {
            sFailureFlags |= (sEnforcedChallengeFlags & existingFlags);
            lose_challenge();
        }

        if (flags == existingFlags) {
            return FALSE;
        }
    }

    existingRequiredFlags = sObtainedChallengeFlags & sRequiredChallengeFlags;
    sObtainedChallengeFlags |= flags;

    // Has challenge resolved itself within this function?
    if (!is_challenge_active()) {
        return TRUE;
    }

    // Have requirements changed?
    if ((sObtainedChallengeFlags & sRequiredChallengeFlags) != existingRequiredFlags) {
        // Are all requirements met?
        if ((sObtainedChallengeFlags & sRequiredChallengeFlags) != sRequiredChallengeFlags) {
            // ONE_TODO: Play flag collected sound?
        } else {
            // ONE_TODO: Play flag collected sound, but more grand?
            can_win_challenge();
        }
    }

    return TRUE;
}

void challenge_update(void) {
    // ONE_TODO: Delete this
    if (gChallengeLevel == 0xFF) {
        print_set_envcolour(0xFF, 0xFF, 0xFF, 0xFF);
        print_small_text(16, SCREEN_HEIGHT - 24, "Press L to display/reset challenge 1!", PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_OUTLINE);
    }

    if (gPlayer1Controller->buttonPressed & L_TRIG) {
        if (
            // ONE_TODO: future conditions
            // gChallengeStatus != CHALLENGE_STATUS_NOT_PLAYING &&
            gChallengeStatus != CHALLENGE_STATUS_WIN
        ) {
            start_challenge();
        }
    }

    if (gChallengeStatus == CHALLENGE_STATUS_NOT_PLAYING) {
        update_last_print_vars(sObtainedChallengeFlags, sFailureFlags);
        return;
    }

    check_flag_conditions();

    // ONE_TODO: update HUD/text elements?

    print_challenge_types();

    update_last_print_vars(sObtainedChallengeFlags, sFailureFlags);
}
