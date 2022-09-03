/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_bn_hit_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:12:13 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/03 09:37:43 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	rt_init_square(t_object *sq)
{
	t_coord	x;
	t_coord	u;
	t_coord	v;

	x.x = 1.0;
	x.y = 0.0;
	x.z = 0.0;
	// trouver les deux autres vecteurs perpendiculaires à sq->dir
	u = rt_cross_vec(*sq->dir, x);
	if (!rt_vec_length_sqr(u))
		u.y = 1.0;
	v = rt_cross_vec(u, *sq->dir);
	// modifier les vecteurs à la taille souhaitée
	u = rt_scale_vec(u, 2);
	v = rt_scale_vec(v, 4);
	// trouver les 4 coins du rectangle
	sq->c[0] = rt_add_vec(rt_add_vec(*sq->pos, u), v);
	sq->c[1] = rt_sub_vec(rt_add_vec(*sq->pos, u), v);
	sq->c[2] = rt_add_vec(rt_sub_vec(*sq->pos, u), v);
	sq->c[3] = rt_sub_vec(rt_sub_vec(*sq->pos, u), v);
	// mesurer les 4 côtés du rectangle
	sq->gap[0] = rt_sub_vec(sq->c[0], sq->c[1]);
	sq->gap[1] = rt_sub_vec(sq->c[3], sq->c[1]);
	sq->gap[2] = rt_sub_vec(sq->c[2], sq->c[0]);
	sq->gap[3] = rt_sub_vec(sq->c[2], sq->c[3]);
}	

bool	rt_in_square(t_coord p, t_object *sq)
{
	t_coord	g[4];

	// trouver la distance entre notre point et chacun des coins du rectangle
	g[0] = rt_sub_vec(sq->c[0], p);
	g[1] = rt_sub_vec(p, sq->c[1]);
	g[2] = rt_sub_vec(sq->c[2], p);
	g[3] = rt_sub_vec(p, sq->c[3]);
	// trouver la normale de ces deux vecteurs de distance et la comparer avec la normale du rectangle
	if (rt_dot_prod(*sq->dir, rt_cross_vec(sq->gap[0], g[0])) >= 0
		&& rt_dot_prod(*sq->dir, rt_cross_vec(sq->gap[1], g[1])) >= 0
		&& rt_dot_prod(*sq->dir, rt_cross_vec(sq->gap[2], g[2])) >= 0
		&& rt_dot_prod(*sq->dir, rt_cross_vec(sq->gap[3], g[3])) >= 0)
		return (1);
	return (0);
}

bool	rt_inter_square(t_ray *ray, t_object *sq)
{
	float	a;
	float	b;
	float	time;

	a = rt_dot_prod(*sq->dir, ray->dir);
	b = rt_dot_prod(*sq->dir, rt_sub_vec(*sq->pos, ray->origin));
	time = b / a;
	if (time <= 0.0)
		return (0);
	if (ray->inter == 0 || time < ray->hit.time)
		ray->hit.time = time;
	else
		return (0);
	ray->inter = 1;
	rt_set_hit_point(ray);
	if (!rt_in_square(ray->hit.point, sq))
		return (0);
	ray->hit.normal = *sq->dir;
	ray->hit.color = *sq->rgb;
	ray->hit.obj = sq;
	return (1);
}
