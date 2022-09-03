/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:41:39 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/03 14:52:41 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// bool	rt_inter_plane(t_ray *ray, t_object *pl, int crea)
// {
// 	float	a;
// 	float	b;
// 	float	time;

// 	a = rt_dot_prod(*pl->dir, ray->dir); // angle
// 	if (!a)
// 		return (0);
// 	b = rt_dot_prod(*pl->dir, rt_sub_vec(*pl->pos, ray->origin)); // distance
// 	time = b / a;
// 	if (time <= 0.0)
// 		return (0);
// 	if (crea && (ray->inter == 0 || time < ray->hit.time))
// 		rt_set_hit_pl(time, ray, pl);
// 	return (1);
// }

// bool	rt_inter_sphere(t_ray *ray, t_object *sp, int crea)
// {
// 	float	discriminant;
// 	float	res[2];
// 	float	time;
// 	int		in_sphere;

// 	in_sphere = 0;
// 	discriminant = rt_calcul_sphere(ray, sp, res);
// 	if (discriminant < 0.0)
// 		return (0);
// 	if (!crea)
// 		return (1);
// 	if (res[0] > 0.0 && res[1] > 0.0)
// 		time = res[1];
// 	else
// 	{
// 		time = res[0];
// 		in_sphere = 1;
// 	}
// 	if (ray->inter == 0 || time < ray->hit.time)
// 		if (!rt_set_hit_sp(time, ray, sp, in_sphere))
// 			return (0);
// 	return (1);
// }

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
	float	half_b;
	float	c;
	float	delta;
	// float	a;

	from_center = rt_sub_vec(ray->origin, *sp->pos);
	// a = rt_vec_length_sqr(ray->dir);
	half_b = rt_dot_prod(from_center, ray->dir);
	c = rt_vec_length_sqr(from_center) - sp->radius * sp->radius;
	delta = half_b * half_b - c;
	if (delta >= 0.0)
	{
		tmp_time[0] = -half_b + sqrt(delta);
		tmp_time[1] = -half_b - sqrt(delta);
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
	if (delta < 0.0)
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
	t_fcthit	fct[2];
	float		time;

	fct[0] = &rt_inter_sphere;
	fct[1] = &rt_inter_plane;
	//fct[2] = &rt_inter_cylinder;
	n = 0;
	time = -1;
	while (n < obj_data->lst_size)
	{
		i = 1;
		while (i <= 2)
		{
			if (i == obj_data->objects[n]->id)
				time = (*fct[i - 1])(ray, obj_data->objects[n], 1);
			i++;
		}
		n++;
	}
}
