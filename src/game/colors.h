#pragma once

#include "types.h"

/**
 * NOTE: THIS FILE SHOULD NOT BE CHANGED
 * gen/colors.inc.c and gen/colors.inc.h is created into the build directory after compilation.
 * If you need to adjust or add files, edit colors.csv instead.
 * There is a vscode extension for editing csvs that can help!
 */

struct DimensiOneColor
{
    char *hex;
    const struct {
        u8 r;
        u8 g;
        u8 b;
    } rgb;
    const struct {
        f32 h;
        f32 s;
        f32 l;
    } hsl;
};

#include "gen/colors.inc.h"

extern struct DimensiOneColor gD1Colors[];
