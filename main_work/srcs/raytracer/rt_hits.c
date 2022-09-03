/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:15:01 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/03 15:14:36 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

/*bool	rt_hit_cylinder(t_ray *ray, t_object *cy)
{
	float	a;
	float	half_b;
	float	c;
	float	time[3];
	t_coord	v;
	t_coord	to_origin;
	float	discriminant;

	v = rt_cross_vec(rt_cross_vec(*cy->dir, ray->dir), *cy->dir);
	a = rt_vec_length_sqr(v);
	to_origin = rt_cross_vec(rt_cross_vec(*cy->dir, rt_sub_vec(*cy->pos, ray->origin)), *cy->dir);
	half_b = rt_dot_prod(to_origin, v);
	c = rt_vec_length_sqr(to_origin) - cy->radius * cy->radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0.0)
		return (0);
	time[0] = (-half_b + sqrt(discriminant)) * a;
	time[1] = (-half_b - sqrt(discriminant)) * a;
	if (time[0] < time[1])
		time[2] = time[0];
	else
		time[2] = time[1];
	if (time[2] > 0.0 && ray->time == 0.0)
		ray->time = time[2];
	else if (time[2] > 0.0 && time[2] < ray->time)
		ray->time = time[2];
	else
		return (0);
	rt_set_hit_point(ray);
	if (!(rt_dot_prod(rt_sub_vec(*cy->pos, ray->hit), *cy->dir) > 0.0 &&
		rt_dot_prod(rt_sub_vec(rt_scale_vec(*cy->pos, cy->height), ray->hit), *cy->dir) < 0.0))
		return (0);
	ray->color = *cy->rgb;
	return (1);
}*/

// void	rt_set_hit_pl(float t, t_ray *ray, t_object *pl)
// {	
// 	float	ratio;

// 	ratio = 1.0;
// 	ray->hit.time = t;
// 	rt_set_hit_point(ray);
// 	if (rt_dot_prod(ray->dir, *pl->dir) > 0)
// 		ray->hit.normal = rt_scale_vec(*pl->dir, -1);
// 	else
// 		ray->hit.normal = *pl->dir;
// 	ray->hit.color = *pl->rgb;
// 	if (t > 25.0)
// 	{
// 		ratio = 25.0 / t;
// 		ray->hit.color = rt_scale_color(*pl->rgb, ratio);
// 	}
// 	ray->hit.obj = pl;
// }	

// bool	rt_set_hit_sp(float t, t_ray *ray, t_object *sp, int in_sphere)
// {	
// 	t_coord	check;

// 	ray->hit.time = t;
// 	rt_set_hit_point(ray);
// 	check = rt_sub_vec(ray->origin, ray->hit.point);
// 	if (rt_dot_prod(check, ray->dir) > 0.0)
// 		return (0);
// 	if (in_sphere)
// 		ray->hit.normal = rt_sub_vec(*sp->pos, ray->hit.point);
// 	else
// 		ray->hit.normal = rt_sub_vec(ray->hit.point, *sp->pos);
// 	rt_norm_vector(&ray->hit.normal);
// 	ray->hit.color = *sp->rgb;
// 	ray->hit.obj = sp;
// 	return (1);
// }	

void	rt_set_hit_point(t_ray *ray)
{	
	ray->hit.point.x = ray->origin.x + ray->dir.x * ray->hit.time;
	ray->hit.point.y = ray->origin.y + ray->dir.y * ray->hit.time;
	ray->hit.point.z = ray->origin.z + ray->dir.z * ray->hit.time;
}

void	rt_set_hit(t_ray *ray, t_object *obj, float time)
{
	ray->hit.time = time;
	rt_set_hit_point(ray);
	ray->inter = 1;
	if (obj->id == SP)
	{
		if (ray->in_obj)
			ray->hit.normal = rt_sub_vec(*obj->pos, ray->hit.point);
		else
			ray->hit.normal = rt_sub_vec(ray->hit.point, *obj->pos);
	}
	if (obj->id == PL)
		ray->hit.normal = *obj->dir;
	// if (obj->id == CY)
	rt_norm_vector(&ray->hit.normal);
	ray->hit.color = *obj->rgb;
	ray->hit.obj = obj;
}
