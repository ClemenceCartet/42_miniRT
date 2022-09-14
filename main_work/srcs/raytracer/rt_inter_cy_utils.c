/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_inter_cy_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:30:03 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/14 15:48:20 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

float	rt_check_plane_cy(t_ray *ray, t_coord cy_pos, t_object *cy)
{
	float	time;
	t_coord	tmp_hit;
	float	dist;

	time = rt_calcul_plane(ray, cy_pos, *cy->dir);
	if (time >= 0.0)
	{
		tmp_hit = rt_add_vec(ray->origin, rt_scale_vec(ray->dir, time));
		dist = rt_vector_length(rt_sub_vec(tmp_hit, cy_pos));
		if (dist <= cy->radius)
			return (time);
	}
	return (-1);
}

float	rt_set_time(t_ray *ray, float tmp_time, float dist, int ok)
{
	float	time;

	time = tmp_time;
	ray->hit.dist_for_normal = dist;
	ray->in_obj = ok;
	return (time);
}

float	rt_check_body_cy(t_ray *ray, t_object *cy, float *tmp_time)
{
	float	dist[2];
	t_coord	to_center;
	float	time;

	time = 0.0;
	to_center = rt_sub_vec(*cy->pos, ray->origin);
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
	return (time);
}
