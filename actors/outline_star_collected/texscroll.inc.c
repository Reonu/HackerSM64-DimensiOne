void scroll_sts_mat_outline_star_collected_f3dlite_material_layer7() {
	Gfx *mat = segmented_to_virtual(mat_outline_star_collected_f3dlite_material_layer7);
	shift_t(mat, 13, PACK_TILESIZE(0, 2));
	shift_t_down(mat, 21, PACK_TILESIZE(0, 2));
};

void scroll_actor_geo_outline_star_collected() {
	scroll_sts_mat_outline_star_collected_f3dlite_material_layer7();
}
