
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

bool	hit_sphere(t_ray *ray, t_object *sp)
{
	t_coord	to_center;
	float	distance;
	float	opposit;
	float	radius;

	radius = sp->diameter * 0.5;
	to_center = find_vector(ray->origin, *sp->pos);
	distance = dot_product(to_center, ray->dir);
	opposit = vector_lenght(to_center) * vector_lenght(to_center) - distance * distance;
	if (opposit < (radius * radius))
	{
		dprintf(2, "blop");
		ray->color = *sp->rgb;
		return (1);
	}
	return (0);
}

bool	hit_plane(t_ray *ray, t_object *pl)
{
	float	d;
	float	distance;

	d = -(dot_product(*pl->dir, *pl->pos));
	distance = -(dot_product(*pl->dir, ray->origin) + d) 
		/ dot_product(*pl->dir, ray->dir);
	if (distance <= 0)
		return (0);
	if (ray->time == 0.0 || distance < ray->time)
		ray->time = distance;
	else
		return (0);
	set_hit_point(ray);
	return (1);
}