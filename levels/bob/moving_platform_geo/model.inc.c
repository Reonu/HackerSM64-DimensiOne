Vtx moving_platform_geo_moving_platform_geo_mesh_layer_1_vtx_cull[8] = {
	{{{-6, -57, -62}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-6, -57, 53}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-6, 57, 53}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-6, 57, -62}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{10, -57, -62}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{10, -57, 53}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{10, 57, 53}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{10, 57, -62}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
};

Vtx moving_platform_geo_moving_platform_geo_mesh_layer_1_vtx_0[24] = {
	{{{-6, -57, 53}, 0, {368, 1008}, {0x81, 0x0, 0x0, 0xFF}}},
	{{{-6, 57, 53}, 0, {624, 1008}, {0x81, 0x0, 0x0, 0xFF}}},
	{{{-6, 57, -62}, 0, {624, 752}, {0x81, 0x0, 0x0, 0xFF}}},
	{{{-6, -57, -62}, 0, {368, 752}, {0x81, 0x0, 0x0, 0xFF}}},
	{{{-6, -57, -62}, 0, {368, 752}, {0x0, 0x0, 0x81, 0xFF}}},
	{{{-6, 57, -62}, 0, {624, 752}, {0x0, 0x0, 0x81, 0xFF}}},
	{{{10, 57, -62}, 0, {624, 496}, {0x0, 0x0, 0x81, 0xFF}}},
	{{{10, -57, -62}, 0, {368, 496}, {0x0, 0x0, 0x81, 0xFF}}},
	{{{10, -57, -62}, 0, {368, 496}, {0x7F, 0x0, 0x0, 0xFF}}},
	{{{10, 57, -62}, 0, {624, 496}, {0x7F, 0x0, 0x0, 0xFF}}},
	{{{10, 57, 53}, 0, {624, 240}, {0x7F, 0x0, 0x0, 0xFF}}},
	{{{10, -57, 53}, 0, {368, 240}, {0x7F, 0x0, 0x0, 0xFF}}},
	{{{10, -57, 53}, 0, {368, 240}, {0x0, 0x0, 0x7F, 0xFF}}},
	{{{10, 57, 53}, 0, {624, 240}, {0x0, 0x0, 0x7F, 0xFF}}},
	{{{-6, 57, 53}, 0, {624, -16}, {0x0, 0x0, 0x7F, 0xFF}}},
	{{{-6, -57, 53}, 0, {368, -16}, {0x0, 0x0, 0x7F, 0xFF}}},
	{{{-6, -57, -62}, 0, {112, 496}, {0x0, 0x81, 0x0, 0xFF}}},
	{{{10, -57, -62}, 0, {368, 496}, {0x0, 0x81, 0x0, 0xFF}}},
	{{{10, -57, 53}, 0, {368, 240}, {0x0, 0x81, 0x0, 0xFF}}},
	{{{-6, -57, 53}, 0, {112, 240}, {0x0, 0x81, 0x0, 0xFF}}},
	{{{10, 57, -62}, 0, {624, 496}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{-6, 57, -62}, 0, {880, 496}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{-6, 57, 53}, 0, {880, 240}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{10, 57, 53}, 0, {624, 240}, {0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx moving_platform_geo_moving_platform_geo_mesh_layer_1_tri_0[] = {
	gsSPVertex(moving_platform_geo_moving_platform_geo_mesh_layer_1_vtx_0 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSPEndDisplayList(),
};


Gfx mat_moving_platform_geo_cozies_noise_thing_layer1[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(NOISE, 0, SHADE_ALPHA, ENVIRONMENT, 0, 0, 0, 1, PRIMITIVE, SHADE, COMBINED, SHADE, 0, 0, 0, 1),
	gsDPSetFogColor(141, 255, 239, 255),
	gsSPFogPosition(962, 980),
	gsSPGeometryMode(0, G_FOG),
	gsDPSetCycleType(G_CYC_2CYCLE),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 36, 17, 66, 70, 255),
	gsDPSetEnvColor(204, 224, 193, 255),
	gsSPEndDisplayList(),
};

Gfx mat_revert_moving_platform_geo_cozies_noise_thing_layer1[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(G_FOG, 0),
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
	gsSPEndDisplayList(),
};

Gfx moving_platform_geo_moving_platform_geo_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(moving_platform_geo_moving_platform_geo_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_moving_platform_geo_cozies_noise_thing_layer1),
	gsSPDisplayList(moving_platform_geo_moving_platform_geo_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_moving_platform_geo_cozies_noise_thing_layer1),
	gsSPEndDisplayList(),
};

Gfx moving_platform_geo_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

