/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadegecartet <nadegecartet@student.42ly    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:15:01 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/08 15:58:23 by nadegecarte      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

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
	{
		if (rt_dot_prod(ray->dir, *pl->dir) > 0)
			ray->hit.normal = rt_scale_vec(*obj->dir, -1);
		else
			ray->hit.normal = *obj->dir;
	}
	// if (obj->id == CY)
	rt_norm_vector(&ray->hit.normal);
	ray->hit.color = *obj->rgb;
	ray->hit.obj = obj;
}
