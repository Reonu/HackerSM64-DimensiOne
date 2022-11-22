#ifndef ONE_CHALLENGES_H
#define ONE_CHALLENGES_H

#include "types.h"

typedef u64 oneflags_t;

enum OneChallengeStatus {
    CHALLENGE_STATUS_NOT_PLAYING,
    CHALLENGE_STATUS_PLAYING,
    CHALLENGE_STATUS_CAN_WIN,
    CHALLENGE_STATUS_WIN,
    CHALLENGE_STATUS_LOSE
};

enum OneChallengeEntries {
    CHALLENGE_NAME_SMOOCH,
    CHALLENGE_NAME_JUMP,
    CHALLENGE_NAME_COIN,
    CHALLENGE_NAME_GROUND,
    CHALLENGE_NAME_A_PRESS,
    CHALLENGE_NAME_B_PRESS,
    CHALLENGE_NAME_WALLKICK,
    CHALLENGE_NAME_TRIPLE_JUMP,
    CHALLENGE_NAME_COLLECT_LIFE,
    CHALLENGE_NAME_SLEEPING_PIRANHA,
    CHALLENGE_NAME_KILL_GOOMBA,
    CHALLENGE_NAME_KILL_KOOPA,
    CHALLENGE_NAME_KILL_PENGUIN,
    CHALLENGE_NAME_KILL_BOMB,
    CHALLENGE_NAME_KILL_ALL_BOMBS,
    CHALLENGE_NAME_KILL_GOOMBA_WITH_BOMB,
    CHALLENGE_NAME_KILL_WHOMP_KING,
    CHALLENGE_NAME_KILL_MONEYBAG,
    CHALLENGE_NAME_INTERACTED_KOOPA,

    CHALLENGE_NAME_TIMER, // Must be last
    CHALLENGE_NAME_TOTAL,
};

STATIC_ASSERT(CHALLENGE_NAME_TOTAL <= sizeof(oneflags_t) * 8, "Too many challenges!");

enum OneChallengeFlags {
    CHALLENGE_FLAG_NONE                  = 0,

    CHALLENGE_FLAG_SMOOCH                = (1ULL << CHALLENGE_NAME_SMOOCH), // TODO: Everything lol
    CHALLENGE_FLAG_JUMP                  = (1ULL << CHALLENGE_NAME_JUMP),
    CHALLENGE_FLAG_COIN                  = (1ULL << CHALLENGE_NAME_COIN),
    CHALLENGE_FLAG_GROUND                = (1ULL << CHALLENGE_NAME_GROUND),
    CHALLENGE_FLAG_A_PRESS               = (1ULL << CHALLENGE_NAME_A_PRESS),
    CHALLENGE_FLAG_B_PRESS               = (1ULL << CHALLENGE_NAME_B_PRESS),
    CHALLENGE_FLAG_WALLKICK              = (1ULL << CHALLENGE_NAME_WALLKICK),
    CHALLENGE_FLAG_TRIPLE_JUMP           = (1ULL << CHALLENGE_NAME_TRIPLE_JUMP),
    CHALLENGE_FLAG_COLLECT_LIFE          = (1ULL << CHALLENGE_NAME_COLLECT_LIFE),
    CHALLENGE_FLAG_SLEEPING_PIRANHA      = (1ULL << CHALLENGE_NAME_SLEEPING_PIRANHA),
    CHALLENGE_FLAG_KILL_GOOMBA           = (1ULL << CHALLENGE_NAME_KILL_GOOMBA),
    CHALLENGE_FLAG_KILL_KOOPA            = (1ULL << CHALLENGE_NAME_KILL_KOOPA),
    CHALLENGE_FLAG_KILL_PENGUIN          = (1ULL << CHALLENGE_NAME_KILL_PENGUIN),
    CHALLENGE_FLAG_KILL_BOMB             = (1ULL << CHALLENGE_NAME_KILL_BOMB),
    CHALLENGE_FLAG_KILL_ALL_BOMBS        = (1ULL << CHALLENGE_NAME_KILL_ALL_BOMBS),
    CHALLENGE_FLAG_KILL_GOOMBA_WITH_BOMB = (1ULL << CHALLENGE_NAME_KILL_GOOMBA_WITH_BOMB),
    CHALLENGE_FLAG_KILL_WHOMP_KING       = (1ULL << CHALLENGE_NAME_KILL_WHOMP_KING),
    CHALLENGE_FLAG_KILL_MONEYBAG         = (1ULL << CHALLENGE_NAME_KILL_MONEYBAG),
    CHALLENGE_FLAG_INTERACTED_KOOPA      = (1ULL << CHALLENGE_NAME_INTERACTED_KOOPA),

    CHALLENGE_FLAG_TIMER                 = (1ULL << CHALLENGE_NAME_TIMER), // Must be last
};

struct OneChallengeLevel {
    oneflags_t requiredFlags;
    oneflags_t enforcedFlags;
};

extern u8 gChallengeLevel;
extern u16 gBombsSpawned;
extern u32 gChallengeStatus;
extern s32 gChallengeTimer;
extern s32 gMoneybagSwap;
extern s32 gMoneybagCount;
extern u8 gSetChallengeMusic;
extern u8 gWaitingToStart;

u8 is_challenge_active(void);
oneflags_t get_challenge_obtained_flags(void);
oneflags_t get_challenge_enforced_flags(void);
oneflags_t get_challenge_required_flags(void);
oneflags_t get_challenge_failure_flags(void);

void reset_challenge(void);
void start_next_challenge_level(void);
void start_challenge(void);
void add_challenge_flags(oneflags_t flags);
void add_challenge_kill_flags(oneflags_t flags);

void challenge_update(void);

#endif // ONE_CHALLENGES_H
