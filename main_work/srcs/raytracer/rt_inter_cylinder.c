#include <mini_rt.h>

float	rt_check_plane_cy(t_ray *ray, t_coord cy_pos, t_coord cy_dir, float radius)
{
	float	time;
	t_coord	tmp_hit;
	float	dist;

	time = rt_calcul_plane(ray, cy_pos, cy_dir);
	if (time >= 0.0)
	{
		tmp_hit = rt_add_vec(ray->origin, rt_scale_vec(ray->dir, time));
		dist = rt_vector_length(rt_sub_vec(tmp_hit, cy_pos));
		if (dist <= radius)
			return (time);
	}
	return (-1);	
}

int	rt_set_ends_cylinder(t_ray *ray, t_object *cy, float *time_ends)
{
	float	time_down;
	float	time_up;
	int		ret;

	ret = 0;
	time_down = rt_check_plane_cy(ray, *cy->pos, cy->cydir, cy->radius);
	//dprintf(2, "%.2f\n", time_down);
	time_up = rt_check_plane_cy(ray, cy->cypos, *cy->dir, cy->radius);
	if ((time_down > 0.0 && time_up > 0.0) && time_down < time_up)
		*time_ends = time_down;
	else if ((time_down > 0.0 && time_up > 0.0) && time_down > time_up)
		*time_ends = time_up;
	else if (time_down > 0.0 && time_up < 0.0)
		*time_ends = time_down;
	else if (time_down < 0.0 && time_up > 0.0)
		*time_ends = time_up;
	else
		*time_ends = -1;
	if (*time_ends == time_up)
		ret = 1;
	if (*time_ends == time_down)
		ret = 2;
	return (ret);
}

bool	rt_check_up_down_cy(float time, t_ray *ray, t_object *cy)
{
	t_coord tmp_hit;
	t_coord	from_down;
	t_coord	from_up;
	float	up;
	float	down;

	tmp_hit = rt_add_vec(ray->origin, rt_scale_vec(ray->dir, time));
	from_down = rt_sub_vec(tmp_hit, *cy->pos);
	rt_norm_vector(&from_down);
	from_up = rt_sub_vec(tmp_hit, cy->cypos);
	rt_norm_vector(&from_up);
	down = rt_dot_prod(from_down, *cy->dir); // calcul intersection plane
	up = rt_dot_prod(from_up, *cy->dir);
	if (down > 0.0 && up < 0.0)
		return (1);
	return (0);
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
	v = rt_scale_vec(*cy->dir, rt_dot_prod(ray->dir, *cy->dir));
	v = rt_sub_vec(ray->dir, v);
	u = rt_scale_vec(*cy->dir, rt_dot_prod(from_center, *cy->dir));
	u = rt_sub_vec(from_center, u);
	a = rt_vec_length_sqr(v);
	half_b = rt_dot_prod(u, v);
	c = rt_vec_length_sqr(u) - cy->radius * cy->radius;
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

float	rt_inter_cylinder(t_ray *ray, t_object *cy)
{
	// float	delta;
	// t_coord	to_center;
	// float	tmp_time[2];
	// float	dist[2];
	float	time_ends;
	float	time;

	ray->in_obj = 0;
	ray->hit.cy_plane = 0;
	time = -1;
	// delta = rt_calcul_cylinder_v1(ray, cy, tmp_time);
	// if (delta < 0.0 || tmp_time[1] < 0.0)
	// 	return (-1);
	// to_center = rt_sub_vec(*cy->pos, ray->origin);
	// dist[0] = rt_dot_prod(*cy->dir, rt_sub_vec(rt_scale_vec(ray->dir, tmp_time[0]), to_center));
	// dist[1] = rt_dot_prod(*cy->dir, rt_sub_vec(rt_scale_vec(ray->dir, tmp_time[1]), to_center));
	// if (dist[0] > 0.0 && dist[1] > 0.0)
	// 	time = dist[0];
	// else
	// {
	// 	time = dist[1];
	// 	ray->in_obj = 1;
	// }
	// if (!rt_check_up_down_cy(time, ray, cy))
	// 	time = -1;
	ray->hit.cy_plane = rt_set_ends_cylinder(ray, cy, &time_ends);
	//dprintf(2, "%d\n", ray->hit.cy_plane);
	if (time_ends != -1 && time != -1 && time_ends < time)
		return (time_ends);
	if (time_ends != -1 && time == -1)
		return (time_ends);
	ray->hit.cy_plane = 0;
	return (time);
}

static float	rt_calcul_cylinder_v2(t_ray *ray, t_object *cy, float *tmp_time)
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

/*static float	rt_calcul_cylinder_v3(t_ray *ray, t_object *cy, float *tmp_time)
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
	
	x_vec = rt_cross_vec(*cy->dir, ray->dir);
	rt_norm_vector(&x_vec);
	z_vec = rt_cross_vec(*cy->dir, x_vec);
	time_to_axis_pl = rt_dot_prod(z_vec, rt_sub_vec(*cy->pos, ray->origin)) / rt_dot_prod(z_vec, ray->dir);
	h1.x = ray->origin.x + ray->dir.x * time_to_axis_pl;
	h1.y = ray->origin.y + ray->dir.y * time_to_axis_pl;
	h1.z = ray->origin.z + ray->dir.z * time_to_axis_pl;
	time_along_axis = rt_dot_prod(*cy->dir, rt_sub_vec(h1, *cy->pos)) / rt_vec_length_sqr(*cy->dir);
	h2.x = ray->origin.x + ray->dir.x * time_along_axis;
	h2.y = ray->origin.y + ray->dir.y * time_along_axis;
	h2.z = ray->origin.z + ray->dir.z * time_along_axis;
	line_segment = rt_sub_vec(h1, h2);
	//dprintf(2, "%.2f, %.2f\n", rt_vector_length(line_segment), cy->radius);
	if (rt_vector_length(line_segment) > cy->radius)
		return (-1);
	a = pow(rt_dot_prod(ray->dir, z_vec), 2);
	c = pow(rt_dot_prod(line_segment, x_vec), 2) - pow(cy->radius, 2);
	delta = c / a;
	if (delta >= 0.0)
	{
		tmp_time[0] = 0.0 + sqrt(delta);
		tmp_time[1] = 0.0 - sqrt(delta);
		if (tmp_time[0] > tmp_time[1])
			ft_fswap(&tmp_time[0], &tmp_time[1]);
	}
	return (delta);
}*/

float	rt_inter_cylinder_bis(t_ray *ray, t_object *cy)
{
	t_ray	new_ray;
	float	time;
	float	delta;
	float	tmp_time[2];

	new_ray.origin = rt_sub_vec(ray->origin, *cy->pos);
	new_ray.dir = ray->dir;
	x_axis_rotation(&new_ray.dir, -asin(cy->dir->x));
	//x_axis_rotation(&new_ray.dir, atan2(cy->dir->y, cy->dir->x));
	//z_axis_rotation(&new_ray.dir, -asin(cy->dir->z));
	delta = rt_calcul_cylinder_v2(&new_ray, cy, tmp_time);
	if (delta < 0.0 || tmp_time[1] < 0.0)
		return (-1);
	if (tmp_time[0] > 0.0 && tmp_time[1] > 0.0)
		time = tmp_time[0];
	else
	{
		time = tmp_time[1];
		ray->in_obj = 1;
	}
	//if (!rt_check_up_down_cy(time, ray, cy))
	//	return (-1);
	return (time);
}