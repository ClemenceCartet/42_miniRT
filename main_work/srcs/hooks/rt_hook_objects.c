/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hook_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:35:44 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/07 11:56:49 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Move the corresponding object on the axis given one way or the other
void	rt_update_obj_pos(int key, t_master *master, int object, int axis)
{
	if (axis == -1 || object == -1)
		return ;
	else
	{
		if (key == K_UP)
		{
			if (axis == AXIS_X)
				master->obj_data->objects[object]->pos->x += 0.2;
			else if (axis == AXIS_Y)
				master->obj_data->objects[object]->pos->y += 0.2;
			else if (axis == AXIS_Z)
				master->obj_data->objects[object]->pos->z += 0.2;
		}
		else if (K_DOWN)
		{
			if (axis == AXIS_X)
				master->obj_data->objects[object]->pos->x -= 0.2;
			else if (axis == AXIS_Y)
				master->obj_data->objects[object]->pos->y -= 0.2;
			else if (axis == AXIS_Z)
				master->obj_data->objects[object]->pos->z -= 0.2;
		}
	}
}

//Move the light object on the axis given one way or the other
void	rt_update_light_pos(int key, t_master *master, int axis)
{
	if (axis == -1)
		return ;
	else
	{
		if (key == PV_8)
		{
			if (axis == AXIS_X)
				master->light->pos->x += 0.2;
			else if (axis == AXIS_Y)
				master->light->pos->y += 0.2;
			else if (axis == AXIS_Z)
				master->light->pos->z += 0.2;
		}
		else if (key == PV_2)
		{
			if (axis == AXIS_X)
				master->light->pos->x -= 0.2;
			else if (axis == AXIS_Y)
				master->light->pos->y -= 0.2;
			else if (axis == AXIS_Z)
				master->light->pos->z -= 0.2;
		}
	}
}

//change the size depending on its value and the key pressed
static float	rt_update_size(int key, float size)
{
	if (key == PV_MINUS)
	{
		if (size >= 0.2)
			return (size - 0.2);
		else
			return (0.0);
	}
	else if (key == PV_PLUS)
		return (size + 0.2);
	return (size);
}

//Change either Diameter or Height depending on selected obj_size and object ID
void	rt_update_obj_size(int key, t_master *master, int object, int obj_size)
{
	if (obj_size == SIZE_D)
		master->obj_data->objects[object]->diameter = rt_update_size(key,
				master->obj_data->objects[object]->diameter);
	else if (obj_size == SIZE_H)
	{
		if (master->obj_data->objects[object]->id == CY)
			master->obj_data->objects[object]->height = rt_update_size(key,
					master->obj_data->objects[object]->height);
	}
	rt_init_add_object(&master->obj_data->objects[object]);
}
