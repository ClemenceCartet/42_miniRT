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
	time_down = rt_check_plane_cy(ray, *cy->pos, cy->cydir, cy->radius); // pas forcément obligé de mettre une dir différente...
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

float	rt_calcul_cylinder(t_ray *ray, t_object *cy, float *tmp_time) // v6
{
	t_coord	from_center;
	t_coord	v;
	t_coord	u;
	float	a;
	float	b;
	float	c;
	float	delta;
	
	from_center = rt_sub_vec(ray->origin, *cy->pos);
	rt_norm_vector(&from_center);
	v = rt_scale_vec(*cy->dir, rt_dot_prod(ray->dir, *cy->dir));
	v = rt_sub_vec(ray->dir, v);
	u = rt_scale_vec(*cy->dir, rt_dot_prod(from_center, *cy->dir));
	u = rt_sub_vec(from_center, u);
	a = rt_vec_length_sqr(v);
	b = 2 * rt_dot_prod(u, v);
	c = rt_vec_length_sqr(u) - pow(cy->radius, 2);
	delta = pow(b, 2) - 4 * a * c;
	if (delta >= 0.0)
	{
		tmp_time[0] = -b + sqrt(delta) / 2 * a;
		tmp_time[1] = -b - sqrt(delta) / 2 * a;
		if (tmp_time[0] > tmp_time[1])
			ft_fswap(&tmp_time[0], &tmp_time[1]);
	}
	return (delta);
}

float	rt_inter_cylinder(t_ray *ray, t_object *cy)
{
	float	time;
	float	delta;
	float	tmp_time[2];
	t_coord	to_center;
	float	dist[2];
	float	dist_for_normal;
	float	time_ends;

	ray->in_obj = 0;
	ray->hit.cy_plane = 0;
	time = -1;
	delta = rt_calcul_cylinder(ray, cy, tmp_time);
	if (delta < 0.0 || tmp_time[1] < 0.0)
		return (-1);
	to_center = rt_sub_vec(*cy->pos, ray->origin);
	dist[0] = rt_dot_prod(*cy->dir, rt_sub_vec(rt_scale_vec(ray->dir, tmp_time[0]), to_center));
	dist[1] = rt_dot_prod(*cy->dir, rt_sub_vec(rt_scale_vec(ray->dir, tmp_time[1]), to_center));
	if (!((dist[0] >= 0.0 && dist[0] <= cy->height && tmp_time[0] > 0.0) ||
			(dist[1] >= 0.0 && dist[1] <= cy->height && tmp_time[1] > 0.0)))
		return (-1);
	if (tmp_time[0] > 0.0 && tmp_time[1] > 0.0)
	{
		time = tmp_time[0];
		dist_for_normal = dist[0];
	}
	else
	{
		time = tmp_time[1];
		dist_for_normal = dist[1];
		ray->in_obj = 1;
	}
	ray->hit.cy_plane = rt_set_ends_cylinder(ray, cy, &time_ends);
	//dprintf(2, "%d\n", ray->hit.cy_plane);
	if (time_ends != -1 && time != -1 && time_ends < time)
		return (time_ends);
	if (time_ends != -1 && time == -1)
		return (time_ends);
	ray->hit.cy_plane = 0;
	return (time);
}