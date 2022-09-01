#include <mini_rt.h>

bool	rt_in_shadow(t_obj_data *obj_data, t_ray *ray)
{
	size_t	n;
	int 	i;
	bool	(*fctHit[2])(t_ray*, t_object*, int);

	fctHit[0] = &rt_inter_sphere;
	fctHit[1] = &rt_inter_plane;
	//fctHit[2] = &rt_inter_cylinder;
	n = -1;
	while (++n < obj_data->lst_size)
	{
		i = 0;
		while (++i <= 2)
		{
			if (i == obj_data->objects[n]->id)
				if ((*fctHit[i - 1])(ray, obj_data->objects[n], 0))
					return (1);
		}
	}
	return (0);
}	