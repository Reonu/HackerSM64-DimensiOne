#include "src/game/envfx_snow.h"

const GeoLayout moving_platform_geo_challenge_10_bob_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_moving_platform_geo_challenge_10_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
