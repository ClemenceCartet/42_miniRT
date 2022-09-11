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

// float	rt_calcul_cylinder(t_ray *ray, t_object *cy, float *tmp_time)
// {
// 	float	a;
// 	float	half_b;
// 	float	c;
// 	float	delta;
	
// 	a = pow(ray->dir.x, 2) + pow(ray->dir.z, 2);
// 	half_b = ray->dir.x * ray->origin.x + ray->dir.z * ray->origin.z;
// 	c = pow(ray->origin.x, 2) + pow(ray->origin.z, 2) - pow(cy->radius, 2);
// 	delta = half_b * half_b - a * c;
// 	if (delta >= 0.0)
// 	{
// 		tmp_time[0] = 0.0 + sqrt(delta) / a;
// 		tmp_time[1] = 0.0 - sqrt(delta) / a;
// 		if (tmp_time[0] > tmp_time[1])
// 			ft_fswap(&tmp_time[0], &tmp_time[1]);
// 	}
// 	return (delta);
// }

float	rt_calcul_cylinder(t_ray *ray, t_object *cy, float *tmp_time)
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

float	rt_inter_cylinder(t_ray *ray, t_object *cy)
{
	t_ray	new_ray;
	float	time;
	float	delta;
	float	tmp_time[2];
	float	dist[2];
	t_coord	to_center;
	float	time_ends;

	ray->in_obj = 0;
	ray->hit.cy_plane = 0;
	new_ray.origin = rt_sub_vec(ray->origin, *cy->pos);
	new_ray.dir = ray->dir;
	x_axis_rotation(&new_ray.dir, cy->dir->x);
	y_axis_rotation(&new_ray.dir, cy->dir->y);
	z_axis_rotation(&new_ray.dir, cy->dir->z);
	time = -1;
	delta = rt_calcul_cylinder(ray, cy, tmp_time);
	if (delta < 0.0 || tmp_time[1] < 0.0)
		return (-1);
	to_center = rt_sub_vec(*cy->pos, ray->origin);
	dist[0] = rt_dot_prod(*cy->dir, rt_sub_vec(rt_scale_vec(ray->dir, tmp_time[0]), *cy->pos));
	dist[1] = rt_dot_prod(*cy->dir, rt_sub_vec(rt_scale_vec(ray->dir, tmp_time[1]), *cy->pos));
	if (dist[0] >= 0.0 && dist[1] >= 0.0)
		time = dist[0];
	else
	{
		time = dist[1];
		ray->in_obj = 1;
	}
	// dprintf(2, "%.2f\n", time);
	// if (time >= 0.0 && !rt_check_up_down_cy_v2(time, ray, cy))
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