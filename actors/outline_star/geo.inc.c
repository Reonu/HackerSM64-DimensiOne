#include "src/game/envfx_snow.h"

const GeoLayout outline_star_geo[] = {
	GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x9B, 100),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, outline_star_anocollect_mask_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, outline_star_no_collect_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, outline_star_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
