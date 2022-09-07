/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hook_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:35:44 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/04 18:02:59 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Iterate through the object list with left and right key press
int	rt_update_selected_object(int key, t_master *master, int object)
{
	if (key == K_LEFT)
	{
		if (object == -1 || object == 0)
			return (master->obj_data->lst_size - 1);
		else
			return (object - 1);
	}
	else
	{
		if (object == -1 || object == (int)(master->obj_data->lst_size - 1))
			return (0);
		else
			return (object + 1);
	}
	return (-1);
}

//Select an axis depending on which key is pressed
int	rt_update_selected_axis(int key)
{
	if (key == K_X)
		return (AXIS_X);
	else if (key == K_Y)
		return (AXIS_Y);
	else if (key == K_Z)
		return (AXIS_Z);
	return (-1);
}

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
		else
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

//wip function
void	rt_update_object_size(int key, t_master *master, int object)
{
	key = 0;
	(void)master;
	object = 0;
	return ;
}
