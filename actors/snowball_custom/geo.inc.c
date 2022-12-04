#include "src/game/envfx_snow.h"

const GeoLayout snowball_custom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, snowball_custom_snowball_custom_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, snowball_custom_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
