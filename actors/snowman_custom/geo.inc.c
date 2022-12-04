#include "src/game/envfx_snow.h"

const GeoLayout snowman_custom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SCALE(LAYER_FORCE, 16384),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, snowman_custom_000_displaylist_mesh_layer_1),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 356, 0, 0, NULL),
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_OPAQUE, snowman_custom_000_displaylist_001_mesh_layer_1),
					GEO_CLOSE_NODE(),
					GEO_ANIMATED_PART(LAYER_ALPHA, 356, 0, 0, snowman_custom_002_offset_mesh_layer_4),
					GEO_ANIMATED_PART(LAYER_ALPHA, 356, 0, 0, snowman_custom_003_offset_mesh_layer_4),
					GEO_SWITCH_CASE(2, geo_switch_anim_state),
					GEO_OPEN_NODE(),
						GEO_NODE_START(),
						GEO_OPEN_NODE(),
							GEO_NODE_START(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 89, 0, -229, NULL),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, snowman_custom_000_offset_003_mesh_layer_1),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 68, 0, 0, snowman_custom_000_offset_004_mesh_layer_1),
							GEO_ASM(0, geo_update_projectile_pos_from_parent),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 356, 0, 0, NULL),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, snowman_custom_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, snowman_custom_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
