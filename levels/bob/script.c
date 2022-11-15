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
		OBJECT(MODEL_STAR, 702, -3134, 165, 0, -90, 0, (0x01 << 16) | (0x01), bhvStar),
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
		OBJECT(MODEL_STAR, -176, 1665, 2023, 0, 0, 0, (0x02 << 16) | (0x02), bhvStar),
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
		WARP_NODE(0x02, LEVEL_BOB, 0x02, 0x02, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GOOMBA, 46, -142, -1135, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -177, -142, -796, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 162, -142, -804, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 20, -142, -953, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -296, -142, -1006, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -384, -142, -810, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -121, -142, -1045, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 15, -142, -831, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 275, -142, -1063, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 158, -142, -1001, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 321, -142, -864, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 439, -142, -1027, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 468, -142, -837, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 557, -142, -1043, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -411, -142, -1040, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -180, -142, -1090, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -55, -142, -878, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 36, -142, -758, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 345, -142, -1132, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -477, -142, -873, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -357, -142, -1227, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -121, -142, -1238, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -80, -142, -1172, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 127, -142, -1270, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 185, -142, -1174, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 432, -142, -1270, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 312, -142, -1304, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 549, -142, -1230, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -329, -142, -1385, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -92, -142, -1402, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 110, -142, -1422, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 362, -142, -1445, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 556, -142, -1412, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_STAR, 64, -13, -1807, 0, 0, 0, (0x03 << 16) | (0x03), bhvStar),
		TERRAIN(bob_area_3_collision),
		MACRO_OBJECTS(bob_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
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
