#include <mini_rt.h>

//vec3 result = (ambient + diffuse) * objectColor;

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
	refl_vec = rt_add_vec(l_to_p_vec, rt_scale_vec(ray.normal, angle)); 
	rt_norm_vector(&refl_vec);
	l_spec = light->ratio * rt_dot_prod(refl_vec, rt_scale_vec(ray.dir, -1));
	if (l_spec < 0)
		l_spec = 0;
	return (l_spec);
}	

t_color	rt_set_spot_light(t_ray ray, t_light *light)
{
	float	l_dif;
	float	l_spec;
	//float	l_intensity;
	//float	l_power;
	t_coord	p_to_l_vec; // hit point to light
	float 	angle;
	t_color	spot;

	p_to_l_vec = rt_sub_vec(*light->pos, ray.hit);
	rt_norm_vector(&p_to_l_vec);
	angle = rt_dot_prod(ray.normal, p_to_l_vec);
	l_dif = rt_diffuse_light(light, angle); 
	l_spec = rt_specular_light(light, angle, ray);
	//l_intensity = light->ratio / (4 * M_PI * pow(rt_dot_prod(*light->pos, ray.hit), 2));
	//l_power = (l_dif +l_spec) - l_intensity;
	spot = rt_scale_color(ray.color, l_dif + l_spec);
	return (spot);
}

t_color	rt_set_color(t_ray ray, t_master *master)
{
	t_color	l_amb;
	t_color	l_spot;
	t_color color;

	l_amb = rt_set_ambient_light(ray, master->ambient);
	// parcourir liste chainée des lumières
	l_spot = rt_set_spot_light(ray, master->light);
	color = rt_add_color(l_amb, l_spot);
	return (color);
}
