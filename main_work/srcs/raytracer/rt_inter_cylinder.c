#include <mini_rt.h>

float	rt_check_down_plane_cy(t_ray *ray, t_object *cy)
{
	float	time;
	t_coord	tmp_hit;
	float	dist;

	//new_hit = rt_add_vec(hit.point, rt_scale_vec(hit.normal, 0.0001));
	time = rt_calcul_plane(ray, *cy->pos, *cy->dir);
	if (time >= 0.0)
	{
		tmp_hit = rt_add_vec(ray->origin, rt_scale_vec(ray->dir, time));
		dist = rt_vector_length(rt_sub_vec(tmp_hit, *cy->pos));
		if (dist <= cy->radius)
			return (time);
	}
	return (-1);	
}

float	rt_check_up_plane_cy(t_ray *ray, t_object *cy)
{
	t_coord	up;
	float	time;
	t_coord	tmp_hit;
	float	dist;

	up = rt_add_vec(*cy->pos, rt_scale_vec(*cy->dir, cy->height));
	time = rt_calcul_plane(ray, up, *cy->dir);
	if (time >= 0.0)
	{
		tmp_hit = rt_add_vec(ray->origin, rt_scale_vec(ray->dir, time));
		dist = rt_vector_length(rt_sub_vec(tmp_hit, up));
		if (dist <= cy->radius)
			return (time);
	}
	return (-1);	
}

float	rt_end_cy_inter(t_ray *ray, t_object *cy)
{
	float	down;
	float	up;
	float	time;
	float	tmp_time[2];

	down = rt_check_down_plane_cy(ray, cy);
	up = rt_check_up_plane_cy(ray, cy);
	tmp_time[0] = down;
	tmp_time[1] = up;
	if (tmp_time[0] < 0.0 && tmp_time[1] < 0.0)
		return (-1);
	//dprintf(2, "%.2f, %.2f\n", tmp_time[0], tmp_time[1]);
	if (tmp_time[0] > tmp_time[1])
			ft_fswap(&tmp_time[0], &tmp_time[1]);
	if (tmp_time[0] >= 0.0 && tmp_time[1] >= 0.0)
		time = tmp_time[0];
	else
		time = tmp_time[1];
	if (time == down)
		ray->hit.cy_plane = 2;
	else
		ray->hit.cy_plane = 1;
	return (time);
}

void	rt_calcul_cylinder(t_ray *ray, t_object *cy, float *tmp_time, float *delta)
{
	t_coord	v;
	t_coord	u;
	float	a;
	float	half_b;
	float	c;
	
	v = rt_scale_vec(*cy->dir, rt_dot_prod(ray->dir, *cy->dir));
	v = rt_sub_vec(ray->dir, v);
	u = rt_scale_vec(*cy->dir, rt_dot_prod(rt_sub_vec(ray->origin, *cy->pos), *cy->dir));
	u = rt_sub_vec(rt_sub_vec(ray->origin, *cy->pos), u);
	a = rt_vec_length_sqr(v);
	if (a == 0.0)
		return ;
	half_b = 2 * rt_dot_prod(u, v);
	c = rt_vec_length_sqr(u) - pow(cy->radius, 2);
	*delta = pow(half_b, 2) - 4 * a * c;
	if (*delta >= 0.0)
	{
		tmp_time[0] = (-half_b + sqrt(*delta)) / (2 * a);
		tmp_time[1] = (-half_b - sqrt(*delta)) / (2 * a);
		if (tmp_time[0] > tmp_time[1])
			ft_fswap(&tmp_time[0], &tmp_time[1]);
	}
}

float	rt_body_cy_inter(t_ray *ray, t_object *cy)
{
	float	time;
	float	delta;
	float	tmp_time[2];
	t_coord	to_center;
	float	dist[2];

	delta = 0.0;
	rt_calcul_cylinder(ray, cy, tmp_time, &delta);
	if (delta < 0.0 || tmp_time[1] < 0.0)
		return (-1);
	to_center = rt_sub_vec(*cy->pos, ray->origin);
	dist[0] = rt_dot_prod(*cy->dir, rt_sub_vec(rt_scale_vec(ray->dir, tmp_time[0]), to_center));
	dist[1] = rt_dot_prod(*cy->dir, rt_sub_vec(rt_scale_vec(ray->dir, tmp_time[1]), to_center));
	if (!((dist[0] >= 0.0 && dist[0] <= cy->height && tmp_time[0] >= 0.0) ||
			(dist[1] >= 0.0 && dist[1] <= cy->height && tmp_time[1] >= 0.0))) // condition à faire vérifier à Loïc
		return (-1);
	if (tmp_time[0] >= 0.0 && tmp_time[1] >= 0.0)
	{
		time = tmp_time[0];
		ray->hit.dist_for_normal = dist[0];
	}
	else
	{
		time = tmp_time[1];
		ray->hit.dist_for_normal = dist[1];
		ray->in_obj = 1;
	}
	return (time);
}

float	rt_inter_cylinder(t_ray *ray, t_object *cy)
{
	float	body_time;
	float	end_time;

	ray->in_obj = 0;
	ray->hit.cy_plane = 0;
	ray->hit.dist_for_normal = 0;
	body_time = rt_body_cy_inter(ray, cy);
	end_time = rt_end_cy_inter(ray, cy);
	if (body_time < 0.0 && end_time < 0.0)
		return (-1);
	dprintf(1, "%.2f, %.2f       ", end_time, body_time);
	if ((body_time >= 0.0 && end_time > body_time) || end_time < 0.0)
	{
		ray->hit.cy_plane = 0;
		return (body_time);
	}
	else
		return (end_time);
}
