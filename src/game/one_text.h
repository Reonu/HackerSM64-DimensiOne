#ifndef ONE_TEXT_H
#define ONE_TEXT_H

#include "types.h"
#include "one_challenges.h"

extern char *gChallengeHeaderText[sizeof(oneflags_t)*8];
extern char **gChallengeTypesArr[];

extern u32 gChallengesPrintTimer;

void print_challenge_types(void);
void clear_challenge_print_timers(void);
void update_last_print_vars(oneflags_t obtained, oneflags_t failure);

#endif // ONE_TEXT_H
