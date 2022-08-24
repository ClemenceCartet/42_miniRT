/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_additional_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:43:28 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/24 14:40:45 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	rt_init_focal(t_camera *cam)
{
	cam->focal = W / (2 * tan(cam->radian * 0.5));
	//cam->focal = (cos(cam->radian * 0.5) / sin(cam->radian * 0.5)) / H;
	// dprintf(2, "%f, %f\n", cam->radian, cam->focal);
}

//Object table initialization from linked list of obj_data
t_object	**rt_init_object_tab(t_obj_data *obj_data)
{
	t_object	**objects;
	size_t		a;

	a = 0;
	objects = malloc(sizeof(t_object *) * (obj_data->lst_size + 1));
	if (!objects)
		return (NULL);
	obj_data->lst = obj_data->start;
	while (a < obj_data->lst_size)
	{
		objects[a] = obj_data->lst->content;
		obj_data->lst = obj_data->lst->next;
		a++;
	}
	objects[a] = NULL;
	return (objects);
}
