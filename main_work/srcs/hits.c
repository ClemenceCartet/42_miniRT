/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:15:01 by ccartet           #+#    #+#             */
/*   Updated: 2022/08/24 15:18:07 by ccartet          ###   ########.fr       */
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

	a = dot_product(*pl->dir, ray->dir);
	b = dot_product(*pl->dir, find_vector(ray->origin, *pl->pos)); // distance
	time = b / a;
	if (time <= 0.0)
		return (0);
	if (ray->time == 0.0 || time < ray->time)
		ray->time = time;
	else
		return (0);
	set_hit_point(ray);
	ray->color = *pl->rgb;
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

	to_center = find_vector(*sp->pos, ray->origin);
	a = vector_length_squared(ray->dir); // normalement egal à 1
	half_b = dot_product(to_center, ray->dir);
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
		time[2] = time[0];
	if (time[2] > 0.0 && (ray->time == 0.0 || time[2] < ray->time))
		ray->time = time[2];
	else
		return (0);
	set_hit_point(ray);
	ray->normal = find_vector(*sp->pos, ray->hit);
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

	v = cross_vectors(cross_vectors(*cy->dir, ray->dir), *cy->dir);
	a = vector_length_squared(v);
	to_origin = cross_vectors(cross_vectors(*cy->dir, find_vector(ray->origin, *cy->pos)), *cy->dir);
	half_b = dot_product(to_origin, v);
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
	if (!(dot_product(find_vector(ray->hit, *cy->pos), *cy->dir) > 0.0 &&
		dot_product(find_vector(ray->hit, scale_vectors_bis(*cy->pos, cy->height)), *cy->dir) < 0.0))
		return (0);
	ray->color = *cy->rgb;
	ray->object_id = CY;
	return (1);
}
