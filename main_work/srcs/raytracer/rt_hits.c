/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:15:01 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/12 14:54:23 by ccartet          ###   ########.fr       */
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

void	rt_find_normal_cy(t_hit *hit, t_object *cy, int in_obj)
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

void	rt_find_normal_plane(t_ray *ray, t_coord pl_dir)
{
	if (rt_dot_prod(ray->dir, pl_dir) > 0)
		ray->hit.normal = rt_scale_vec(pl_dir, -1);
	else
		ray->hit.normal = pl_dir;
}

void	rt_set_hit(t_ray *ray, t_object *obj, float time)
{
	t_color blop;

	blop.r = 0.2;
	blop.g = 0.8;
	blop.b = 1.0;
	ray->hit.time = time;
	rt_set_hit_point(ray);
	// dprintf(2, "%.2f,%.2f,%.2f   ", ray->hit.point.x,ray->hit.point.y, ray->hit.point.z);
	ray->inter = 1;
	if (obj->id == SP)
	{
		if (ray->in_obj)
			ray->hit.normal = rt_sub_vec(*obj->pos, ray->hit.point);
		else
			ray->hit.normal = rt_sub_vec(ray->hit.point, *obj->pos);
	}
	if (obj->id == PL)
		rt_find_normal_plane(ray, *obj->dir);
	if (obj->id == CY)
	{
		if (ray->hit.cy_plane == 1)
			rt_find_normal_plane(ray, *obj->dir);
		else if (ray->hit.cy_plane == 2)
			rt_find_normal_plane(ray, obj->cydir);
		else
			rt_find_normal_cy(&ray->hit, obj, ray->in_obj);
	}	
	rt_norm_vector(&ray->hit.normal);
	if (ray->hit.cy_plane == 1 || ray->hit.cy_plane == 2)
		ray->hit.color = blop;
	else
		ray->hit.color = *obj->rgb;
}
