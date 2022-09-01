#include <mini_rt.h>

bool	rt_hit_plane(t_coord vec, t_object *pl)
{
	float	a;
	float	b;
	float	time;

	a = rt_dot_prod(*pl->dir, vec);
	b = rt_dot_prod(*pl->dir, rt_sub_vec(*pl->pos, ray->origin));
	time = b / a;
	if (time <= 0.0)
		return (0);
	if (ray->time == 0.0 || time < ray->time)
		ray->time = time;
	else
		return (0);
	rt_set_hit_point(ray);
	ray->color = *pl->rgb;
	if (time > 25.0)
	{
		ratio = 25.0 / time;
		ray->color = rt_scale_color(*pl->rgb, ratio);
	}
	ray->normal = *pl->dir;
	return (1);
}

bool	rt_in_shadow(t_coord vec, t_obj_data *obj_data)
{
	size_t	n;
	int 	i;
	bool	(*fctHit[3])(t_ray*, t_object*);
	int		ret;

	ret = 0;
	fctHit[0] = &rt_hit_sphere;
	fctHit[1] = &rt_hit_plane;
	fctHit[2] = &rt_hit_cylinder;
	n = 0;
	while (n < obj_data->lst_size)
	{
		i = 1;
		while (i <= 3)
		{
			if (i == obj_data->objects[n]->id)
				if ((*fctHit[i - 1])(vec, obj_data->objects[n]))
					ret = 1;
			i++;
		}
		n++;
	}
	return (ret);

}
