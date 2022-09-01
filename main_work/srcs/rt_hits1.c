/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:15:01 by ccartet           #+#    #+#             */
/*   Updated: 2022/08/28 14:53:49 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	rt_set_hit_point(t_ray *ray)
{	
	ray->hit.x = ray->origin.x + ray->dir.x * ray->time;
	ray->hit.y = ray->origin.y + ray->dir.y * ray->time;
	ray->hit.z = ray->origin.z + ray->dir.z * ray->time;
}

bool	rt_hit_plane(t_ray *ray, t_object *pl)
{
	float	a;
	float	b;
	float	time;
	float	ratio;

	ratio = 1.0;
	a = rt_dot_prod(*pl->dir, ray->dir);
	b = rt_dot_prod(*pl->dir, rt_sub_vec(*pl->pos, ray->origin)); // distance
	time = b / a;
	if (time <= 0.0)
		return (0);
	if (ray->time == 0.0 || time < ray->time)
		ray->time = time;
	else
		return (0);
	rt_set_hit_point(ray);
	ray->color = *pl->rgb;
	if (time > 25.0)
	{
		ratio = 25.0 / time;
		ray->color = rt_scale_color(*pl->rgb, ratio);
	}
	ray->normal = *pl->dir;
	return (1);
}

bool	rt_hit_sphere(t_ray *ray, t_object *sp)
{
	t_coord	to_center;
	float	a;
	float	half_b;
	float	c;
	float	discriminant;
	float	time[3];

	to_center = rt_sub_vec(ray->origin, *sp->pos);
	a = rt_vector_length_sqr(ray->dir); // normalement egal à 1
	half_b = rt_dot_prod(to_center, ray->dir);
	c = rt_vector_length_sqr(to_center) - sp->radius * sp->radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0.0)
		return (0);
	time[0] = (-half_b + sqrt(discriminant)) * a;
	time[1] = (-half_b - sqrt(discriminant)) * a;
	rt_min_first(&time[0], &time[1]);
	if (time[0] > 0.0 && time[1] > 0.0)
		time[2] = time[1];
	else
		time[2] = time[0];
	if (time[2] > 0.0 && (ray->time == 0.0 || time[2] < ray->time))
		ray->time = time[2];
	else
		return (0);
	rt_set_hit_point(ray);
	if (in_sp)
		ray->normal = rt_sub_vec(*sp->pos, ray->hit);
	else
		ray->normal = rt_sub_vec(ray->hit, *sp->pos);
	rt_norm_vector(&ray->normal);
	ray->color = *sp->rgb;
	return (1);
}

bool	rt_hit_cylinder(t_ray *ray, t_object *cy)
{
	float	a;
	float	half_b;
	float	c;
	float	time[3];
	t_coord	v;
	t_coord	to_origin;
	float	discriminant;

	v = rt_cross_vec(rt_cross_vec(*cy->dir, ray->dir), *cy->dir);
	a = rt_vector_length_sqr(v);
	to_origin = rt_cross_vec(rt_cross_vec(*cy->dir, rt_sub_vec(*cy->pos, ray->origin)), *cy->dir);
	half_b = rt_dot_prod(to_origin, v);
	c = rt_vector_length_sqr(to_origin) - cy->radius * cy->radius;
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
}
