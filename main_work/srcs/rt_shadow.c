/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:12:43 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/03 09:34:46 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

bool	rt_check_inter_sphere(t_ray *ray, t_object *sp, int crea)
{
	float	discriminant;
	float	res[2];
	float	time;
	int		in_sphere;

	in_sphere = 0;
	discriminant = rt_calcul_sphere(ray, sp, res);
	if (discriminant < 0.0)
		return (0);
	dprintf(2, "d%.2f\n", discriminant);
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

bool	rt_check_inter_plane(t_ray *ray, t_object *pl, int crea)
{
	float	a;

	a = rt_dot_prod(*pl->dir, ray->dir);
	if (a < 0.0)
		return (0);
	return (rt_inter_plane(ray, pl, crea));
}
