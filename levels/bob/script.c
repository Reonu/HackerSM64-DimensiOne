#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x01, LEVEL_BOB, 0x01, 0x01, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x02, 0x02, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x01, WARP_NO_CHECKPOINT),
		WARP_NODE(0x02, LEVEL_BOB, 0x02, 0x02, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 250, -3445, 150, 0, -90, 0, (0x01), bhvCoinFormation),
		MARIO_POS(0x01, 90, -309, -3445, 195),
		OBJECT(MODEL_STAR, 702, -3134, 165, 0, -90, 0, (0x01 << 24) | (0x01), bhvStar),
		OBJECT(MODEL_NONE, -314, -3445, 197, 0, 90, 0, (0x01 << 16) | (0x01), bhvInstantActiveWarp),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bob_area_2),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x02, LEVEL_BOB, 0x02, 0x02, WARP_NO_CHECKPOINT),
		WARP_NODE(0x03, LEVEL_BOB, 0x03, 0x03, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_YELLOW_COIN, -262, 100, 5514, 0, -180, 0, (0x02), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 213, 100, 4660, 0, -180, 0, (0x02), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -245, 100, 3917, 0, -180, 0, (0x02), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1748, 100, 3347, 0, -180, 0, (0x02), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -2373, 100, 3979, 0, -180, 0, (0x02), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -2198, 100, 4672, 0, -180, 0, (0x02), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -367, 100, 2456, 0, -180, 0, (0x02), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -162, 100, 2466, 0, -180, 0, (0x02), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 750, 649, 2357, 0, -180, 0, (0x02), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 750, 649, 2079, 0, -180, 0, (0x02), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 750, 649, 1823, 0, -180, 0, (0x02), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 750, 649, 1633, 0, -180, 0, (0x02), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 750, 649, 1401, 0, -180, 0, (0x02), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1738, 377, 2492, 0, -180, 0, (0x02), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1742, 377, 2076, 0, -180, 0, (0x02), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -869, 655, 2078, 0, -180, 0, (0x02), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -2172, 100, 5461, 0, -180, 0, (0x02), bhvYellowCoin),
		OBJECT(MODEL_STAR, -176, 1665, 2023, 0, 0, 0, (0x02 << 24) | (0x02), bhvStar),
		OBJECT(MODEL_NONE, -804, 200, 7687, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -801, 100, 7693, 0, 0, 0, (0x02 << 16), bhvInstantActiveWarp),
		TERRAIN(bob_area_2_collision),
		MACRO_OBJECTS(bob_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, bob_area_3),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x03, LEVEL_BOB, 0x03, 0x03, WARP_NO_CHECKPOINT),
		WARP_NODE(0x04, LEVEL_BOB, 0x04, 0x04, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GOOMBA, 46, -142, -1135, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 162, -142, -804, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -384, -142, -810, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 275, -142, -1063, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 468, -142, -837, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 557, -142, -1043, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -180, -142, -1090, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -55, -142, -878, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 36, -142, -758, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 345, -142, -1132, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -477, -142, -873, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -357, -142, -1227, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 432, -142, -1270, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 549, -142, -1230, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -92, -142, -1402, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 110, -142, -1422, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_STAR, 2, -13, -1807, 0, 0, 0, (0x03 << 24) | (0x03), bhvStar),
		OBJECT(MODEL_NONE, -16, -42, 17, 0, 0, 0, (0x03 << 16), bhvInstantActiveWarp),
		TERRAIN(bob_area_3_collision),
		MACRO_OBJECTS(bob_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, bob_area_4),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x04, LEVEL_BOB, 0x04, 0x04, WARP_NO_CHECKPOINT),
		WARP_NODE(0x05, LEVEL_BOB, 0x05, 0x05, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GOOMBA, 826, 886, 9811, 0, 0, 0, (0x04), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 678, 886, 8105, 0, 0, 0, (0x04), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 340, 886, 5889, 0, 0, 0, (0x04), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 243, 886, 3905, 0, 0, 0, (0x04), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 653, 886, 2497, 0, 0, 0, (0x04), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 1604, 886, 382, 0, 0, 0, (0x04), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 1271, 886, -2946, 0, 0, 0, (0x04), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 743, 886, -4297, 0, 0, 0, (0x04), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 452, 886, -6683, 0, 0, 0, (0x04), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 895, 886, -8009, 0, 0, 0, (0x04), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 1750, 886, -8658, 0, 0, 0, (0x04), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 3073, 886, -8847, 0, 0, 0, (0x04), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 3365, 886, -6332, 0, 0, 0, (0x04), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 4345, 886, -2483, 0, 0, 0, (0x04), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 3987, 886, -4410, 0, 0, 0, (0x04), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 4580, 886, -330, 0, 0, 0, (0x04), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 6003, 886, 17, 0, 0, 0, (0x04), bhvGoomba),
		OBJECT(MODEL_KOOPA_SHELL, 881, 886, 10749, 0, 0, 0, (0x04), bhvKoopaShell),
		OBJECT(MODEL_STAR, 6519, 1128, 8, 0, 0, 0, (0x04 << 24) | (0x04), bhvStar),
		OBJECT(MODEL_NONE, 903, 886, 11402, 0, 0, 0, (0x04 << 16) | (0x04), bhvInstantActiveWarp),
		TERRAIN(bob_area_4_collision),
		MACRO_OBJECTS(bob_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(5, bob_area_5),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x05, LEVEL_BOB, 0x05, 0x05, WARP_NO_CHECKPOINT),
		WARP_NODE(0x06, LEVEL_BOB, 0x05, 0x06, WARP_NO_CHECKPOINT),
		WARP_NODE(0x07, LEVEL_BOB, 0x06, 0x07, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLACK_BOBOMB, -1235, -368, -182, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -1140, -368, 151, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -1459, -368, 167, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -731, -368, 884, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -401, -368, 879, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -591, -368, 1113, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 276, -368, 783, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 295, -368, 1044, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 548, -368, 862, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 427, -368, -152, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 442, -368, -369, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 659, -368, -227, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 345, -368, -1097, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 174, -368, -1001, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 171, -368, -1253, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -397, -368, -1306, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -285, -368, -1388, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -265, -368, -1116, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_STAR, 8, 113, -23, 0, 0, 0, (0x05 << 24) | (0x05), bhvStar),
		OBJECT(MODEL_BLACK_BOBOMB, -1235, -368, -182, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -1140, -368, 151, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -1459, -368, 167, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -731, -368, 884, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -401, -368, 879, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -591, -368, 1113, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 276, -368, 783, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 295, -368, 1044, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 548, -368, 862, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 427, -368, -152, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 442, -368, -369, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 659, -368, -227, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 345, -368, -1097, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 174, -368, -1001, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 171, -368, -1253, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -397, -368, -1306, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -285, -368, -1388, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -265, -368, -1116, 0, 0, 0, (0x06), bhvBobomb),
		OBJECT(MODEL_NONE, -222, -368, -176, 0, 0, 0, (0x05 << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -222, -368, -176, 0, 0, 0, (0x06 << 16), bhvInstantActiveWarp),
		TERRAIN(bob_area_5_collision),
		MACRO_OBJECTS(bob_area_5_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(6, bob_area_6),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x07, LEVEL_BOB, 0x06, 0x07, WARP_NO_CHECKPOINT),
		MOVING_PLATFORM_WITH_ACTS(moving_platform_geo_geo, moving_platform_geo_collision, 0, 0, 0, 0, 0, 0, (SPLINE_OBJECT_BHV_AUTO << 24) | (SPLINE_OBJECT_MOVE_FORWARD << 16), bhvSplinePlatform, 31),
		OBJECT(MODEL_NONE, 0, -106, 0, 0, 0, 0, (0x07 << 16), bhvInstantActiveWarp),
		TERRAIN(bob_area_6_collision),
		MACRO_OBJECTS(bob_area_6_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		AREA_SPLINE(bob_area_6_spline_NurbsCurve),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 90, -309, -3445, 195),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
