#include "src/game/envfx_snow.h"

const GeoLayout platform2_rr_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, platform2_rr_platform2_rr_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, platform2_rr_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
