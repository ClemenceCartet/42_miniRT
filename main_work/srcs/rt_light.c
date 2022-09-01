#include <mini_rt.h>

t_color	rt_set_ambient_light(t_ray ray, t_ambient *ambient)
{
	t_color	amb_color;
	t_color	l_amb;
	
	amb_color = rt_scale_color(*ambient->rgb, ambient->ratio);
	l_amb = rt_reflt_color(amb_color, ray.color);
	//dprintf(2, "%.2f, %.2f, %.2f\n", l_amb.r, l_amb.g, l_amb.b);
	return (l_amb);
}

float	rt_diffuse_light(t_light *light, float angle)
{
	float	l_dif;

	l_dif = light->ratio * angle;
	if (l_dif < 0)
		l_dif = 0;
	return (l_dif);
}	

float	rt_specular_light(t_light *light, float angle, t_ray ray)
{
	float	l_spec;
	t_coord	refl_vec;
	t_coord	l_to_p_vec;

	l_to_p_vec = rt_sub_vec(ray.hit, *light->pos);
	rt_norm_vector(&l_to_p_vec);
	refl_vec = rt_add_vec(l_to_p_vec, rt_scale_vec(ray.normal, angle * 1.0)); 
	rt_norm_vector(&refl_vec);
	l_spec = light->ratio * rt_dot_prod(refl_vec, rt_scale_vec(ray.dir, -1));
	if (l_spec < 0)
		l_spec = 0;
	return (l_spec);
}	

t_color	rt_set_point_light(t_ray ray, t_light *light, t_coord l_vec)
{
	float	l_dif;
	//float	l_spec;
	float	l_bright;
	float 	angle;
	t_color	spot;

	angle = rt_dot_prod(ray.normal, l_vec);
	l_dif = rt_diffuse_light(light, angle); 
	//l_spec = rt_specular_light(light, angle, ray);
	l_bright = light->ratio / (M_PI * rt_vector_length_sqr(l_vec));
	spot = rt_scale_color(ray.color, l_dif * l_bright);
	return (spot);
}

t_color	rt_set_color(t_ray ray, t_master *master)
{
	t_color	l_vec;
	t_color	l_amb;
	t_color	l_spot;
	t_color color;

	l_vec = rt_sub_vec(*light->pos, ray.hit);
	rt_norm_vector(&l_vec);
	l_amb = rt_set_ambient_light(ray, master->ambient);
	// parcourir liste chainée des lumières
	if (rt_in_shadow(l_vec, master->obj_data))
		color = l_amb;
	else
	{
		l_spot = rt_set_point_light(ray, master->light, l_vec);
		color = rt_add_color(l_amb, l_spot);
	}
	return (color);
}
