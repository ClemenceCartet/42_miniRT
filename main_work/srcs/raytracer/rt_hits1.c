/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hits1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:15:01 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/03 13:42:15 by ljohnson         ###   ########lyon.fr   */
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
