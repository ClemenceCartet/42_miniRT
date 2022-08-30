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

void	set_hit_point(t_ray *ray)
{	
	ray->hit.x = ray->origin.x + ray->dir.x * ray->time;
	ray->hit.y = ray->origin.y + ray->dir.y * ray->time;
	ray->hit.z = ray->origin.z + ray->dir.z * ray->time;
}

bool	hit_plane(t_ray *ray, t_object *pl)
{
	float	a;
	float	b;
	float	time;

	a = rt_dot_prod(*pl->dir, ray->dir);
	b = rt_dot_prod(*pl->dir, rt_sub_vec(*pl->pos, ray->origin)); // distance
	time = b / a;
	if (time <= 0.0)
		return (0);
	if (ray->time == 0.0 || time < ray->time)
		ray->time = time;
	else
		return (0);
	set_hit_point(ray);
	ray->color = *pl->rgb;
	ray->normal = *pl->dir;
	ray->object_id = PL;
	return (1);
}

bool	hit_sphere(t_ray *ray, t_object *sp)
{
	t_coord	to_center;
	float	a;
	float	half_b;
	float	c;
	float	discriminant;
	float	time[3];
	int		in_sp;

	in_sp = 0;
	to_center = rt_sub_vec(ray->origin, *sp->pos);
	a = vector_length_squared(ray->dir); // normalement egal à 1
	half_b = rt_dot_prod(to_center, ray->dir);
	c = vector_length_squared(to_center) - sp->radius * sp->radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0.0)
		return (0);
	time[0] = (-half_b + sqrt(discriminant)) * a;
	time[1] = (-half_b - sqrt(discriminant)) * a;
	min_first(&time[0], &time[1]);
	if (time[0] > 0.0 && time[1] > 0.0)
		time[2] = time[1];
	else
	{
		in_sp = 1; // à enregistrer dans t_ray ? front / back ?
		time[2] = time[0];
	}
	if (time[2] > 0.0 && (ray->time == 0.0 || time[2] < ray->time))
		ray->time = time[2];
	else
		return (0);
	set_hit_point(ray);
	if (in_sp)
		ray->normal = rt_sub_vec(*sp->pos, ray->hit);
	else
		ray->normal = rt_sub_vec(ray->hit, *sp->pos);
	norm_vector(&ray->normal);
	ray->color = *sp->rgb;
	ray->object_id = SP;
	return (1);
}

bool	hit_cylinder(t_ray *ray, t_object *cy)
{
	float	a;
	float	half_b;
	float	c;
	float	time[3];
	t_coord	v;
	t_coord	to_origin;
	float	discriminant;

	v = rt_cross_vec(rt_cross_vec(*cy->dir, ray->dir), *cy->dir);
	a = vector_length_squared(v);
	to_origin = rt_cross_vec(rt_cross_vec(*cy->dir, rt_sub_vec(*cy->pos, ray->origin)), *cy->dir);
	half_b = rt_dot_prod(to_origin, v);
	c = vector_length_squared(to_origin) - cy->radius * cy->radius;
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
	set_hit_point(ray);
	if (!(rt_dot_prod(rt_sub_vec(*cy->pos, ray->hit), *cy->dir) > 0.0 &&
		rt_dot_prod(rt_sub_vec(rt_scale_vec(*cy->pos, cy->height), ray->hit), *cy->dir) < 0.0))
		return (0);
	ray->color = *cy->rgb;
	ray->object_id = CY;
	return (1);
}
