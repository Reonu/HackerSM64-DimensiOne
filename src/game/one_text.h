#ifndef ONE_TEXT_H
#define ONE_TEXT_H

#include "types.h"
#include "one_challenges.h"

extern char *gChallengeHeaderText[sizeof(u32)*8];
extern char **gChallengeTypesArr[];

void print_challenge_types(void);

#endif // ONE_TEXT_H
