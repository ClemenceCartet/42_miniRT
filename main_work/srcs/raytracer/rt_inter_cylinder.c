#include <mini_rt.h>

void	find_normal_cy(t_hit *hit, t_object *cy, int in_obj)
{
	t_coord c_to_h;
	float	angle;
	float	dist;
	t_coord	new_center;

	c_to_h = rt_sub_vec(hit->point, *cy->pos);
	rt_norm_vector(&c_to_h);
	angle = rt_dot_prod(c_to_h, *cy->dir);
	dist = cos(angle) * rt_vector_length(rt_sub_vec(hit->point, *cy->pos));
	new_center.x = cy->pos->x + cy->dir->x * dist;
	new_center.y = cy->pos->y + cy->dir->y * dist;
	new_center.z = cy->pos->z + cy->dir->z * dist;
	if (in_obj)
		hit->normal = rt_sub_vec(new_center, hit->point);
	else
		hit->normal = rt_sub_vec(hit->point, new_center);
}

static bool	check_up_down_cy(float time, t_ray *ray, t_object *cy)
{
	t_coord hit;
	t_coord	p1;
	t_coord	p2;
	float	up;
	float	down;

	hit.x = ray->origin.x + ray->dir.x * time;
	hit.y = ray->origin.y + ray->dir.y * time;
	hit.z = ray->origin.z + ray->dir.z * time;
	p1 = *cy->pos;
	down = rt_dot_prod(rt_sub_vec(hit, p1), *cy->dir); // calcul intersection plane
	p2 = rt_add_vec(p1, rt_scale_vec(*cy->dir, cy->height));
	up = rt_dot_prod(rt_sub_vec(hit, p2), *cy->dir);
	if (down > 0.0 && up < 0.0)
		return (1);
	return (0);
}

static float	rt_calcul_cylinder(t_ray *ray, t_object *cy, float *tmp_time)
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
	t_coord	to_center;
	float	time;
	float	delta;
	float	tmp_time[2];
	float	dist[2];

	ray->in_obj = 0;
	delta = rt_calcul_cylinder(ray, cy, tmp_time);
	if (delta < 0.0 || tmp_time[1] < 0.0)
		return (-1);
	to_center = rt_sub_vec(*cy->pos, ray->origin);
	dist[0] = rt_dot_prod(*cy->dir, rt_sub_vec(rt_scale_vec(ray->dir, tmp_time[0]), to_center));
	dist[1] = rt_dot_prod(*cy->dir, rt_sub_vec(rt_scale_vec(ray->dir, tmp_time[1]), to_center));
	if (dist[0] > 0.0 && dist[1] > 0.0)
		time = dist[0];
	else
	{
		time = dist[1];
		ray->in_obj = 1;
	}
	if (!check_up_down_cy(time, ray, cy))
		return (-1);
	return (time);
}

