#include "sm64.h"
#include "seq_ids.h"
#include "area.h"
#include "game_init.h"
#include "level_update.h"
#include "one_challenges.h"
#include "one_text.h"
#include "puppyprint.h"
#include "sound_init.h"
#include "object_list_processor.h"
#include "audio/external.h"
#include "engine/math_util.h"
#include "fb_effects.h"
#include "rendering_graph_node.h"


// Actual data for all challenges
#include "one_challenge_structs.c.in"


// What is the current level of the challenge?
u8 gChallengeLevel = 0xFF; // ONE_TODO: Save file support?

// What is the current status of the challenge?
u32 gChallengeStatus = CHALLENGE_STATUS_NOT_PLAYING;

// How many Bob-ombs have been spawned into the level?
u16 gBombsSpawned = 0xFFFF;

// One-minute timer used for the challenges that need it
s32 gChallengeTimer;

// Randomly selected moneybag becomes coin
s32 gMoneybagSwap = 0;
s32 gMoneybagCount = 0;

// Flags of which challenge conditions have been met by the player
oneflags_t sObtainedChallengeFlags = CHALLENGE_FLAG_NONE;

// Which challenges are being enforced? (i.e. if one of these conditions is met more than once e.g. pressing A twice, automatically fail the challenge)
oneflags_t sEnforcedChallengeFlags = CHALLENGE_FLAG_NONE;

// Which of these challenges are required in order to beat the level? (e.g. must collect one coin, or must kill one goomba)
oneflags_t sRequiredChallengeFlags = CHALLENGE_FLAG_NONE;

// Which flags have been overacquired?
oneflags_t sFailureFlags = CHALLENGE_FLAG_NONE;

// Temporary set of flags to be applied at end of frame
oneflags_t internalFlagsForFrame = CHALLENGE_FLAG_NONE;


u8 gSetChallengeMusic = FALSE;


static u8 freshlyTouchedGround = FALSE;
static u16 sBombsSpawnedLast = 0;

static u8 sGoombasKilled = 0;
static u8 sKoopasKilled = 0;
static u8 sKoopasInteracted = 0;
static u8 sBombsKilled = 0;
static u8 sPiranhasDisturbed = 0;
static u8 sGoombasKilledWithBombs = 0;
static u8 sMoneybagsKilled = 0;
static u8 sLivesCollected = 0;
u8 gWaitingToStart = TRUE;


static void can_win_challenge(void) {
    if (gChallengeStatus != CHALLENGE_STATUS_PLAYING) {
        return;
    }

    if (gChallengeLevel == 9 && !(sRequiredChallengeFlags & CHALLENGE_FLAG_TIMER)) {
        sRequiredChallengeFlags |= CHALLENGE_FLAG_TIMER;
        gChallengesPrintTimer = 0;
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

static void process_kill_flags(void) {
    if (sGoombasKilled > 0) {
        sGoombasKilled--;
        add_challenge_flags(CHALLENGE_FLAG_KILL_GOOMBA);
    }
    if (sKoopasKilled > 0) {
        sKoopasKilled--;
        add_challenge_flags(CHALLENGE_FLAG_KILL_KOOPA);
    }
    if (sKoopasInteracted > 0) {
        sKoopasInteracted--;
        add_challenge_flags(CHALLENGE_FLAG_INTERACTED_KOOPA);
    }
    if (sBombsKilled > 0) {
        sBombsKilled--;
        add_challenge_flags(CHALLENGE_FLAG_KILL_BOMB);
    }
    if (sPiranhasDisturbed > 0) {
        sPiranhasDisturbed--;
        add_challenge_flags(CHALLENGE_FLAG_SLEEPING_PIRANHA);
    }
    if (sGoombasKilledWithBombs > 0) {
        sGoombasKilledWithBombs--;
        add_challenge_flags(CHALLENGE_FLAG_KILL_GOOMBA_WITH_BOMB);
    }
    if (sMoneybagsKilled > 0) {
        sMoneybagsKilled--;
        add_challenge_flags(CHALLENGE_FLAG_KILL_MONEYBAG);
    }
    if (sLivesCollected > 0) {
        sLivesCollected--;
        add_challenge_flags(CHALLENGE_FLAG_COLLECT_LIFE);
    }
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

    // CHALLENGE_FLAG_KILL_ALL_BOMBS
    if (gBombsSpawned >= (u16) -3) {
        gBombsSpawned--; // Process 3 frames later instead, just in case the bombs haven't spawned in yet (hacky but oh well)
    } else if (gBombsSpawned & 0x8000) {
        if (gBombsSpawned >= 0xFFF0) { // No bombs were spawned
            gBombsSpawned = 0;
            sBombsSpawnedLast = 2; // Trigger 2 bomb spawn flags
        } else {
            gBombsSpawned &= ~0x8000;
            sBombsSpawnedLast = gBombsSpawned;
        }
    }
    if (sBombsSpawnedLast < gBombsSpawned) {
        sBombsSpawnedLast = gBombsSpawned;
    } else if (sBombsSpawnedLast > gBombsSpawned) {
        sBombsSpawnedLast--;
        if (sBombsSpawnedLast <= 1) {
            add_challenge_flags(CHALLENGE_FLAG_KILL_ALL_BOMBS);
        }
    }

    process_kill_flags();
}

// Apply internal challenge flags at end of frame for when a condition or conditions is/are met; overall challenge success/failure can be determined here automatically.
static void add_challenge_flags_internal(void) {
    oneflags_t existingFlags;
    oneflags_t existingRequiredFlags;

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

// Flags of which challenge conditions have been met by the player
oneflags_t get_challenge_obtained_flags(void) {
    return sObtainedChallengeFlags;
}

// Which challenges are being enforced? (i.e. if one of these conditions is met more than once e.g. pressing A twice, automatically fail the challenge)
oneflags_t get_challenge_enforced_flags(void) {
    return sEnforcedChallengeFlags;
}

// Which of these challenges are required in order to beat the level? (e.g. must collect one coin, or must kill one goomba)
oneflags_t get_challenge_required_flags(void) {
    return sRequiredChallengeFlags;
}

// Which challenge(s) did the player actively fail (if applicable)?
oneflags_t get_challenge_failure_flags(void) {
    return sFailureFlags;
}

// Clear all obtained challenge flags
void reset_challenge(void) {
    sObtainedChallengeFlags = CHALLENGE_FLAG_NONE;
    sFailureFlags = CHALLENGE_FLAG_NONE;

    sRequiredChallengeFlags = gChallengeLevelData[gChallengeLevel].requiredFlags;
    sEnforcedChallengeFlags = gChallengeLevelData[gChallengeLevel].enforcedFlags;

    internalFlagsForFrame = CHALLENGE_FLAG_NONE;

    freshlyTouchedGround = TRUE;
    gBombsSpawned = 0xFFFF;
    sBombsSpawnedLast = 0;
    
    sGoombasKilled = 0;
    sKoopasKilled = 0;
    sKoopasInteracted = 0;
    sBombsKilled = 0;
    sPiranhasDisturbed = 0;
    sGoombasKilledWithBombs = 0;
    sMoneybagsKilled = 0;
    sLivesCollected = 0;

    gMoneybagSwap = random_u16() % 22;
    gMoneybagCount = 0;

    gChallengeTimer = 60 * 30; // 1 minute

    if (gChallengeStatus == CHALLENGE_STATUS_NOT_PLAYING) {
        gChallengeStatus = CHALLENGE_STATUS_PLAYING;
        gSetChallengeMusic = TRUE;
    }

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

    if (gChallengeLevel == 0) {
        gChallengeLevel++;
    }

    if (gChallengeLevel >= ARRAY_COUNT(gChallengeLevelData)) {
        gChallengeLevel = ARRAY_COUNT(gChallengeLevelData) - 1;
    }

    start_challenge();
}

// Start up a new challenge level
void start_challenge(void) {
    gWaitingToStart = TRUE;

    if (gChallengeLevel == 0xFF) {
        start_next_challenge_level();
        return;
    }

    if (gChallengeLevel == 0) {
        gChallengeLevel++;
    }

    reset_challenge();
}

// Apply a challenge flag or flags when a condition is met; updated automatically at end of frame.
void add_challenge_flags(oneflags_t flags) {
    internalFlagsForFrame |= flags;
}

// add_challenge_flags(), but allows case stacking, particularly for killing of multiple enemies on the same frame.
void add_challenge_kill_flags(oneflags_t flags) {
    if (flags & CHALLENGE_FLAG_KILL_KOOPA) {
        sKoopasInteracted++; // Special case here
        sKoopasKilled++;
    }
    if (flags & CHALLENGE_FLAG_KILL_GOOMBA)
        sGoombasKilled++;
    if (flags & CHALLENGE_FLAG_KILL_BOMB)
        sBombsKilled++;
    if (flags & CHALLENGE_FLAG_SLEEPING_PIRANHA)
        sPiranhasDisturbed++;
    if (flags & CHALLENGE_FLAG_KILL_GOOMBA_WITH_BOMB)
        sGoombasKilledWithBombs++;
    if (flags & CHALLENGE_FLAG_KILL_MONEYBAG)
        sMoneybagsKilled++;
    if (flags & CHALLENGE_FLAG_COLLECT_LIFE)
        sLivesCollected++;
}

#define ALL_LETTERS "!\"#$%&'()*+,-./\n0123456789:;<=>?@\nABCDEFGHIJKLMNOPQRSTUVWXYZ\n[\\]^_`\nabcdefghijklmnopqrstuvwxyz{|}~"
#define PRESS_L_TO_RESTART "Press " PP_COL_TMP("FF00FF--", "L") PP_WAVE " to start or reset the challenges!"

void challenge_update(void) {
    // ONE_TODO: Delete this
    // if (gChallengeLevel == 0xFF) {
    //     print_set_envcolour(0xFF, 0xFF, 0xFF, 0xFF);
    //     print_small_text(16, SCREEN_HEIGHT - 24, PRESS_L_TO_RESTART, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_DEFAULT);
    //     // print_small_text(16, SCREEN_HEIGHT - 64, ALL_LETTERS, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_DEFAULT);
    // }

#ifdef ENABLE_DEBUG_FREE_MOVE
    if (
        (gPlayer1Controller->buttonDown & (Z_TRIG | R_TRIG)) == (Z_TRIG | R_TRIG) &&
        (gPlayer1Controller->buttonPressed & (Z_TRIG | R_TRIG))
    ) {
        if (
            gChallengeStatus != CHALLENGE_STATUS_NOT_PLAYING &&
            sDelayedWarpOp == WARP_OP_NONE &&
            !gWarpTransition.isActive &&
            sCurrPlayMode == PLAY_MODE_NORMAL
        ) {
            gChallengeStatus = CHALLENGE_STATUS_WIN;
            level_trigger_warp(gMarioState, WARP_OP_DEBUG_CHALLENGE_SKIP); // warp to next challenge
        }
    }
#endif

    if (gChallengeStatus != CHALLENGE_STATUS_NOT_PLAYING) {
        if (gWaitingToStart) {
            set_time_stop_flags(TIME_STOP_ENABLED | TIME_STOP_ALL_OBJECTS);
            if (gPlayer1Controller->buttonPressed) {
                gWaitingToStart = FALSE;
                clear_time_stop_flags(TIME_STOP_ENABLED | TIME_STOP_ALL_OBJECTS);
                gPlayer1Controller->buttonPressed = 0;
            } else {
                gPlayer1Controller->buttonPressed = 0;
                set_motion_blur(150);
                set_fb_effect_col(gGlobalFog.r, gGlobalFog.g, gGlobalFog.b);
                set_fb_effect_type(FBE_EFFECT_MULT);
                print_set_envcolour(0xFF, 0xFF, 0xFF, 0xFF);
                print_small_text(SCREEN_WIDTH / 2, 24+36, "Press ONE button to start", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_DEFAULT);
                print_challenge_types();
                update_last_print_vars(sObtainedChallengeFlags, sFailureFlags);
                return;
            }
        }
    }

#ifdef USE_PROFILER
    if ((gPlayer1Controller->buttonPressed & L_TRIG) && !(gPlayer1Controller->buttonDown & U_JPAD)) {
#else
    if (gPlayer1Controller->buttonPressed & L_TRIG) {
#endif
        if (
            // ONE_TODO: future conditions
            gChallengeStatus != CHALLENGE_STATUS_NOT_PLAYING &&
            gChallengeStatus != CHALLENGE_STATUS_WIN &&
            !gWarpTransition.isActive &&
            sCurrPlayMode == PLAY_MODE_NORMAL
        ) {
            level_trigger_warp(gMarioState, WARP_OP_START_CHALLENGES); // reset level
        }
    }

    if (gChallengeStatus == CHALLENGE_STATUS_NOT_PLAYING) {
        update_last_print_vars(sObtainedChallengeFlags, sFailureFlags);
        return;
    }

    check_flag_conditions();

    while (internalFlagsForFrame) {
        add_challenge_flags_internal();
        process_kill_flags();
    }

    print_challenge_types();

    update_last_print_vars(sObtainedChallengeFlags, sFailureFlags);
}
