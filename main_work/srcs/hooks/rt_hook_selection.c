/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hook_selection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:09:06 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/07 14:17:12 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Set selected value of all objects to 0
static void	rt_reset_object_selection(t_master *master)
{
	int	a;

	a = 0;
	while (master->obj_data->objects[a])
	{
		master->obj_data->objects[a]->selected = 0;
		a++;
	}
}

//Iterate through the object list with left and right key press
int	rt_update_selected_object(int key, t_master *master, int object)
{
	rt_reset_object_selection(master);
	if (key == K_LEFT)
	{
		if (object == -1 || object == 0)
			return (master->obj_data->lst_size - 1);
		else
			return (object - 1);
	}
	else if (key == K_RIGHT)
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

//Select Diameter value or Height value depending on which state obj_size is
int	rt_update_selected_size(int obj_size)
{
	if (obj_size == -1)
		return (SIZE_D);
	else if (obj_size == SIZE_D)
		return (SIZE_H);
	else if (obj_size == SIZE_H)
		return (SIZE_D);
	return (-1);
}
