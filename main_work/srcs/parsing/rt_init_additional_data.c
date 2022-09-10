/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_additional_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:43:28 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/10 13:40:31 by ccartet          ###   ########.fr       */
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
	(*cam)->focal = WIDTH / (2 * tan((*cam)->radian * 0.5));
}

//Object additional data initialization (SP / PL / CY)
void	rt_init_add_object(t_object **object)
{
	t_coord	scale;

	(*object)->radius = 0.0;
	(*object)->cypos.x = 0.0;
	(*object)->cypos.y = 0.0;
	(*object)->cypos.z = 0.0;
	(*object)->cydir.x = 0.0;
	(*object)->cydir.y = 0.0;
	(*object)->cydir.z = 0.0;
	if ((*object)->id == SP || (*object)->id == CY)
		(*object)->radius = (*object)->diameter * 0.5;
	if ((*object)->id == CY)
	{
		scale = rt_scale_vec(*(*object)->dir, (*object)->height);
		(*object)->cypos = rt_add_vec(*(*object)->pos, scale);
		(*object)->cydir.x = -(*object)->dir->x;
		(*object)->cydir.y = -(*object)->dir->y;
		(*object)->cydir.z = -(*object)->dir->z;
	}
}

//Master additional data initialization
int	rt_init_additional_data(t_master *master)
{
	int	a;

	a = 0;
	master->mlx = ft_calloc(1, sizeof(t_mlx_data));
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
		master->obj_data->objects[a]->selected = 0;
		a++;
	}
	master->obj_data->fct[0] = &rt_inter_sphere;
	master->obj_data->fct[1] = &rt_inter_plane;
	master->obj_data->fct[2] = &rt_inter_cylinder_bis;
	return (0);
}
