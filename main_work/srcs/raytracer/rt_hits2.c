/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hits2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:12:30 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/03 09:37:03 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	rt_set_hit_point(t_ray *ray)
{	
	ray->hit.point.x = ray->origin.x + ray->dir.x * ray->hit.time;
	ray->hit.point.y = ray->origin.y + ray->dir.y * ray->hit.time;
	ray->hit.point.z = ray->origin.z + ray->dir.z * ray->hit.time;
}

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
