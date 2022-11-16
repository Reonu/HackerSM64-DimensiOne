#include "src/game/envfx_snow.h"

const GeoLayout outline_star_collected_geo[] = {
	GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x9B, 100),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, outline_star_collected_anocollect_mask_001_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, outline_star_collected_no_collect_001_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, outline_star_collected_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
