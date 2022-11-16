#ifndef ONE_TEXT_H
#define ONE_TEXT_H

#include "types.h"
#include "one_challenges.h"

extern char *gChallengeHeaderText[sizeof(u32)*8];
extern char **gChallengeTypesArr[];

void print_challenge_types(void);
void clear_challenge_print_timers(void);
void update_last_print_vars(u32 obtained, u32 failure);

#endif // ONE_TEXT_H
