#include <mini_rt.h>

t_color	rt_set_ambient_light(t_color hit_color, t_ambient *ambient)
{
	t_color	amb_color;
	t_color	l_amb;
	
	amb_color = rt_scale_color(*ambient->rgb, ambient->ratio);
	l_amb = rt_reflt_color(amb_color, hit_color);
	//dprintf(2, "%.2f, %.2f, %.2f\n", l_amb.r, l_amb.g, l_amb.b);
	return (l_amb);
}

t_color	rt_set_point_light(t_hit hit, t_light *light, t_coord l_dir)
{
	float 	angle;
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
	t_color color;
	int		l_intensity;

	l_intensity = 1;
	l_ray.dir = rt_sub_vec(hit.point, *master->light->pos);
	l_ray.origin = *master->light->pos;
	l_amb = rt_set_ambient_light(hit.color, master->ambient);
	l_point = rt_set_point_light(hit, master->light, l_ray.dir);
	if (rt_in_shadow(master->obj_data, l_ray, hit))
		l_intensity = 0;
	l_point = rt_scale_color(l_point, l_intensity);
	color = rt_add_color(l_amb, l_point);
	return (color);
}

bool	rt_in_shadow(t_obj_data *obj_data, t_ray l_ray, t_hit hit)
{
	t_ray	shadow;
	size_t	n;
	int 	i;
	bool	(*fctHit[2])(t_ray*, t_object*, int);

	fctHit[0] = &rt_check_inter_sphere;
	fctHit[1] = &rt_check_inter_plane;
	//fctHit[2] = &rt_inter_cylinder;
	shadow.dir = rt_scale_vec(l_ray.dir, -1);
	rt_norm_vector(&shadow.dir);
	shadow.origin = rt_add_vec(hit.point, rt_scale_vec(hit.normal, 0.001));
	n = -1;
	while (++n < obj_data->lst_size)
	{
		i = 0;
		while (++i <= 2)
		{
			if (i == obj_data->objects[n]->id)
				if ((*fctHit[i - 1])(&shadow, obj_data->objects[n], 0))
					return (1);
		}
	}
	return (0);
}
