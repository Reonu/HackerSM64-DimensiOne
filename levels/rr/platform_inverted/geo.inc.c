#include "src/game/envfx_snow.h"

const GeoLayout platform_inverted_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_FORCE, platform_inverted_platform_inverted_mesh_layer_0),
		GEO_DISPLAY_LIST(LAYER_FORCE, platform_inverted_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
