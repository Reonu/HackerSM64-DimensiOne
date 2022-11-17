#include "sm64.h"
#include "area.h"
#include "game_init.h"
#include "level_update.h"
#include "one_challenges.h"
#include "one_text.h"
#include "puppyprint.h"
#include "audio/external.h"

// Actual data for all challenges
static struct OneChallengeLevel sChallengeLevels[sizeof(u32)*8] = {
    {    /*00*/
        (CHALLENGE_FLAG_COIN), // Requirements (i.e. "At least one of")
        (CHALLENGE_FLAG_COIN), // Enforcements (i.e. "No more than one of")
    }, { /*01*/
        (CHALLENGE_FLAG_NONE), // Requirements
        (CHALLENGE_FLAG_COIN), // Enforcements
    }, { /*02*/
        (CHALLENGE_FLAG_JUMP | CHALLENGE_FLAG_KILL_GOOMBA | CHALLENGE_FLAG_GROUND), // Requirements
        (CHALLENGE_FLAG_JUMP | CHALLENGE_FLAG_KILL_GOOMBA | CHALLENGE_FLAG_GROUND), // Enforcements
    }, { /*03*/
        (CHALLENGE_FLAG_KILL_GOOMBA | CHALLENGE_FLAG_GROUND), // Requirements
        (CHALLENGE_FLAG_KILL_GOOMBA | CHALLENGE_FLAG_GROUND), // Enforcements
    }, { /*04*/
        (CHALLENGE_FLAG_KILL_BOMB), // Requirements
        (CHALLENGE_FLAG_KILL_BOMB), // Enforcements
    }, { /*05*/
        (CHALLENGE_FLAG_KILL_ALL_BOMBS), // Requirements
        (CHALLENGE_FLAG_KILL_ALL_BOMBS), // Enforcements
    }, { /*06*/
        (CHALLENGE_FLAG_WALLKICK | CHALLENGE_FLAG_GROUND), // Requirements
        (CHALLENGE_FLAG_WALLKICK | CHALLENGE_FLAG_GROUND), // Enforcements
    }, { /*07*/
        (CHALLENGE_FLAG_KILL_GOOMBA_WITH_BOMB), // Requirements
        (CHALLENGE_FLAG_KILL_GOOMBA_WITH_BOMB), // Enforcements
    }, { /*08*/
        (CHALLENGE_FLAG_KNOCKED_KOOPA | CHALLENGE_FLAG_GROUND), // Requirements  TODO: for this challenge only, add on timer flag after meeting knocked Koopa condition
        (CHALLENGE_FLAG_KNOCKED_KOOPA | CHALLENGE_FLAG_GROUND | CHALLENGE_FLAG_KILL_KOOPA), // Enforcements
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

// Flags of which challenge conditions have been met by the player
u32 sObtainedChallengeFlags = CHALLENGE_FLAG_NONE;

// Which challenges are being enforced? (i.e. if one of these conditions is met more than once e.g. pressing A twice, automatically fail the challenge)
u32 sEnforcedChallengeFlags = CHALLENGE_FLAG_NONE;

// Which of these challenges are required in order to beat the level? (e.g. must collect one coin, or must kill one goomba)
u32 sRequiredChallengeFlags = CHALLENGE_FLAG_NONE;

// Which flags have been overacquired?
u32 sFailureFlags = CHALLENGE_FLAG_NONE;

// Temporary set of flags to be applied at end of frame
u32 internalFlagsForFrame = CHALLENGE_FLAG_NONE;


static u8 freshlyTouchedGround = FALSE;


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

    // NOTE: Race conditions can happen with collecting the star on the same frame as losing.
    // Star collect gets priority, so be careful with any cutscene effects here; maybe delay execution by a frame with a status check?

    // ONE_TODO: more loser stuffs
}

static void check_flag_conditions(void) {
    struct MarioState *m = gMarioState;

    if (m == NULL) {
        return;
    }

    // CHALLENGE_FLAG_GROUND
    if (m->action & (ACT_FLAG_AIR | ACT_FLAG_ON_POLE | ACT_FLAG_HANGING | ACT_FLAG_SWIMMING | ACT_FLAG_RIDING_SHELL)) { // Shell debatable here
        freshlyTouchedGround = TRUE;
    } else if (freshlyTouchedGround && m->action != ACT_DEBUG_FREE_MOVE) {
        freshlyTouchedGround = FALSE;
        add_challenge_flags(CHALLENGE_FLAG_GROUND);
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

// Apply internal challenge flags at end of frame for when a condition or conditions is/are met; overall challenge success/failure can be determined here automatically.
static void add_challenge_flags_internal(void) {
    u32 existingFlags;
    u32 existingRequiredFlags;

    // Don't set a flag if challenge is not currently active
    if (!is_challenge_active()) {
        internalFlagsForFrame = CHALLENGE_FLAG_NONE;
        return;
    }

    existingFlags = sObtainedChallengeFlags & internalFlagsForFrame;

    // Has a flag already been used?
    if (existingFlags) {
        // Player has unacceptably acquired a flag twice, automatic loss!
        if (sEnforcedChallengeFlags & existingFlags) {
            sFailureFlags |= (sEnforcedChallengeFlags & existingFlags);
            lose_challenge();
        }

        if (internalFlagsForFrame == existingFlags) {
            internalFlagsForFrame = CHALLENGE_FLAG_NONE;
            return;
        }
    }

    existingRequiredFlags = sObtainedChallengeFlags & sRequiredChallengeFlags;
    sObtainedChallengeFlags |= internalFlagsForFrame;

    // Has challenge resolved itself within this function?
    if (!is_challenge_active()) {
        internalFlagsForFrame = CHALLENGE_FLAG_NONE;
        return;
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

    internalFlagsForFrame = CHALLENGE_FLAG_NONE;
    return;
}


// Is there a challenge actively going on?
u8 is_challenge_active(void) {
    return (
        gChallengeStatus == CHALLENGE_STATUS_PLAYING ||
        gChallengeStatus == CHALLENGE_STATUS_CAN_WIN
    );
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
    sObtainedChallengeFlags = CHALLENGE_FLAG_NONE;
    sFailureFlags = CHALLENGE_FLAG_NONE;

    sRequiredChallengeFlags = sChallengeLevels[gChallengeLevel].requiredFlags;
    sEnforcedChallengeFlags = sChallengeLevels[gChallengeLevel].enforcedFlags;

    internalFlagsForFrame = CHALLENGE_FLAG_NONE;

    freshlyTouchedGround = TRUE;

    gChallengeStatus = CHALLENGE_STATUS_NOT_PLAYING;
    update_last_print_vars(sObtainedChallengeFlags, sFailureFlags);
    gChallengeStatus = CHALLENGE_STATUS_PLAYING;

    if (sRequiredChallengeFlags == CHALLENGE_FLAG_NONE) {
        gChallengeStatus = CHALLENGE_STATUS_CAN_WIN;
    }
    
    clear_challenge_print_timers();
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
}

// Apply a challenge flag or flags when a condition is met; updated automatically at end of frame.
void add_challenge_flags(u32 flags) {
    internalFlagsForFrame |= flags;
}

#define ALL_LETTERS "!\"#$%&'()*+,-./\n0123456789:;<=>?@\nABCDEFGHIJKLMNOPQRSTUVWXYZ\n[\\]^_`\nabcdefghijklmnopqrstuvwxyz{|}~"
#define PRESS_L_TO_RESTART "Press " PP_COL_TMP("FF00FF--", "L") PP_WAVE " to start or reset the challenges!"

void challenge_update(void) {
    // ONE_TODO: Delete this
    if (gChallengeLevel == 0xFF) {
        print_set_envcolour(0xFF, 0xFF, 0xFF, 0xFF);
        print_small_text(16, SCREEN_HEIGHT - 24, PRESS_L_TO_RESTART, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_DEFAULT);
        // print_small_text(16, SCREEN_HEIGHT - 64, ALL_LETTERS, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_DEFAULT);
    }

#ifdef USE_PROFILER
    if ((gPlayer1Controller->buttonPressed & L_TRIG) && !(gPlayer1Controller->buttonDown & U_JPAD)) {
#else
    if (gPlayer1Controller->buttonPressed & L_TRIG) {
#endif
        if (
            // ONE_TODO: future conditions
            // gChallengeStatus != CHALLENGE_STATUS_NOT_PLAYING &&
            gChallengeStatus != CHALLENGE_STATUS_WIN &&
            !gWarpTransition.isActive
        ) {
            level_trigger_warp(gMarioState, WARP_OP_START_CHALLENGES); // reset level
        }
    }

#ifdef ENABLE_DEBUG_FREE_MOVE
    if (
        (gPlayer1Controller->buttonDown & (Z_TRIG | R_TRIG)) == (Z_TRIG | R_TRIG) &&
        (gPlayer1Controller->buttonPressed & (Z_TRIG | R_TRIG))
    ) {
        if (
            gChallengeStatus != CHALLENGE_STATUS_NOT_PLAYING &&
            sDelayedWarpOp == WARP_OP_NONE &&
            !gWarpTransition.isActive
        ) {
            gChallengeStatus = CHALLENGE_STATUS_WIN;
            level_trigger_warp(gMarioState, WARP_OP_DEBUG_CHALLENGE_SKIP); // warp to next challenge
        }
    }
#endif

    if (gChallengeStatus == CHALLENGE_STATUS_NOT_PLAYING) {
        update_last_print_vars(sObtainedChallengeFlags, sFailureFlags);
        return;
    }

    check_flag_conditions();

    add_challenge_flags_internal();

    print_challenge_types();

    update_last_print_vars(sObtainedChallengeFlags, sFailureFlags);
}
