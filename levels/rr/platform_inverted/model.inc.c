Vtx platform_inverted_platform_inverted_mesh_layer_0_vtx_cull[8] = {
	{{{-100, -115, -100}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-100, -115, 100}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-100, 85, 100}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-100, 85, -100}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{100, -115, -100}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{100, -115, 100}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{100, 85, 100}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{100, 85, -100}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
};

Vtx platform_inverted_platform_inverted_mesh_layer_0_vtx_0[16] = {
	{{{100, -115, 100}, 0, {487, 240}, {0x0, 0x0, 0x81, 0xFF}}},
	{{{-100, -115, 100}, 0, {487, -16}, {0x0, 0x0, 0x81, 0xFF}}},
	{{{-100, 85, 100}, 0, {624, -16}, {0x0, 0x0, 0x81, 0xFF}}},
	{{{100, 85, 100}, 0, {624, 240}, {0x0, 0x0, 0x81, 0xFF}}},
	{{{100, -115, -100}, 0, {487, 496}, {0x81, 0x0, 0x0, 0xFF}}},
	{{{100, -115, 100}, 0, {487, 240}, {0x81, 0x0, 0x0, 0xFF}}},
	{{{100, 85, 100}, 0, {624, 240}, {0x81, 0x0, 0x0, 0xFF}}},
	{{{100, 85, -100}, 0, {624, 496}, {0x81, 0x0, 0x0, 0xFF}}},
	{{{-100, -115, -100}, 0, {487, 752}, {0x0, 0x0, 0x7F, 0xFF}}},
	{{{100, -115, -100}, 0, {487, 496}, {0x0, 0x0, 0x7F, 0xFF}}},
	{{{100, 85, -100}, 0, {624, 496}, {0x0, 0x0, 0x7F, 0xFF}}},
	{{{-100, 85, -100}, 0, {624, 752}, {0x0, 0x0, 0x7F, 0xFF}}},
	{{{-100, -115, 100}, 0, {487, 1008}, {0x7F, 0x0, 0x0, 0xFF}}},
	{{{-100, -115, -100}, 0, {487, 752}, {0x7F, 0x0, 0x0, 0xFF}}},
	{{{-100, 85, -100}, 0, {624, 752}, {0x7F, 0x0, 0x0, 0xFF}}},
	{{{-100, 85, 100}, 0, {624, 1008}, {0x7F, 0x0, 0x0, 0xFF}}},
};

Gfx platform_inverted_platform_inverted_mesh_layer_0_tri_0[] = {
	gsSPVertex(platform_inverted_platform_inverted_mesh_layer_0_vtx_0 + 0, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSPEndDisplayList(),
};

Vtx platform_inverted_platform_inverted_mesh_layer_0_vtx_1[4] = {
	{{{100, 85, -100}, 0, {624, 496}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{-100, 85, -100}, 0, {880, 496}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{-100, 85, 100}, 0, {880, 240}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{100, 85, 100}, 0, {624, 240}, {0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx platform_inverted_platform_inverted_mesh_layer_0_tri_1[] = {
	gsSPVertex(platform_inverted_platform_inverted_mesh_layer_0_vtx_1 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};


Gfx mat_platform_inverted_sm64_material_001_layer0[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(NOISE, 0, SHADE_ALPHA, ENVIRONMENT, 0, 0, 0, 1, PRIMITIVE, SHADE, COMBINED, SHADE, 0, 0, 0, 1),
	gsDPSetFogColor(141, 255, 239, 255),
	gsSPFogPosition(962, 980),
	gsSPGeometryMode(0, G_FOG),
	gsDPSetCycleType(G_CYC_2CYCLE),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 36, 17, 66, 70, 255),
	gsDPSetEnvColor(205, 224, 193, 255),
	gsSPEndDisplayList(),
};

Gfx mat_revert_platform_inverted_sm64_material_001_layer0[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(G_FOG, 0),
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsDPSetRenderMode(G_RM_ZB_OPA_SURF, G_RM_ZB_OPA_SURF2),
	gsSPEndDisplayList(),
};

Gfx mat_platform_inverted_writeZ_layer0[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
	gsDPSetRenderMode(GBL_c1(G_BL_CLR_BL, G_BL_0, G_BL_CLR_MEM, G_BL_1) | GBL_c2(G_BL_CLR_BL, G_BL_0, G_BL_CLR_MEM, G_BL_1), AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_platform_inverted_writeZ_layer0[] = {
	gsDPPipeSync(),
	gsDPSetRenderMode(G_RM_ZB_OPA_SURF, G_RM_ZB_OPA_SURF2),
	gsSPEndDisplayList(),
};

Gfx platform_inverted_platform_inverted_mesh_layer_0[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(platform_inverted_platform_inverted_mesh_layer_0_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_platform_inverted_sm64_material_001_layer0),
	gsSPDisplayList(platform_inverted_platform_inverted_mesh_layer_0_tri_0),
	gsSPDisplayList(mat_revert_platform_inverted_sm64_material_001_layer0),
	gsSPDisplayList(mat_platform_inverted_writeZ_layer0),
	gsSPDisplayList(platform_inverted_platform_inverted_mesh_layer_0_tri_1),
	gsSPDisplayList(mat_revert_platform_inverted_writeZ_layer0),
	gsSPEndDisplayList(),
};

Gfx platform_inverted_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

