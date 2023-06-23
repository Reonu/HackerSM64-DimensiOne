void scroll_gfx_mat_wf_dl_f3dlite_material_005_layer1() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_f3dlite_material_005_layer1);


	shift_s(mat, 11, PACK_TILESIZE(0, 1));
	shift_t(mat, 11, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 16, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_wf() {
	scroll_gfx_mat_wf_dl_f3dlite_material_005_layer1();
};
