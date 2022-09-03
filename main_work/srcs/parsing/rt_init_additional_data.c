/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_additional_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:43:28 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/03 12:00:39 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Object table initialization from linked list of obj_data
static t_object	**rt_init_object_tab(t_obj_data *obj_data)
{
	t_object	**objects;
	size_t		a;

	a = 0;
	objects = malloc(sizeof(t_object *) * (obj_data->lst_size + 1));
	if (!objects)
		return (rt_write_ptr_error(E_MALLOC, NULL, DFI, DLI));
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

//Camera additional data initialization (C)
static void	rt_init_add_camera(t_camera **cam)
{
	(*cam)->radian = (*cam)->fov * M_PI / 180;
	(*cam)->focal = W / (2 * tan((*cam)->radian * 0.5));
}

//Object additional data initialization (SP / PL / CY)
static void	rt_init_add_object(t_object **object)
{
	if ((*object)->id == SP || (*object)->id == CY)
		(*object)->radius = (*object)->diameter * 0.5;
	else
		(*object)->radius = 0;
}

//Master additional data initialization
int	rt_init_additional_data(t_master *master)
{
	int	a;

	a = 0;
	master->mlx = malloc(sizeof(t_mlx_data));
	if (!master->mlx)
		return (rt_write_int_error(E_MALLOC, NULL, DFI, DLI));
	master->obj_data->objects = rt_init_object_tab(master->obj_data);
	if (!master->obj_data->objects)
		return (1);
	master->obj_data->lst = master->obj_data->start;
	rt_init_add_camera(&master->camera);
	while (master->obj_data->objects[a])
	{
		rt_init_add_object(&master->obj_data->objects[a]);
		a++;
	}
	return (0);
}
