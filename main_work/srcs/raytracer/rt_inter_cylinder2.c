/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_inter_cylinder2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:30:03 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/14 14:31:48 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

float	rt_body_cy_inter(t_ray *ray, t_object *cy)
{
	float	time;
	float	delta;
	float	tmp_time[2];
	t_coord	to_center;
	float	dist[2];

	time = 0.0;
	delta = 0.0;
	rt_calcul_cy(ray, cy, tmp_time, &delta);
	if (delta < 0.0 || tmp_time[1] < 0.0)
		return (-1);
	to_center = rt_sub_vec(*cy->pos, ray->origin);
	//nouvelle fonction
	dist[0] = rt_dot_prod(*cy->dir,
			rt_sub_vec(rt_scale_vec(ray->dir, tmp_time[0]), to_center));
	dist[1] = rt_dot_prod(*cy->dir,
			rt_sub_vec(rt_scale_vec(ray->dir, tmp_time[1]), to_center));
	if (!((dist[0] >= 0.0 && dist[0] <= cy->height && tmp_time[0] >= 0.0)
			|| (dist[1] >= 0.0 && dist[1] <= cy->height && tmp_time[1] >= 0.0)))
		return (-1);
	if (!(dist[0] >= 0.0 && dist[0] <= cy->height && tmp_time[0] >= 0.0))
		time = rt_set_time(ray, tmp_time[1], dist[1], 1);
	else if (!(dist[1] >= 0.0 && dist[1] <= cy->height && tmp_time[1] >= 0.0))
		time = rt_set_time(ray, tmp_time[0], dist[0], 0);
	else if (tmp_time[0] >= 0.0 && tmp_time[1] >= 0.0)
		time = rt_set_time(ray, tmp_time[0], dist[0], 0);
	else
		time = rt_set_time(ray, tmp_time[1], dist[1], 1);
	// ouaf
	return (time);
}

float	rt_inter_cylinder(t_ray *ray, t_object *cy)
{
	float	body_time;
	float	end_time;

	ray->in_obj = 0;
	ray->hit.cy_plane = 0;
	ray->hit.dist_for_normal = 0;
	body_time = rt_body_cy_inter(ray, cy);
	end_time = rt_end_cy_inter(ray, cy);
	if (body_time < 0.0 && end_time < 0.0)
		return (-1);
	if ((body_time >= 0.0 && end_time > body_time) || end_time < 0.0)
	{
		ray->hit.cy_plane = 0;
		return (body_time);
	}
	else
		return (end_time);
}
