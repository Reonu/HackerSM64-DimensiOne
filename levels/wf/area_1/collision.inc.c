const Collision wf_area_1_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(12),
	COL_VERTEX(-4230, -3100, 4230),
	COL_VERTEX(7892, -3100, 4230),
	COL_VERTEX(7892, -3100, -4230),
	COL_VERTEX(-4230, -3100, -4230),
	COL_VERTEX(-331, 0, 275),
	COL_VERTEX(219, 0, 275),
	COL_VERTEX(219, 0, -275),
	COL_VERTEX(-331, 0, -275),
	COL_VERTEX(-331, -211, 275),
	COL_VERTEX(-331, -211, -275),
	COL_VERTEX(219, -211, -275),
	COL_VERTEX(219, -211, 275),
	COL_TRI_INIT(SURFACE_DEATH_PLANE, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_INIT(SURFACE_DEFAULT, 12),
	COL_TRI(4, 5, 6),
	COL_TRI(4, 6, 7),
	COL_TRI(8, 9, 10),
	COL_TRI(8, 10, 11),
	COL_TRI(5, 11, 10),
	COL_TRI(5, 10, 6),
	COL_TRI(7, 9, 8),
	COL_TRI(7, 8, 4),
	COL_TRI(6, 10, 9),
	COL_TRI(6, 9, 7),
	COL_TRI(4, 8, 11),
	COL_TRI(4, 11, 5),
	COL_TRI_STOP(),
	COL_END()
};
