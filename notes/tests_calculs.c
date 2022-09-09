
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
	to_center = rt_sub_vec(*sp->pos, ray->origin);
	distance = dot_product(to_center, ray->dir);
	opposit = vector_length(to_center) * vector_length(to_center) - distance * distance;
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

static float	rt_calcul_cylinder(t_ray *ray, t_object *cy, float *tmp_time)
{
	t_coord	vA;
	t_coord	rAO;
	float	a;
	float	half_b;
	float	c;
	float	delta;
	
	vA = rt_cross_vec(ray->dir, *cy->dir);
	rAO = rt_cross_vec(rt_sub_vec(ray->origin, *cy->pos), *cy->dir);
	a = rt_vec_length_sqr(vA);
	half_b = rt_dot_prod(rAO, vA);
	c = rt_vec_length_sqr(rAO) - cy->radius * cy->radius;
	delta = half_b * half_b - c;
	if (delta >= 0.0)
	{
		tmp_time[0] = -half_b + sqrt(delta);
		tmp_time[1] = -half_b - sqrt(delta);
		if (tmp_time[0] > tmp_time[1])
			ft_fswap(&tmp_time[0], &tmp_time[1]);
	}
	return (delta);
}
// ne fonctionne pas...

/*static bool	check_up_down_cy(float time, t_ray *ray, t_object *cy)
{
	float 	hit_y;

	hit_y = ray->origin.y + ray->dir.y * time;
	if (hit_y >= 0.0 && hit_y <= cy->height)
		return (1);
	return (0);
}

t_coord	rt_scale_2vec(t_coord v1, t_coord v2)
{
	float	x;
	float	y;
	float	z;

	x = v1.x * v2.x;
	y = v1.y * v2.y;
	z = v1.z * v2.z;
	return (rt_create_vector(x, y ,z)); 
}*/