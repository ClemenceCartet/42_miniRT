
t_coord	find_hit_test(t_camera *cam, t_object *pl) // pour le point central
{
	float		d;
	float		distance;
	t_coord	i;

	d = -(dot_product(*pl->dir, *pl->pos));
	dprintf(2, "%f\n", d);
	distance = -(dot_product(*pl->dir, *cam->pos) + d) 
		/ dot_product(*pl->dir, *cam->dir);
	dprintf(2, "%f\n", distance);
	i.x = cam->pos->x + cam->dir->x * distance;
	i.y = cam->pos->y + cam->dir->y * distance;
	i.z = cam->pos->z + cam->dir->z * distance;
	dprintf(2, "%f, %f, %f\n", i.x, i.y, i.z);
	return (i);
}
