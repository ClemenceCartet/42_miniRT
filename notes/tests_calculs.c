
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

float	rt_calcul_cylinder_v1(t_ray *ray, t_object *cy, float *tmp_time)
{
	t_coord	from_center;
	t_coord	v;
	t_coord	u;
	float	a;
	float	half_b;
	float	c;
	float	delta;
	
	from_center = rt_sub_vec(ray->origin, *cy->pos);
	rt_norm_vector(&from_center);
	v = rt_scale_vec(*cy->dir, rt_dot_prod(ray->dir, *cy->dir));
	v = rt_sub_vec(ray->dir, v);
	u = rt_scale_vec(*cy->dir, rt_dot_prod(from_center, *cy->dir));
	u = rt_sub_vec(from_center, u);
	a = rt_vec_length_sqr(v);
	half_b = rt_dot_prod(u, v);
	c = rt_vec_length_sqr(u) - cy->radius * cy->radius;
	delta = half_b * half_b - a * c;
	//dprintf(2, "%.2f   ", delta);
	if (delta >= 0.0)
	{
		tmp_time[0] = half_b + sqrt(delta) / a;
		tmp_time[1] = half_b - sqrt(delta) / a;
		if (tmp_time[0] > tmp_time[1])
			ft_fswap(&tmp_time[0], &tmp_time[1]);
	}
	return (delta);
} // fonctuionne avec inter cylinder_v2

float	rt_inter_cylinder_v2(t_ray *ray, t_object *cy)
{
	float	delta;
	t_coord	to_center;
	float	tmp_time[2];
	float	dist[2];
	//float	time_ends;
	float	time;

	ray->in_obj = 0;
	ray->hit.cy_plane = 0;
	time = -1;
	delta = rt_calcul_cylinder_v1(ray, cy, tmp_time);
	if (delta < 0.0 || tmp_time[1] < 0.0)
		return (-1);
	to_center = rt_sub_vec(*cy->pos, ray->origin);
	dist[0] = rt_dot_prod(*cy->dir, rt_sub_vec(rt_scale_vec(ray->dir, tmp_time[0]), to_center));
	dist[1] = rt_dot_prod(*cy->dir, rt_sub_vec(rt_scale_vec(ray->dir, tmp_time[1]), to_center));
	//dprintf(2, "%.2f,%.2f   ", tmp_time[0], tmp_time[1]);
	if (dist[0] > 0.0 && dist[1] > 0.0)
		time = dist[0];
	else
	{
		time = dist[1];
		ray->in_obj = 1;
	}
	// if (time > 0.0)
	// {
	// 	if (!rt_check_up_down_cy(time, ray, cy))
	// 		time = -1;
	// }
	// ray->hit.cy_plane = rt_set_ends_cylinder(ray, cy, &time_ends);
	// //dprintf(2, "%d\n", ray->hit.cy_plane);
	// if (time_ends != -1 && time != -1 && time_ends < time)
	// 	return (time_ends);
	// if (time_ends != -1 && time == -1)
	// 	return (time_ends);
	// ray->hit.cy_plane = 0;
	return (time);
}

float	rt_calcul_cylinder_v2(t_ray *ray, t_object *cy, float *tmp_time)
{
	float	a;
	float	half_b;
	float	c;
	float	delta;
	
	a = pow(ray->dir.x, 2) + pow(ray->dir.z, 2);
	half_b = ray->dir.x * ray->origin.x + ray->dir.z * ray->origin.z;
	c = pow(ray->origin.x, 2) + pow(ray->origin.z, 2) - pow(cy->radius, 2);
	delta = half_b * half_b - a * c;
	if (delta >= 0.0)
	{
		tmp_time[0] = 0.0 + sqrt(delta) / a;
		tmp_time[1] = 0.0 - sqrt(delta) / a;
		if (tmp_time[0] > tmp_time[1])
			ft_fswap(&tmp_time[0], &tmp_time[1]);
	}
	return (delta);
}

	new_ray.origin = rt_sub_vec(ray->origin, *cy->pos);
	new_ray.dir = ray->dir;
	x_axis_rotation(&new_ray.dir, cy->dir->x);
	y_axis_rotation(&new_ray.dir, cy->dir->y);
	z_axis_rotation(&new_ray.dir, cy->dir->z);

float	rt_calcul_cylinder_v3(t_ray *ray, t_object *cy, float *tmp_time)
{
	t_coord	x_vec;
	t_coord	z_vec;
	float 	time_to_axis_pl;
	t_coord	h1;
	float 	time_along_axis;
	t_coord	h2;
	t_coord	line_segment;
	float	a;
	float	c;
	float	delta;
	
	x_vec = rt_cross_vec(ray->dir, *cy->dir);
	z_vec = rt_cross_vec(*cy->dir, x_vec);
	time_to_axis_pl = rt_dot_prod(z_vec, rt_sub_vec(*cy->pos, ray->origin)) / rt_dot_prod(z_vec, ray->dir);
	h1.x = ray->origin.x + ray->dir.x * time_to_axis_pl;
	h1.y = ray->origin.y + ray->dir.y * time_to_axis_pl;
	h1.z = ray->origin.z + ray->dir.z * time_to_axis_pl;
	time_along_axis = rt_dot_prod(*cy->dir, rt_sub_vec(h1, *cy->pos)) / rt_vec_length_sqr(*cy->dir);
	h2.x = cy->pos->x + cy->dir->x * time_along_axis;
	h2.y = cy->pos->y + cy->dir->y * time_along_axis;
	h2.z = cy->pos->z + cy->dir->z * time_along_axis;
	line_segment = rt_sub_vec(h1, h2);
	if (rt_vector_length(line_segment) > cy->radius)
		return (-1);
	dprintf(2, "%.2f,  ", rt_vector_length(line_segment));
	a = pow(rt_dot_prod(ray->dir, z_vec), 2);
	c = pow(rt_dot_prod(line_segment, x_vec), 2) - pow(cy->radius, 2);
	delta = c / a;
	if (delta >= 0.0)
	{
		tmp_time[0] = 0.0 + sqrt(delta) / a;
		tmp_time[1] = 0.0 - sqrt(delta) / a;
		if (tmp_time[0] > tmp_time[1])
			ft_fswap(&tmp_time[0], &tmp_time[1]);
	}
	return (delta);
}

float	rt_calcul_cylinder_v4(t_ray *ray, t_object *cy, float *tmp_time)
{
	t_coord	from_center;
	float	a;
	float	half_b;
	float	c;
	float	delta;

	from_center = rt_sub_vec(ray->origin, *cy->pos);
	a = rt_vec_length_sqr(ray->dir) - pow(rt_dot_prod(ray->dir, *cy->dir), 2);
	half_b = 2 * (rt_dot_prod(ray->dir, from_center) - rt_dot_prod(ray->dir, *cy->dir) * rt_dot_prod(from_center, *cy->dir));
	c = rt_vec_length_sqr(from_center) - pow(rt_dot_prod(from_center, *cy->dir), 2) - pow(cy->radius, 2);
	delta = pow(half_b, 2) - 4 * a * c;
	if (delta > 0.0)
	{
		tmp_time[0] = -half_b + sqrt(delta) / 2 * a;
		tmp_time[1] = -half_b - sqrt(delta) / 2 * a;
		if (tmp_time[0] > tmp_time[1])
			ft_fswap(&tmp_time[0], &tmp_time[1]);
	}
	return (delta);
}

float	rt_calcul_cylinder_v5(t_ray *ray, t_object *cy, float *tmp_time) // v5
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
	if (a == 0.0)
		return (-1);
	half_b = 2 * rt_dot_prod(rAO, vA);
	c = rt_vec_length_sqr(rAO) - pow(cy->radius, 2);
	delta = pow(half_b, 2) - 4 * a * c;
	if (delta > 0.0)
	{
		tmp_time[0] = -half_b + sqrt(delta) / 2 * a;
		tmp_time[1] = -half_b - sqrt(delta) / 2 * a;
		if (tmp_time[0] > tmp_time[1])
			ft_fswap(&tmp_time[0], &tmp_time[1]);
	}
	return (delta);
}

bool	rt_check_up_down_cy_v2(float time, t_ray *ray, t_object *cy)
{
	t_coord tmp_hit;
	t_coord	from_down;
	t_coord	d_to_u;

	float	dist;

	tmp_hit = rt_add_vec(ray->origin, rt_scale_vec(ray->dir, time));
	//dprintf(2, "%.2f,%.2f,%.2f   ", tmp_hit.x, tmp_hit.y, tmp_hit.z);
	from_down = rt_sub_vec(tmp_hit, *cy->pos);
	d_to_u = rt_sub_vec(cy->cypos, *cy->pos);
	rt_norm_vector(&d_to_u);
	dist = rt_dot_prod(from_down, d_to_u);
	if (dist >= 0.0 && dist <= cy->height)
		return (1);
	return (0);
}

bool	rt_check_up_down_cy(float time, t_ray *ray, t_object *cy)
{
	t_coord tmp_hit;
	t_coord	from_down;
	float	dist_from_down;
	float	angle_down;
	float	dist;

	tmp_hit = rt_add_vec(ray->origin, rt_scale_vec(ray->dir, time));
	// dprintf(2, "%.2f,%.2f,%.2f   ", tmp_hit.x, tmp_hit.y, tmp_hit.z);
	from_down = rt_sub_vec(tmp_hit, *cy->pos);
	dist_from_down = rt_vector_length(from_down);
	angle_down = asin(cy->radius / dist_from_down);
	dist = cos(angle_down) * dist_from_down;
	//dprintf(2, "%.2f,%.2f  ", dist_from_down, dist);
	if (dist <= cy->height)
		return (1);
	return (0);
}
