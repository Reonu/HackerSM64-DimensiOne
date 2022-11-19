Vtx wf_dl_Plane_003_mesh_layer_1_vtx_cull[8] = {
	{{{-275, 0, 275}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-275, 0, 275}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-275, 0, -275}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-275, 0, -275}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{275, 0, 275}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{275, 0, 275}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{275, 0, -275}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{275, 0, -275}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
};

Vtx wf_dl_Plane_003_mesh_layer_1_vtx_0[4] = {
	{{{-275, 0, 275}, 0, {-16, 1008}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{275, 0, 275}, 0, {1008, 1008}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{275, 0, -275}, 0, {1008, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
	{{{-275, 0, -275}, 0, {-16, -16}, {0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx wf_dl_Plane_003_mesh_layer_1_tri_0[] = {
	gsSPVertex(wf_dl_Plane_003_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_wf_dl_cozies_noise_thing_layer1[] = {
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

Gfx mat_revert_wf_dl_cozies_noise_thing_layer1[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(G_FOG, 0),
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
	gsSPEndDisplayList(),
};

Gfx wf_dl_Plane_003_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(wf_dl_Plane_003_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_wf_dl_cozies_noise_thing_layer1),
	gsSPDisplayList(wf_dl_Plane_003_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_wf_dl_cozies_noise_thing_layer1),
	gsSPEndDisplayList(),
};

Gfx wf_dl_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

