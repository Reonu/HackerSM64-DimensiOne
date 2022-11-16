#pragma once

void render_fb_effects(void);
void run_motion_blur(s32 goalAmount);

enum FBETypes {
    FBE_EFFECT_BRIGHTEN = (1 << 0),
    FBE_EFFECT_MULT = (1 << 1),
};
