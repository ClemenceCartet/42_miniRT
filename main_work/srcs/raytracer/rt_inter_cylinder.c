#include <mini_rt.h>

t_coord	find_normal

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
	down = rt_dot_prod(rt_sub_vec(hit, p1), *cy->dir);
	p2 = rt_add_vec(p1, rt_scale_vec(*cy->dir, cy->height));
	up = rt_dot_prod(rt_sub_vec(hit, p2), *cy->dir);
	if (down > 0.0 && up < 0.0)
		return (1);
	return (0);
}

static float	rt_calcul_cylinder(t_ray *ray, t_object *cy, float *tmp_time)
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


float	rt_inter_cylinder(t_ray *ray, t_object *cy)
{
	float	time;
	float	delta;
	float	tmp_time[2];

	ray->in_obj = 0;
	delta = rt_calcul_cylinder(ray, cy, tmp_time);
	if (delta < 0.0 || tmp_time[1] < 0.0)
		return (-1);
	if (tmp_time[0] > 0.0 && tmp_time[1] > 0.0)
		time = tmp_time[0];
	else
	{
		time = tmp_time[1];
		ray->in_obj = 1;
	}
	if (!check_up_down_cy(time, ray, cy))
		return (-1);
	return (time);
}
