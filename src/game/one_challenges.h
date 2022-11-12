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

enum OneChallengeFlags {
    CHALLENGE_FLAG_NONE = 0,

    CHALLENGE_FLAG_JUMP    = (1 << 0),
    CHALLENGE_FLAG_COIN    = (1 << 1),
    CHALLENGE_FLAG_GROUND  = (1 << 2),
    CHALLENGE_FLAG_GOOMBA  = (1 << 3),
    CHALLENGE_FLAG_A_PRESS = (1 << 4),
    CHALLENGE_FLAG_B_PRESS = (1 << 5),
};

extern u32 gChallengeStatus;

u32 get_challenge_obtained_flags(void);
u32 get_challenge_enforced_flags(void);
u32 get_challenge_required_flags(void);
u32 get_challenge_failure_flags(void);

void reset_challenge_flags(void);
void new_challenge_flags(u32 enforcedFlags, u32 requiredFlags);
void start_challenge(void);
u8 add_challenge_flags(u32 flags);

#endif // ONE_CHALLENGES_H
