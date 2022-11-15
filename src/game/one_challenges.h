#ifndef ONE_CHALLENGES_H
#define ONE_CHALLENGES_H

#include "types.h"

enum OneChallengeStatus {
    CHALLENGE_STATUS_NOT_PLAYING,
    CHALLENGE_STATUS_PLAYING,
    CHALLENGE_STATUS_CAN_WIN,
    CHALLENGE_STATUS_WIN,
    CHALLENGE_STATUS_LOSE
};

enum OneChallengeEntries {
    CHALLENGE_NAME_JUMP,
    CHALLENGE_NAME_COIN,
    CHALLENGE_NAME_GROUND,
    CHALLENGE_NAME_GOOMBA,
    CHALLENGE_NAME_A_PRESS,
    CHALLENGE_NAME_B_PRESS,

    CHALLENGE_NAME_TOTAL,
};

enum OneChallengeFlags {
    CHALLENGE_FLAG_NONE    = 0,

    CHALLENGE_FLAG_JUMP    = (1U << CHALLENGE_NAME_JUMP),
    CHALLENGE_FLAG_COIN    = (1U << CHALLENGE_NAME_COIN),
    CHALLENGE_FLAG_GROUND  = (1U << CHALLENGE_NAME_GROUND),
    CHALLENGE_FLAG_GOOMBA  = (1U << CHALLENGE_NAME_GOOMBA),
    CHALLENGE_FLAG_A_PRESS = (1U << CHALLENGE_NAME_A_PRESS),
    CHALLENGE_FLAG_B_PRESS = (1U << CHALLENGE_NAME_B_PRESS),
};

struct OneChallengeLevel {
    u32 requiredFlags;
    u32 enforcedFlags;
};

extern u8 gChallengeLevel;
extern u32 gChallengeStatus;

u8 is_challenge_active(void);
u32 get_challenge_obtained_flags(void);
u32 get_challenge_enforced_flags(void);
u32 get_challenge_required_flags(void);
u32 get_challenge_failure_flags(void);

void reset_challenge(void);
void start_next_challenge_level(void);
void start_challenge(void);
void add_challenge_flags(u32 flags);

void challenge_update(void);

#endif // ONE_CHALLENGES_H
