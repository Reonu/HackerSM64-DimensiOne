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
#include "levels/wf/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wf_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, wf_geo_0007E0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, wf_geo_000820), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, wf_geo_000860), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, wf_geo_000878), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, wf_geo_000890), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08, wf_geo_0008A8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_09, wf_geo_0008E8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A, wf_geo_000900), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C, wf_geo_000940), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_GIANT_POLE, wf_geo_000AE0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E, wf_geo_000958), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0F, wf_geo_0009A0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_PLATFORM, wf_geo_0009B8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_11, wf_geo_0009D0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_12, wf_geo_0009E8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_SMALL_BOMP, wf_geo_000A00), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_LARGE_BOMP, wf_geo_000A40), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_WOODEN_PLATFORM, wf_geo_000A58), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_SLIDING_PLATFORM, wf_geo_000A98), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE_PART, wf_geo_000AB0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE, wf_geo_000AC8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_TRAPEZOID_PLATORM, wf_geo_000AF8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM, wf_geo_000B10), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM_UNUSED, wf_geo_000B38), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM_ELEVATOR, wf_geo_000B60), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BREAKABLE_WALL_RIGHT, wf_geo_000B78), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BREAKABLE_WALL_LEFT, wf_geo_000B90), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_KICKABLE_BOARD, wf_geo_000BA8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_DOOR, wf_geo_000BE0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_KICKABLE_BOARD_FELLED, wf_geo_000BC8), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0E, LEVEL_BOB, 0x09, 0x0E, WARP_NO_CHECKPOINT),
		WARP_NODE(0x11, LEVEL_WF, 0x01, 0x11, WARP_NO_CHECKPOINT),
		WARP_NODE(0x12, LEVEL_WF, 0x02, 0x12, WARP_NO_CHECKPOINT),
		MOVING_PLATFORM_WITH_ACTS(moving_platform_geo_challenge_10_wf_geo, moving_platform_geo_challenge_10_wf_collision, 1263, 2, -15, 0, 0, 0, (SPLINE_OBJECT_BHV_AUTO << 24) | (SPLINE_OBJECT_MOVE_FORWARD << 16) | (0x14 << 8) | (0x11), bhvSplinePlatform, 31),
		MOVING_PLATFORM_WITH_ACTS(moving_platform_geo_challenge_10_wf_geo, moving_platform_geo_challenge_10_wf_collision, 1617, 2, -14, 0, 0, 0, (SPLINE_OBJECT_BHV_AUTO << 24) | (SPLINE_OBJECT_MOVE_FORWARD << 16) | (0x14 << 8) | (0x11), bhvSplinePlatform, 31),
		MOVING_PLATFORM_WITH_ACTS(moving_platform_geo_challenge_10_wf_geo, moving_platform_geo_challenge_10_wf_collision, 3714, 2, -14, 0, 0, 0, (SPLINE_OBJECT_BHV_AUTO << 24) | (SPLINE_OBJECT_MOVE_FORWARD << 16) | (0x14 << 8) | (0x11), bhvSplinePlatform, 31),
		OBJECT(MODEL_NONE, 3711, 372, -17, 0, 0, 0, (SPLINE_OBJECT_BHV_AUTO << 24) | (SPLINE_OBJECT_MOVE_FORWARD << 16) | (0x14 << 8) | (0x11), bhvSplineFollower),
		OBJECT(MODEL_STAR, 3711, 372, -17, 0, 0, 0, (0x11 << 24) | (0x14 << 8) | (0x11), bhvStar),
		OBJECT(MODEL_NONE, 19, 0, -23, 0, 0, 0, (0x11 << 16), bhvInstantActiveWarp),
		TERRAIN(wf_area_1_collision),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		AREA_SPLINE(wf_area_1_spline_ASplineChallenge11),
		AREA_SPLINE(wf_area_1_spline_ASplineChallenge11_001),
		AREA_SPLINE(wf_area_1_spline_ASplineChallenge11_002),
		AREA_SPLINE(wf_area_1_spline_ASplineChallenge11_003),
		/* Fast64 begin persistent block [area commands] */
		SET_ECHO(0x22, 0x22),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, wf_area_2),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0E, LEVEL_BOB, 0x09, 0x0E, WARP_NO_CHECKPOINT),
		WARP_NODE(0x11, LEVEL_WF, 0x01, 0x11, WARP_NO_CHECKPOINT),
		WARP_NODE(0x12, LEVEL_WF, 0x02, 0x12, WARP_NO_CHECKPOINT),
		WARP_NODE(0x13, LEVEL_BOB, 0x07, 0x13, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_PENGUIN, 294, -80, -655, 0, -25, 0, (0x12), bhvTuxiesMother),
		OBJECT(MODEL_PENGUIN, 318, 0, -2230, 0, 0, 0, (0x12), bhvTuxiesMother),
		OBJECT(MODEL_PENGUIN, 897, 351, -3813, 0, -90, 0, (0x12), bhvTuxiesMother),
		OBJECT(MODEL_PENGUIN, 651, 1302, -6015, 0, 0, 0, (0x12), bhvTuxiesMother),
		OBJECT(MODEL_PENGUIN, 1057, 1302, -3125, 0, -90, 0, (0x12), bhvTuxiesMother),
		OBJECT(MODEL_PENGUIN, -757, 1302, -2307, 0, 90, 0, (0x12), bhvTuxiesMother),
		OBJECT(MODEL_PENGUIN, 1052, 1302, -1574, 0, -90, 0, (0x12), bhvTuxiesMother),
		OBJECT(MODEL_PENGUIN, -779, 1302, -710, 0, 90, 0, (0x12), bhvTuxiesMother),
		OBJECT(MODEL_PENGUIN, 230, 1302, 534, 0, 180, 0, (0x12), bhvTuxiesMother),
		OBJECT(MODEL_KOOPA_SHELL, 181, 1302, -4934, 0, 0, 0, (0x12), bhvKoopaShell),
		OBJECT(MODEL_PENGUIN, -589, -80, -459, 0, 0, 0, (0x12), bhvSmallPenguin),
		OBJECT(MODEL_STAR, 145, 1684, 167, 0, 0, 0, (0x12 << 24) | (0x12), bhvStar),
		OBJECT(MODEL_NONE, -670, 0, -153, 0, 0, 0, (0x12 << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_SPRING, 61, -80, -2900, 0, 0, 0, (0x01 << 16) | (0x12), bhvSpring),
		OBJECT(MODEL_SPRING, 84, 351, -4685, 0, 0, 0, (0x01 << 16) | (0x12), bhvSpring),
		OBJECT(MODEL_SPRING, 131, 351, -5594, 0, 0, 0, (0x01 << 16) | (0x12), bhvSpring),
		TERRAIN(wf_area_2_collision),
		MACRO_OBJECTS(wf_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		SET_ECHO(0x22, 0x22),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
