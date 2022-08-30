#include <mini_rt.h>

//vec3 result = (ambient + diffuse) * objectColor;

t_color	rt_add_color(t_color c1, t_color c2)
{
	t_color	new;

	new.r = c1.r + c2.r;
	if (new.r > 255)
		new.r = 255;
	new.g = c1.g + c2.g;
	if (new.g > 255)
		new.g = 255;
	new.b = c1.b + c2.b;
	if (new.b > 255)
		new.b = 255;
	return (new);
}

t_color	rt_scale_color(t_color c1, float r)
{
	t_color	new;

	new.r = c1.r * r;
	if (new.r > 255)
		new.r = 255;
	new.g = c1.g * r;
	if (new.g > 255)
		new.g = 255;
	new.b = c1.b * r;
	if (new.b > 255)
		new.b = 255;
	return (new);
}

t_color	set_ambient_light(t_ray ray, t_ambient *ambient)
{
	t_color	l_amb;

	l_amb.r = (ambient->rgb->r * ambient->ratio) * ray.color.r;
	l_amb.g = (ambient->rgb->g * ambient->ratio) * ray.color.g;
	l_amb.b = (ambient->rgb->b * ambient->ratio) * ray.color.b;
	return (l_amb);
}

float	diffuse_light(t_light *light, float angle)
{
	float	l_dif;

	l_dif = light->ratio * angle;
	if (l_dif < 0)
		l_dif = 0;
	return (l_dif);
}	

float	specular_light(t_light *light, float angle, t_ray ray)
{
	float	l_spec;
	t_coord	refl_vec;
	t_coord	l_to_p_vec;

	l_to_p_vec = rt_sub_vec(ray.hit, *light->pos);
	refl_vec = rt_add_vec(l_to_p_vec, rt_scale_vec(ray.normal, 2 * angle)); 
	norm_vector(&refl_vec);
	l_spec = light->ratio * rt_dot_prod(refl_vec, rt_scale_vec(ray.dir, -1));
	if (l_spec < 0)
		l_spec = 0;
	return (l_spec);

}	

t_color	set_spot_light(t_ray ray, t_light *light)
{
	float	l_dif;
	float	l_spec;
	t_coord	p_to_l_vec; // hit point to light
	float 	angle;
	t_color	spot;

	p_to_l_vec = rt_sub_vec(*light->pos, ray.hit);
	norm_vector(&p_to_l_vec);
	angle = rt_dot_prod(ray.normal, p_to_l_vec);
	l_dif = diffuse_light(light, angle); 
	l_spec = specular_light(light, angle, ray);
	spot = rt_add_color(rt_scale_color(ray.color, l_dif), rt_scale_color(ray.color, l_spec));
	return (spot);
}

t_color	set_color(t_ray ray, t_master *master)
{
	t_color	l_amb;
	t_color	l_spot;
	t_color color;

	l_amb = set_ambient_light(ray, master->ambient);
	// parcourir liste chainée des lumières
	l_spot = set_spot_light(ray, master->light);
	color = rt_add_color(l_amb, l_spot);
	dprintf(2, "%d\n", color.r);
	return (color);
}
