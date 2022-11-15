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
#include "levels/rr/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_rr_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _rr_segment_7SegmentRomStart, _rr_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group11_yay0SegmentRomStart, _group11_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group11_geoSegmentRomStart, _group11_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_12), 
	JUMP_LINK(script_func_global_1), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, rr_area_1),
		WARP_NODE(0x0A, LEVEL_RR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_RR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_RR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MOVING_PLATFORM_WITH_ACTS(platform1_rr_geo, platform1_rr_collision, 186, 770, 3138, 0, 0, 0, (SPLINE_OBJECT_BHV_AUTO << 24) | (SPLINE_OBJECT_MOVE_BACK_AND_FORTH << 16) | (10 << 8), bhvSplinePlatform, 31),
		MOVING_PLATFORM_WITH_ACTS(platform1_001_rr_geo, platform1_001_rr_collision, 186, 770, 3138, 0, 0, 0, (SPLINE_OBJECT_BHV_AUTO << 24) | (SPLINE_OBJECT_MOVE_BACK_AND_FORTH_REVERSED << 16) | (10 << 8), bhvSplinePlatform, 31),
		MOVING_PLATFORM_WITH_ACTS(platform2_rr_geo, platform2_rr_collision, 2296, 72, 182, 0, 0, 0, (SPLINE_OBJECT_BHV_AUTO << 24) | (SPLINE_OBJECT_MOVE_FORWARD << 16) | (10 << 8), bhvSplinePlatform, 31),
		MOVING_PLATFORM_WITH_ACTS(platform3_rr_mayro_geo, platform3_rr_mayro_collision, 2198, -52, 527, 0, 0, 0, (SPLINE_OBJECT_BHV_MARIO_ACTIVATES << 24) | (SPLINE_OBJECT_MOVE_FORWARD << 16) | (24 << 8), bhvSplinePlatform, 31),
		MOVING_PLATFORM_WITH_ACTS(platform_inverted_geo, platform_inverted_collision, -24, -84, -396, 0, 0, 0, (SPLINE_OBJECT_BHV_AUTO << 24) | (SPLINE_OBJECT_MOVE_FORWARD << 16) | (10 << 8), bhvSplinePlatform, 31),
		MARIO_POS(0x01, 0, 0, 100, 0),
		OBJECT(MODEL_NONE, 0, 100, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(rr_area_1_collision),
		ROOMS(rr_area_1_collision_rooms),
		MACRO_OBJECTS(rr_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		AREA_SPLINE(rr_area_1_spline_NurbsCurve),
		AREA_SPLINE(rr_area_1_spline_NurbsCurve_001),
		AREA_SPLINE(rr_area_1_spline_NurbsCurve_002),
		AREA_SPLINE(rr_area_1_spline_NurbsCurve_003),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 100, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
