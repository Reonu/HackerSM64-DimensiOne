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
		OBJECT(MODEL_NONE, 372, -3445, 150, 0, -90, 0, (0x01), bhvCoinFormation),
		MARIO_POS(0x01, 90, -309, -3445, 195),
		OBJECT(MODEL_STAR, 1320, -3134, 165, 0, -90, 0, (0x01 << 24) | (0x01), bhvStar),
		OBJECT(MODEL_NONE, -314, -3445, 197, 0, 90, 0, (0x01 << 16), bhvInstantActiveWarp),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		SET_ECHO(0xF8, 0xF8),
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
		SET_ECHO(0xF8, 0xF8),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, bob_area_3),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x03, LEVEL_BOB, 0x03, 0x03, WARP_NO_CHECKPOINT),
		WARP_NODE(0x04, LEVEL_BOB, 0x04, 0x04, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GOOMBA, 162, -183, -804, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -384, -183, -810, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 275, -183, -1063, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 468, -183, -837, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 557, -183, -1043, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -180, -183, -1090, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -55, -183, -878, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 36, -183, -758, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 345, -183, -1132, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -477, -183, -873, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -357, -183, -1227, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 432, -183, -1270, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 549, -183, -1230, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -92, -183, -1402, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 110, -183, -1422, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 46, -183, -1135, 0, 0, 0, (0x03), bhvGoomba),
		OBJECT(MODEL_STAR, 2, -13, -1807, 0, 0, 0, (0x03 << 24) | (0x03), bhvStar),
		OBJECT(MODEL_NONE, -16, -42, 17, 0, 0, 0, (0x03 << 16), bhvInstantActiveWarp),
		TERRAIN(bob_area_3_collision),
		MACRO_OBJECTS(bob_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		SET_ECHO(0xF8, 0xF8),
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
		OBJECT(MODEL_WOODEN_SIGNPOST, 647, 886, 10735, 0, 0, 0, (0x04), bhvMessagePanel),
		OBJECT(MODEL_KOOPA_SHELL, 899, 886, 10911, 0, 0, 0, (0x04), bhvKoopaShell),
		OBJECT(MODEL_STAR, 6519, 1128, 8, 0, 0, 0, (0x04 << 24) | (0x04), bhvStar),
		OBJECT(MODEL_NONE, 903, 886, 11402, 0, 0, 0, (0x04 << 16) | (0x04), bhvInstantActiveWarp),
		TERRAIN(bob_area_4_collision),
		MACRO_OBJECTS(bob_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		SET_ECHO(0x22, 0x22),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(5, bob_area_5),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x05, LEVEL_BOB, 0x05, 0x05, WARP_NO_CHECKPOINT),
		WARP_NODE(0x06, LEVEL_BOB, 0x05, 0x06, WARP_NO_CHECKPOINT),
		WARP_NODE(0x07, LEVEL_BOB, 0x06, 0x07, WARP_NO_CHECKPOINT),
		WARP_NODE(0x08, LEVEL_BOB, 0x05, 0x08, WARP_NO_CHECKPOINT),
		WARP_NODE(0x09, LEVEL_BOB, 0x05, 0x09, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0F, LEVEL_BOB, 0x05, 0x0F, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0A, LEVEL_BOB, 0x06, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x10, LEVEL_BOB, 0x05, 0x10, WARP_NO_CHECKPOINT),
		WARP_NODE(0x11, LEVEL_WF, 0x01, 0x11, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLACK_BOBOMB, 852, -368, -815, 0, 0, 0, (0x0F), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -396, -368, -366, 0, 0, 0, (0x0F), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 1646, -368, 660, 0, 0, 0, (0x0F), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -355, -368, 674, 0, 0, 0, (0x0F), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 1666, -368, -1026, 0, 0, 0, (0x0F), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -810, -368, -1158, 0, 0, 0, (0x0F), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 688, -368, 1266, 0, 0, 0, (0x0F), bhvBobomb),
		OBJECT(MODEL_BULLET_BILL, -1789, -244, -2, 0, 90, 0, (0x0F), bhvBulletBill),
		MOVING_PLATFORM_WITH_ACTS(BulletBillCannon_geo, BulletBillCannon_collision, -1914, -244, -2, 0, 0, 0, (0x0F), bhvStaticObjectCustom, 31),
		MOVING_PLATFORM_WITH_ACTS(BulletBillCannon_geo, BulletBillCannon_collision, 1894, -244, -2, 0, -32768, 0, (0x0F), bhvStaticObjectCustom, 31),
		MOVING_PLATFORM_WITH_ACTS(BulletBillCannon_geo, BulletBillCannon_collision, 30, -244, -2014, 0, -16384, 0, (0x0F), bhvStaticObjectCustom, 31),
		MOVING_PLATFORM_WITH_ACTS(BulletBillCannon_geo, BulletBillCannon_collision, 30, -244, 2068, 0, 16384, 0, (0x0F), bhvStaticObjectCustom, 31),
		OBJECT(MODEL_BULLET_BILL, 1769, -244, -2, 0, -90, 0, (0x0F), bhvBulletBill),
		OBJECT(MODEL_BULLET_BILL, 30, -244, -1889, 0, 0, 0, (0x0F), bhvBulletBill),
		OBJECT(MODEL_BULLET_BILL, 30, -244, 1943, 0, -180, 0, (0x0F), bhvBulletBill),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -1198, -368, 502, 0, 0, 0, (0x0F), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -1150, -368, -414, 0, 0, 0, (0x0F), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -435, -368, 1081, 0, 0, 0, (0x0F), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 630, -368, 737, 0, 0, 0, (0x0F), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 956, -368, -154, 0, 0, 0, (0x0F), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -84, -368, -905, 0, 0, 0, (0x0F), bhvKoopa),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, (0x0F << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_STAR, 0, 0, 0, 0, 0, 0, (0x0F << 24) | (0x0F), bhvStar),
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
		OBJECT(MODEL_BLACK_BOBOMB, -1235, -368, -182, 0, 0, 0, (0x05), bhvBobomb),
		OBJECT(MODEL_STAR, 8, 113, -23, 0, 0, 0, (0x05 << 24) | (0x05), bhvStar),
		OBJECT(MODEL_NONE, -222, -368, -176, 0, 0, 0, (0x05 << 16), bhvInstantActiveWarp),
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
		OBJECT(MODEL_STAR, -16, -86, -5, 0, 0, 0, (0x06 << 24) | (0x06), bhvStar),
		OBJECT(MODEL_NONE, -222, -368, -176, 0, 0, 0, (0x06 << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_BLACK_BOBOMB, -421, -368, -351, 0, -133, 0, (0x08), bhvBobomb),
		OBJECT(MODEL_GOOMBA, -65, -368, -1580, 0, 0, 0, (0x08), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -110, -368, -1527, 0, 0, 0, (0x08), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -245, -368, -1394, 0, 0, 0, (0x08), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -317, -368, -1510, 0, 0, 0, (0x08), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -181, -368, -1466, 0, 0, 0, (0x08), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -374, -368, -1396, 0, 0, 0, (0x08), bhvGoomba),
		OBJECT(MODEL_GOOMBA, -428, -368, -1584, 0, 0, 0, (0x08), bhvGoomba),
		OBJECT(MODEL_STAR, -2, 1, -2, 0, 0, 0, (0x08 << 24) | (0x08), bhvStar),
		OBJECT(MODEL_NONE, 14, 5, -2, 0, 0, 0, (0x08 << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -313, -368, -1231, 0, 0, 0, (0x00 << 16) | (0x09), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -20, -368, -1272, 0, 0, 0, (0x00 << 16) | (0x09), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -147, -368, -928, 0, 0, 0, (0x00 << 16) | (0x09), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -1103, -368, -124, 0, 0, 0, (0x00 << 16) | (0x09), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -1336, -368, -392, 0, 0, 0, (0x00 << 16) | (0x09), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -1382, -368, 131, 0, 0, 0, (0x00 << 16) | (0x09), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -175, -368, 987, 0, 0, 0, (0x00 << 16) | (0x09), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -493, -368, 1274, 0, 0, 0, (0x00 << 16) | (0x09), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 145, -368, 1184, 0, 0, 0, (0x00 << 16) | (0x09), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 568, -368, 20, 0, 0, 0, (0x00 << 16) | (0x09), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 849, -368, -389, 0, 0, 0, (0x00 << 16) | (0x09), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 917, -368, 276, 0, 0, 0, (0x00 << 16) | (0x09), bhvKoopa),
		OBJECT(MODEL_STAR, -9, -4, 1, 0, 0, 0, (0x09 << 24) | (0x09), bhvStar),
		OBJECT(MODEL_NONE, -223, -368, -184, 0, 0, 0, (0x09 << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_YELLOW_COIN, -622, -368, 722, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, -57, -368, 836, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, 274, -368, 165, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, 227, -368, -445, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, 675, -368, 611, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, -1143, -368, 37, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, -843, -368, -667, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, -229, -368, -902, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, -623, -368, -399, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, 926, -368, -449, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, 1259, -368, 884, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, -1185, -368, 677, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, 559, -368, -960, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, 1204, -368, 142, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, 1167, -368, -1096, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, -1448, -368, -1035, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, -1738, -368, 495, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, -447, -368, 1397, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, 788, -368, 1354, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, 340, -368, 830, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, -271, -368, 241, 0, 0, 0, (0x10), bhvMoneybagHidden),
		OBJECT(MODEL_YELLOW_COIN, 88, -347, 1215, 0, 0, 0, (0x10), bhvMoneybag),
		OBJECT(MODEL_STAR, 8, 113, -23, 0, 0, 0, (0x10 << 24) | (0x10), bhvStar),
		OBJECT(MODEL_NONE, -223, -368, -184, 0, 0, 0, (0x10 << 16), bhvInstantActiveWarp),
		TERRAIN(bob_area_5_collision),
		MACRO_OBJECTS(bob_area_5_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		SET_ECHO(0x22, 0x22),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, 0, bhvClockSpawner),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(6, bob_area_6),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x07, LEVEL_BOB, 0x06, 0x07, WARP_NO_CHECKPOINT),
		WARP_NODE(0x08, LEVEL_BOB, 0x05, 0x08, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0A, LEVEL_BOB, 0x06, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x06, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BOB, 0x07, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0E, LEVEL_BOB, 0x06, 0x0E, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0F, LEVEL_BOB, 0x05, 0x0F, WARP_NO_CHECKPOINT),
		WARP_NODE(0x11, LEVEL_BOB, 0x06, 0x11, WARP_NO_CHECKPOINT),
		MOVING_PLATFORM_WITH_ACTS(moving_platform_geo_geo, moving_platform_geo_collision, -1012, 234, -245, 0, 0, 0, (SPLINE_OBJECT_BHV_AUTO << 24) | (SPLINE_OBJECT_MOVE_FORWARD << 16) | (0x14 << 8) | (0x07), bhvSplinePlatform, 31),
		OBJECT(MODEL_STAR, -63, 379, -270, 0, 0, 0, (0x07 << 24) | (0x07), bhvStar),
		OBJECT(MODEL_NONE, -63, 30, -270, 0, 0, 0, (0x07 << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_YELLOW_COIN, 753, 508, 4175, 0, 0, 0, (0x0A), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 753, 508, 4382, 0, 0, 0, (0x0A), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 753, 673, 4273, 0, 0, 0, (0x0A), bhvYellowCoin),
		MOVING_PLATFORM_WITH_ACTS(moving_platform_geo_challenge_10_larger_geo, moving_platform_geo_challenge_10_larger_collision, 746, 79, 3925, 0, 0, 0, (SPLINE_OBJECT_BHV_AUTO << 24) | (SPLINE_OBJECT_MOVE_BACK_AND_FORTH << 16) | (0x14 << 8) | (0x0A), bhvSplinePlatform, 31),
		OBJECT(MODEL_STAR, 753, 79, 4766, 0, 0, 0, (0x0A << 24) | (0x0A), bhvStar),
		OBJECT(MODEL_NONE, 726, 30, 1659, 0, 0, 0, (0x0A << 16), bhvInstantActiveWarp),
		MOVING_PLATFORM_WITH_ACTS(moving_platform_geo_challenge_10_geo, moving_platform_geo_challenge_10_collision, 764, 234, -2303, 0, 0, 0, (SPLINE_OBJECT_BHV_MARIO_ACTIVATES << 24) | (SPLINE_OBJECT_MOVE_FORWARD << 16) | (0x40 << 8) | (0x0B), bhvSplinePlatform, 31),
		OBJECT(MODEL_STAR, 731, 350, -5735, 0, 0, 0, (0x0B << 24) | (0x0B), bhvStar),
		OBJECT(MODEL_NONE, 593, 30, -1219, 0, 0, 0, (0x0B << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_MARIOS_WING_CAP, 613, 30, -1563, 0, 0, 0, (0x0B), bhvWingCap),
		MOVING_PLATFORM_WITH_ACTS(moving_platform_geo_challenge_10_geo, moving_platform_geo_challenge_10_collision, 2349, 66, -751, 0, 0, 0, (SPLINE_OBJECT_BHV_AUTO << 24) | (SPLINE_OBJECT_MOVE_FORWARD << 16) | (0x0A << 8) | (0x0E), bhvSplinePlatform, 31),
		MOVING_PLATFORM_WITH_ACTS(moving_platform_geo_challenge_10_geo, moving_platform_geo_challenge_10_collision, 3703, 66, 515, 0, 0, 0, (SPLINE_OBJECT_BHV_AUTO << 24) | (SPLINE_OBJECT_MOVE_BACKWARDS << 16) | (0x0A << 8) | (0x0E), bhvSplinePlatform, 31),
		MOVING_PLATFORM_WITH_ACTS(moving_platform_geo_challenge_10_geo, moving_platform_geo_challenge_10_collision, 5168, 66, -751, 0, 0, 0, (SPLINE_OBJECT_BHV_AUTO << 24) | (SPLINE_OBJECT_MOVE_FORWARD << 16) | (0x0A << 8) | (0x0E), bhvSplinePlatform, 31),
		OBJECT(MODEL_PIRANHA_PLANT, 3703, 198, 515, 0, 0, 0, (0x0E << 24) | (0x0E), bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, 2349, 198, -751, 0, 0, 0, (0x0E << 24) | (0x0E), bhvPiranhaPlant),
		OBJECT(MODEL_STAR, 6533, 42, -186, 0, 0, 0, (0x0E << 24) | (0x0E), bhvStar),
		OBJECT(MODEL_PIRANHA_PLANT, 5168, 198, -751, 0, 0, 0, (0x0E << 24) | (0x0E), bhvPiranhaPlant),
		OBJECT(MODEL_NONE, 1396, 30, -83, 0, 0, 0, (0x0E << 16), bhvInstantActiveWarp),
		TERRAIN(bob_area_6_collision),
		MACRO_OBJECTS(bob_area_6_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		AREA_SPLINE(bob_area_6_spline_ASplineChallenge07),
		AREA_SPLINE(bob_area_6_spline_ASplineChallenge0A_001),
		AREA_SPLINE(bob_area_6_spline_ASplineChallenge0A_002),
		AREA_SPLINE(bob_area_6_spline_ASplineChallenge0A_003),
		AREA_SPLINE(bob_area_6_spline_ASplineChallenge0B),
		AREA_SPLINE(bob_area_6_spline_ASplineChallenge0A),
		/* Fast64 begin persistent block [area commands] */
		SET_ECHO(0x22, 0x22),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(7, bob_area_7),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BOB, 0x07, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_BOB, 0x08, 0x0D, WARP_NO_CHECKPOINT),
		WARP_NODE(0x13, LEVEL_BOB, 0x07, 0x13, WARP_NO_CHECKPOINT),
		WARP_NODE(0x14, LEVEL_BOB, 0x09, 0x14, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_1UP, 3072, 311, 4090, 0, 0, 0, (0x13), bhvHidden1upInPole),
		OBJECT(MODEL_1UP, 2016, 311, 4098, 0, 0, 0, (0x13), bhvHidden1upInPole),
		OBJECT(MODEL_1UP, 2562, 311, 3634, 0, 0, 0, (0x13), bhvHidden1upInPole),
		OBJECT(MODEL_1UP, 2545, 311, 4552, 0, 0, 0, (0x13), bhvHidden1upInPole),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 1273, 311, 3631, 0, 0, 0, (0x13), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -472, 311, 3561, 0, 0, 0, (0x13), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 1890, 311, 2233, 0, 0, 0, (0x13), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 157, 311, 1659, 0, 0, 0, (0x13), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 640, 598, 782, 0, 0, 0, (0x13), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -1314, 937, 1730, 0, 0, 0, (0x13), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -1948, 1205, 704, 0, 0, 0, (0x13), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 2089, 782, 633, 0, 0, 0, (0x13), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 1514, 1113, -919, 0, 0, 0, (0x13), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 2561, 311, -1156, 0, 0, 0, (0x13), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -1318, 311, -1393, 0, 0, 0, (0x13), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -240, 311, -3503, 0, 0, 0, (0x13), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 1058, 311, -55, 0, 0, 0, (0x13), bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 2084, 311, -3110, 0, 0, 0, (0x13), bhvKoopa),
		OBJECT(MODEL_STAR, 1439, 649, -2029, 0, 0, 0, (0x13 << 24) | (0x13), bhvStar),
		OBJECT(MODEL_NONE, 2548, 311, 4078, 0, 0, 0, (0x13 << 16) | (0x13), bhvInstantActiveWarp),
		OBJECT(MODEL_1UP, -211, 389, -415, 0, 0, 0, (0x0C), bhvHidden1upInPole),
		OBJECT(MODEL_1UP, -1267, 389, -408, 0, 0, 0, (0x0C), bhvHidden1upInPole),
		OBJECT(MODEL_1UP, -721, 389, -871, 0, 0, 0, (0x0C), bhvHidden1upInPole),
		OBJECT(MODEL_1UP, -738, 389, 47, 0, 0, 0, (0x0C), bhvHidden1upInPole),
		OBJECT(MODEL_STAR, 938, 1743, 1211, 0, 0, 0, (0x0C << 24) | (0x0C), bhvStar),
		OBJECT(MODEL_NONE, -725, 713, -405, 0, 0, 0, (0x0C << 16) | (0x0C), bhvInstantActiveWarp),
		TERRAIN(bob_area_7_collision),
		MACRO_OBJECTS(bob_area_7_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		SET_ECHO(0x22, 0x22),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(8, bob_area_8),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_BOB, 0x08, 0x0D, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0E, LEVEL_BOB, 0x06, 0x0E, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLACK_BOBOMB, -3748, 389, -754, 0, 0, 0, (0x0D), bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -3898, 1142, 601, 0, 0, 0, (0x0D), bhvBobomb),
		OBJECT(MODEL_PIRANHA_PLANT, -3356, 389, -566, 0, 0, 0, (0x0D), bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, -4454, 389, 232, 0, 0, 0, (0x0D), bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, -4270, 389, -291, 0, 0, 0, (0x0D), bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, -4166, 389, -818, 0, 0, 0, (0x0D), bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, -4471, 389, 691, 0, 0, 0, (0x0D), bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, -3706, 389, 366, 0, 0, 0, (0x0D), bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, -4852, 389, -173, 0, 0, 0, (0x0D), bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, -4576, 389, -548, 0, 0, 0, (0x0D), bhvPiranhaPlant),
		OBJECT(MODEL_BLACK_BOBOMB, -2564, 389, 652, 0, 0, 0, (0x0D), bhvBobomb),
		OBJECT(MODEL_PIRANHA_PLANT, -5241, 389, -645, 0, 0, 0, (0x0D), bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, -5439, 389, 294, 0, 0, 0, (0x0D), bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, -3628, 389, -207, 0, 0, 0, (0x0D), bhvPiranhaPlant),
		OBJECT(MODEL_STAR, -6005, 533, 19, 0, 0, 0, (0x0D << 24) | (0x0D), bhvStar),
		OBJECT(MODEL_NONE, 558, 53, 209, 0, 0, 0, (0x0D << 16), bhvInstantActiveWarp),
		TERRAIN(bob_area_8_collision),
		MACRO_OBJECTS(bob_area_8_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		SET_ECHO(0x22, 0x22),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(9, bob_area_9),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0F, LEVEL_BOB, 0x09, 0x0F, WARP_NO_CHECKPOINT),
		WARP_NODE(0x14, LEVEL_BOB, 0x09, 0x14, WARP_NO_CHECKPOINT),
		WARP_NODE(0x15, LEVEL_WF, 0x02, 0x15, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_PEACH, 2193, 39, -10, 0, 0, 0, (0x14), bhvPeach),
		OBJECT(MODEL_NONE, -2039, 39, 49, 0, 0, 0, (0x14 << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_WHOMP, 12, 39, 6, 0, 0, 0, (0x14), bhvWhompKingBoss),
		TERRAIN(bob_area_9_collision),
		MACRO_OBJECTS(bob_area_9_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		SET_ECHO(0x22, 0x22),
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
