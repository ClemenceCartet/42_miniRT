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

/*void	set_ends_cylinder(t_ray *ray, t_object *cy)
{
	float	time;
	t_coord	tmp_hit;

	time = rt_inter_plane(ray, cy->pl_up);


}*/

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
	down = rt_dot_prod(rt_sub_vec(hit, *cy->pos), *cy->dir); // calcul intersection plane
	up = rt_dot_prod(rt_sub_vec(hit, *cy->), *cy->dir);
	if (down > 0.0 && up < 0.0)
		return (1);
	return (0);
}

static float	rt_calcul_cylinder_v1(t_ray *ray, t_object *cy, float *tmp_time)
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
	delta = rt_calcul_cylinder_v1(ray, cy, tmp_time);
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
	//if (!check_up_down_cy(time, ray, cy))
	//	return (-1);
	return (time);
}