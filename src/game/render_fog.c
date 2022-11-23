#include <PR/ultratypes.h>
#include "sm64.h"

#include "area.h"
#include "rendering_graph_node.h"
#include "engine/math_util.h"
#include "object_list_processor.h"
#include "level_update.h"
#include "game_init.h"
#include "camera.h"
#include "render_fog.h"
#include "one_challenges.h"
#include "math.h"

struct GlobalFog sWaterFog = {
    .r    = 0x10,
    .g    = 0x2B,
    .b    = 0x29,
    .a    = 0xFF,
    .low  = 920,
    .high = 1000
};

struct GlobalFog sOverrideFog = {
    .r    = 0xB3,
    .g    = 0xBC,
    .b    = 0xDD,
    .a    = 0xFF,
    .low  = 950,
    .high = 1005
};

struct GlobalFog sSomethingFogArea1 = {
    .r    = 141,
    .g    = 255,
    .b    = 239,
    .a    = 0xFF,
    .low  = 962,
    .high = 980
};
	// gsDPSetFogColor(141, 255, 239, 255),
	// gsSPFogPosition(962, 980),

extern struct GlobalFog gGlobalFog;

s32 sOverride = FALSE;

void rgb2hsl(u8 rU, u8 gU, u8 bU, Vec3f hsl) {
    f32 r = (f32)rU / 255.0f;
    f32 g = (f32)gU / 255.0f;
    f32 b = (f32)bU / 255.0f;
    
    f32 max = MAX(MAX(r,g),b);
    f32 min = MIN(MIN(r,g),b);
    
    hsl[0] = hsl[1] = hsl[2] = (max + min) / 2;

    if (max == min) {
        hsl[0] = hsl[1] = 0; // achromatic
    } else {
        f32 d = max - min;
        hsl[1] = (hsl[2] > 0.5f) ? d / (2 - max - min) : d / (max + min);
        
        if (max == r) {
            hsl[0] = (g - b) / d + (g < b ? 6 : 0);
        } else if (max == g) {
            hsl[0] = (b - r) / d + 2;
        } else if (max == b) {
            hsl[0] = (r - g) / d + 4;
        }
        
        hsl[0] /= 6;

        if (hsl[0] < 0.0f) hsl[0]++;
        if (hsl[0] > 1.0f) hsl[0]--;
    }
}

// stolen from stackoverflow and arthur
f32 hue_to_rgb(f32 p, f32 q, f32 t) {
    if (t < 0.f)
        t += 1.f;
    if (t > 1.f)
        t -= 1.f;

    if (t < 1/6.f)
        return p + (q - p) * 6 * t;
    if (t < 1/2.f)
        return q;
    if (t < 2/3.f)
        return p + (q - p) * (2/3.f - t) * 6;
    return p;
}

void hsl_to_rgb(f32 hf, f32 sf, f32 lf, struct GlobalFog *fog) {
    f32 r,g,b;
    // f32 hf = h / 255.0f;
    // f32 sf = s / 255.0f;
    // f32 lf = l / 255.0f;

    if (sf == 0.f) {
        r = g = b = lf;
    } else {
        f32 q = (lf < 1/2.f) ? (lf * (1 + sf)) : (lf + sf - lf * sf);
        f32 p = 2 * lf - q;
        r = hue_to_rgb(p, q, hf + 1/3.f);
        g = hue_to_rgb(p, q, hf);
        b = hue_to_rgb(p, q, hf - 1/3.f);
    }

    fog->r = roundf(CLAMP(r * 255, 0, 255));
    fog->g = roundf(CLAMP(g * 255, 0, 255));
    fog->b = roundf(CLAMP(b * 255, 0, 255));
}

void update_global_fog_override(
    u8 r,
    u8 g,
    u8 b,
    u8 a,
    s16 low,
    s16 high
) {
    sOverrideFog.r = r;
    sOverrideFog.g = g;
    sOverrideFog.b = b;
    sOverrideFog.a = a;
    sOverrideFog.low = low;
    sOverrideFog.high = high;
    sOverride = TRUE;
}

void disable_fog_override(void) {
    sOverride = FALSE;
}

#define GLOBAL_FOG_UPDATE_RATE_DIVISOR 10

// Vec3f hsl = { 0.5f, .45f, .75f };

void update_global_fog(void) {
    Vec3f hsl = { 0.4765f, 1.0f, .77f };
    struct GlobalFog *goalFog;
    // struct GlobalFog newFog;

    if (gCameraIsUnderwater) {
        goalFog = &sWaterFog;
    }
    else if (sOverride) {
        goalFog = &sOverrideFog;
    }
    else {
        switch (gCurrAreaIndex)
        {
        case 1:
        default:
            goalFog = &sSomethingFogArea1;

            // kinda confusing how it only happens after getting a star?
            // if (gChallengeStatus == CHALLENGE_STATUS_WIN) {
            //     hsl[2] = 0.9f;
            //     goalFog->low = 962;
            //     goalFog->high = 980;
            // } else
            if (gChallengeStatus == CHALLENGE_STATUS_LOSE || gMarioState->health <= 0xFF) {
                hsl[0] = 0;

                f32 hV = sins((gGlobalTimer * DEGREES(12.0f)));
                hV = cube(hV) * 0.08f;
                hsl[2] = 0.3f + hV;
                goalFog->low = 940;
                goalFog->high = 970;
            } else {
                f32 hV = sins(gGlobalTimer * DEGREES(2)) * 0.05f;
                hsl[0] = hsl[0] + ((f32)gChallengeLevel)*1.73f;
                hsl[0] = hsl[0] + hV;
                hsl[0] = hsl[0] - floorf(hsl[0]);
                goalFog->low = 962;
                goalFog->high = 980;
            }

            hsl_to_rgb(hsl[0], hsl[1], hsl[2], goalFog);
            break;
        }
    }

    // rgb2hsl(goalFog->r, goalFog->g, goalFog->b, hsl);


    gGlobalFog.r    = approach_s16_asymptotic(gGlobalFog.r,    goalFog->r,    GLOBAL_FOG_UPDATE_RATE_DIVISOR);
    gGlobalFog.g    = approach_s16_asymptotic(gGlobalFog.g,    goalFog->g,    GLOBAL_FOG_UPDATE_RATE_DIVISOR);
    gGlobalFog.b    = approach_s16_asymptotic(gGlobalFog.b,    goalFog->b,    GLOBAL_FOG_UPDATE_RATE_DIVISOR);
    gGlobalFog.a    = approach_s16_asymptotic(gGlobalFog.a,    goalFog->a,    GLOBAL_FOG_UPDATE_RATE_DIVISOR);
    gGlobalFog.low  = approach_s16_asymptotic(gGlobalFog.low,  goalFog->low,  GLOBAL_FOG_UPDATE_RATE_DIVISOR);
    gGlobalFog.high = approach_s16_asymptotic(gGlobalFog.high, goalFog->high, GLOBAL_FOG_UPDATE_RATE_DIVISOR);
    if (gGlobalFog.high < gGlobalFog.low + 5) gGlobalFog.high = gGlobalFog.low + 5;
}
