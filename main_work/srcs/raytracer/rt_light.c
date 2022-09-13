/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:12:35 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/12 14:54:07 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

t_color	ft_skybox_color(t_ambient amb, t_coord v)
{
	t_color	color;

	ft_memset(&color, 0, sizeof(t_color));
	if (fabs(v.x) >= fabs(v.y) && fabs(v.x) >= fabs(v.z))
		color.r = ((v.x + 1) / 2.0) * amb.rgb->r
			* amb.ratio;
	if (fabs(v.y) >= fabs(v.x) && fabs(v.y) >= fabs(v.z))
		color.g = ((v.y + 1) / 2.0) * amb.rgb->g
			* amb.ratio;
	if (fabs(v.z) >= fabs(v.x) && fabs(v.z) >= fabs(v.y))
		color.b = ((v.z + 1) / 2.0) * amb.rgb->b
			* amb.ratio;
	return (color);
}


t_color	rt_set_ambient_light(t_color hit_color, t_ambient *ambient)
{
	t_color	amb_color;
	t_color	l_amb;

	amb_color = rt_scale_color(*ambient->rgb, ambient->ratio);
	l_amb = rt_reflt_color(amb_color, hit_color);
	return (l_amb);
}

t_color	rt_set_point_light(t_hit hit, t_light *light, t_coord l_dir)
{
	float	angle;
	float	l_dif;
	float	l_bright;
	t_color	spot;

	angle = rt_dot_prod(hit.normal, rt_scale_vec(l_dir, -1));
	l_dif = light->ratio * angle;
	if (l_dif < 0)
		l_dif = 0;
	l_bright = l_dif / rt_vec_length_sqr(l_dir);
	spot = rt_scale_color(hit.color, l_bright);
	return (spot);
}

t_color	rt_set_color(t_hit hit, t_master *master)
{
	t_ray	l_ray;
	t_color	l_amb;
	t_color	l_point;
	t_color	color;
	int		l_intensity;

	l_intensity = 1;
	l_ray.dir = rt_sub_vec(hit.point, *master->light->pos);
	l_ray.origin = *master->light->pos;
	l_amb = rt_set_ambient_light(hit.color, master->ambient);
	l_point = rt_set_point_light(hit, master->light, l_ray.dir);
	//if (rt_in_shadow(master->obj_data, &l_ray, hit))
	//	l_intensity = 0;
	l_point = rt_scale_color(l_point, l_intensity);
	color = rt_add_color(l_amb, l_point);
	return (color);
}

bool	rt_in_shadow(t_obj_data *obj_data, t_ray *l_ray, t_hit hit)
{
	size_t		n;
	int			i;
	float		dist;
	float		time;
	t_coord		new_hit;

	time = -1;
	new_hit = rt_add_vec(hit.point, rt_scale_vec(hit.normal, 0.0001));
	l_ray->dir = rt_sub_vec(new_hit, l_ray->origin);
	dist = rt_vector_length(l_ray->dir);
	rt_norm_vector(&l_ray->dir);
	n = -1;
	while (++n < obj_data->lst_size)
	{
		i = 0;
		while (++i <= 3)
		{
			if (i == obj_data->objects[n]->id)
				time = obj_data->fct[i - 1](l_ray, obj_data->objects[n]);
			if (time != -1 && time < dist)
				return (1);
		}
	}
	return (0);
}
