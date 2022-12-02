#include "src/game/envfx_snow.h"

const GeoLayout clock_geo[] = {
	GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xA8, 120),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, clock_clock_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, clock_clock_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, clock_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, clock_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
