/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:15:01 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/14 15:49:19 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	rt_set_hit_point(t_ray *ray)
{	
	ray->hit.point.x = ray->origin.x + ray->dir.x * ray->hit.time;
	ray->hit.point.y = ray->origin.y + ray->dir.y * ray->hit.time;
	ray->hit.point.z = ray->origin.z + ray->dir.z * ray->hit.time;
}

void	rt_find_normal_cy(t_hit *hit, t_object *cy, int in_obj)
{
	t_coord	new_center;

	new_center.x = cy->pos->x + cy->dir->x * hit->dist_for_normal;
	new_center.y = cy->pos->y + cy->dir->y * hit->dist_for_normal;
	new_center.z = cy->pos->z + cy->dir->z * hit->dist_for_normal;
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

void	rt_find_normal_sphere(t_ray *ray, t_object *sp)
{
	if (ray->in_obj)
		ray->hit.normal = rt_sub_vec(*sp->pos, ray->hit.point);
	else
		ray->hit.normal = rt_sub_vec(ray->hit.point, *sp->pos);
}

void	rt_set_hit(t_ray *ray, t_object *obj, float time)
{
	ray->hit.time = time;
	rt_set_hit_point(ray);
	ray->inter = 1;
	if (obj->id == SP)
		rt_find_normal_sphere(ray, obj);
	if (obj->id == PL)
		rt_find_normal_plane(ray, *obj->dir);
	if (obj->id == CY)
	{
		if (ray->hit.cy_plane == 1)
			rt_find_normal_plane(ray, *obj->dir);
		else if (ray->hit.cy_plane == 2)
			rt_find_normal_plane(ray, rt_scale_vec(*obj->dir, -1));
		else
			rt_find_normal_cy(&ray->hit, obj, ray->in_obj);
	}	
	rt_norm_vector(&ray->hit.normal);
	ray->hit.color = *obj->rgb;
}
