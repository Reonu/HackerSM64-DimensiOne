#include "src/game/envfx_snow.h"

const GeoLayout moving_platform_geo_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, moving_platform_geo_moving_platform_geo_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, moving_platform_geo_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
