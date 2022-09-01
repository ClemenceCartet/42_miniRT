/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:15:01 by ccartet           #+#    #+#             */
/*   Updated: 2022/08/28 14:53:49 by ccartet          ###   ########.fr       */
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

	a = rt_dot_prod(*pl->dir, ray->dir);
	b = rt_dot_prod(*pl->dir, rt_sub_vec(*pl->pos, ray->origin)); // distance
	time = b / a;
	if (time <= 0.0)
		return (0);
	if (crea && (ray->inter == 0 || time < ray->hit.time))
		rt_set_hit_pl(time, ray, pl);
	return (1);
}

void	rt_set_hit_sp(float t, t_ray *ray, t_object *sp, int in_sphere)
{	
	ray->hit.time = t;
	ray->inter = 1;
	rt_set_hit_point(ray);
	if (in_sphere)
		ray->hit.normal = rt_sub_vec(*sp->pos, ray->hit.point);
	else
		ray->hit.normal = rt_sub_vec(ray->hit.point, *sp->pos);
	rt_norm_vector(&ray->hit.normal);
	ray->hit.color = *sp->rgb;
	ray->hit.obj = sp;
}	

float	rt_calcul_sphere(t_ray *ray, t_object *sp, float *res)
{
	t_coord	to_center;
	float	a;
	float	half_b;
	float	c;
	float	discriminant;

	to_center = rt_sub_vec(ray->origin, *sp->pos);
	a = rt_vec_length_sqr(ray->dir);
	half_b = rt_dot_prod(to_center, ray->dir);
	c = rt_vec_length_sqr(to_center) - pow(sp->radius, 2);
	discriminant = half_b * half_b - a * c;
	if (discriminant >= 0.0)
	{
		res[0] = (-half_b + sqrt(discriminant)) * a;
		res[1] = (-half_b - sqrt(discriminant)) * a;
		rt_min_first(&res[0], &res[1]);
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
		rt_set_hit_sp(time, ray, sp, in_sphere);
	return (1);
}
