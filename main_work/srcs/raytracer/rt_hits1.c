/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hits1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:15:01 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/03 12:27:57 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	rt_set_hit_pl(float t, t_ray *ray, t_object *pl)
{	
	float	ratio;

	ratio = 1.0;
	ray->hit.time = t;
	ray->inter = 1;
	rt_set_hit_point(ray);
	if (rt_dot_prod(ray->dir, *pl->dir) > 0)
		ray->hit.normal = rt_scale_vec(*pl->dir, -1);
	else
		ray->hit.normal = *pl->dir;
	ray->hit.color = *pl->rgb;
	if (t > 25.0)
	{
		ratio = 25.0 / t;
		ray->hit.color = rt_scale_color(*pl->rgb, ratio);
	}
	ray->hit.obj = pl;
}	

bool	rt_inter_plane(t_ray *ray, t_object *pl, int crea)
{
	float	a;
	float	b;
	float	time;

	a = rt_dot_prod(*pl->dir, ray->dir); // angle
	if (!a)
		return (0);
	b = rt_dot_prod(*pl->dir, rt_sub_vec(*pl->pos, ray->origin)); // distance
	time = b / a;
	if (time <= 0.0)
		return (0);
	if (crea && (ray->inter == 0 || time < ray->hit.time))
		rt_set_hit_pl(time, ray, pl);
	return (1);
}

bool	rt_set_hit_sp(float t, t_ray *ray, t_object *sp, int in_sphere)
{	
	t_coord	check;

	ray->hit.time = t;
	ray->inter = 1;
	rt_set_hit_point(ray);
	check = rt_sub_vec(ray->origin, ray->hit.point);
	if (rt_dot_prod(check, ray->dir) > 0.0)
		return (0);
	if (in_sphere)
		ray->hit.normal = rt_sub_vec(*sp->pos, ray->hit.point);
	else
		ray->hit.normal = rt_sub_vec(ray->hit.point, *sp->pos);
	rt_norm_vector(&ray->hit.normal);
	ray->hit.color = *sp->rgb;
	ray->hit.obj = sp;
	return (1);
}	

float	rt_calcul_sphere(t_ray *ray, t_object *sp, float *res)
{
	t_coord	to_center;
	float	a;
	float	half_b;
	float	c;
	float	discriminant;

	to_center = rt_sub_vec(ray->origin, *sp->pos);
	a = rt_vec_length_sqr(ray->dir); // égal à 1, à supprimer du coup ?
	half_b = rt_dot_prod(to_center, ray->dir);
	c = rt_vec_length_sqr(to_center) - pow(sp->radius, 2); // toujours la même valeur pour une sphère
	discriminant = half_b * half_b - a * c;
	if (discriminant >= 0.0)
	{
		res[0] = (-half_b + sqrt(discriminant)) * a;
		res[1] = (-half_b - sqrt(discriminant)) * a;
		if (res[0] > res[1])
			ft_fswap(&res[0], &res[1]);
	}
	return (discriminant);
}

bool	rt_inter_sphere(t_ray *ray, t_object *sp, int crea)
{
	float	discriminant;
	float	res[2];
	float	time;
	int		in_sphere;

	in_sphere = 0;
	discriminant = rt_calcul_sphere(ray, sp, res);
	if (discriminant < 0.0)
		return (0);
	if (!crea)
		return (1);
	if (res[0] > 0.0 && res[1] > 0.0)
		time = res[1];
	else
	{
		time = res[0]; // on se trouve dans la sphere
		in_sphere = 1;
	}
	if (ray->inter == 0 || time < ray->hit.time)
		if (!rt_set_hit_sp(time, ray, sp, in_sphere))
			return (0);
	return (1);
}
