/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_inter_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:28:42 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/15 09:13:30 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

float	rt_end_cy_inter(t_ray *ray, t_object *cy)
{
	float	down;
	t_coord	up_pos;
	float	up;
	float	time;
	float	tmp_time[2];

	down = rt_check_plane_cy(ray, *cy->pos, cy);
	up_pos = rt_add_vec(*cy->pos, rt_scale_vec(*cy->dir, cy->height));
	up = rt_check_plane_cy(ray, up_pos, cy);
	tmp_time[0] = down;
	tmp_time[1] = up;
	if (tmp_time[0] < 0.0 && tmp_time[1] < 0.0)
		return (-1);
	if (tmp_time[0] > tmp_time[1])
		ft_fswap(&tmp_time[0], &tmp_time[1]);
	if (tmp_time[0] >= 0.0 && tmp_time[1] >= 0.0)
		time = tmp_time[0];
	else
		time = tmp_time[1];
	if (time == down)
		ray->hit.cy_plane = 2;
	else
		ray->hit.cy_plane = 1;
	return (time);
}

void	rt_calcul_cy(t_ray *ray, t_object *cy, float *tmp_time, float *delta)
{
	t_coord	from_center;
	float	a;
	float	half_b;
	float	c;

	from_center = rt_sub_vec(ray->origin, *cy->pos);
	a = rt_vec_length_sqr(ray->dir) - pow(rt_dot_prod(ray->dir, *cy->dir), 2);
	if (a == 0.0)
		return ;
	half_b = 2 * (rt_dot_prod(ray->dir, from_center)
			- rt_dot_prod(ray->dir, *cy->dir)
			* rt_dot_prod(from_center, *cy->dir));
	c = rt_vec_length_sqr(from_center)
		- pow(rt_dot_prod(from_center, *cy->dir), 2) - pow(cy->radius, 2);
	*delta = pow(half_b, 2) - 4 * a * c;
	if (*delta >= 0.0)
	{
		tmp_time[0] = (-half_b + sqrt(*delta)) / (2 * a);
		tmp_time[1] = (-half_b - sqrt(*delta)) / (2 * a);
		if (tmp_time[0] > tmp_time[1])
			ft_fswap(&tmp_time[0], &tmp_time[1]);
	}
}

float	rt_body_cy_inter(t_ray *ray, t_object *cy)
{
	float	time;
	float	delta;
	float	tmp_time[2];

	time = 0.0;
	delta = 0.0;
	rt_calcul_cy(ray, cy, tmp_time, &delta);
	if (delta < 0.0 || tmp_time[1] < 0.0)
		return (-1);
	time = rt_check_body_cy(ray, cy, tmp_time);
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
