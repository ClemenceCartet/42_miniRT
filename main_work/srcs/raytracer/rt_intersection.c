/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadegecartet <nadegecartet@student.42ly    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:41:39 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/08 15:48:20 by nadegecarte      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

float	rt_inter_plane(t_ray *ray, t_object *pl)
{
	float	angle_rad;
	float	distance;
	float	time;

	angle_rad = rt_dot_prod(*pl->dir, ray->dir);
	if (!angle_rad)
		return (-1);
	distance = rt_dot_prod(*pl->dir, rt_sub_vec(*pl->pos, ray->origin));
	time = distance / angle_rad;
	if (time <= 0.0)
		return (-1);
	return (time);
}

static float	rt_calcul_sphere(t_ray *ray, t_object *sp, float *tmp_time)
{
	t_coord	from_center;
	float	a;
	float	half_b;
	float	c;
	float	delta;

	from_center = rt_sub_vec(ray->origin, *sp->pos);
	a = rt_vec_length_sqr(ray->dir);
	half_b = rt_dot_prod(from_center, ray->dir);
	c = rt_vec_length_sqr(from_center) - sp->radius * sp->radius;
	delta = half_b * half_b - a * c;
	if (delta >= 0.0)
	{
		tmp_time[0] = -half_b + sqrt(delta) * a;
		tmp_time[1] = -half_b - sqrt(delta) * a;
		if (tmp_time[0] > tmp_time[1])
			ft_fswap(&tmp_time[0], &tmp_time[1]);
	}
	return (delta);
}

float	rt_inter_sphere(t_ray *ray, t_object *sp)
{
	float	time;
	float	delta;
	float	tmp_time[2];

	ray->in_obj = 0;
	delta = rt_calcul_sphere(ray, sp, tmp_time);
	if (delta < 0.0 || tmp_time[1] < 0.0)
		return (-1);
	if (tmp_time[0] > 0.0 && tmp_time[1] > 0.0)
		time = tmp_time[0];
	else
	{
		time = tmp_time[1];
		ray->in_obj = 1;
	}
	return (time);
}

void	rt_intersect(t_obj_data *obj_data, t_ray *ray)
{
	size_t		n;
	int			i;
	float		time;

	n = 0;
	time = -1;
	while (n < obj_data->lst_size)
	{
		i = 1;
		while (i <= 3)
		{
			if (i == obj_data->objects[n]->id)
				time = obj_data->fct[i - 1](ray, obj_data->objects[n]);
			if (time != -1 && (ray->inter == 0 || time < ray->hit.time))
				rt_set_hit(ray, obj_data->objects[n], time);
			i++;
		}
		n++;
	}
}
