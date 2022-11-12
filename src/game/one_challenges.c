#include "sm64.h"
#include "game_init.h"
#include "level_update.h"
#include "one_challenges.h"
#include "puppyprint.h"
#include "audio/external.h"


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

    hasLeftGround = FALSE;
    lastMarioAction = ACT_UNINITIALIZED;
}

// Set new challenge flags, ideally for a new challenge/level
void new_challenge_flags(u32 enforcedFlags, u32 requiredFlags) {
    reset_challenge();

    sEnforcedChallengeFlags = enforcedFlags;
    sRequiredChallengeFlags = requiredFlags;
}

// Start up a new challenge level
void start_challenge(void) {
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
    if (gChallengeStatus == CHALLENGE_STATUS_NOT_PLAYING) {
        return;
    }

    check_flag_conditions();

    // ONE_TODO: update HUD/text elements?
}
