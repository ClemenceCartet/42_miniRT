/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_manage_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:56:26 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/04 16:41:40 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	exit_x(t_master *master)
{
	mlx_clear_window(master->init, master->wdw);
	mlx_destroy_window(master->init, master->wdw);
	rt_free_master(master);
	exit(0);
	return (0);
}

// void	rt_update_camera_pos(int key, t_master *master)
// {
// 	if (key == K_W)
// 		master->camera->pos->z += 0.1;
// 	else if (key == K_S)
// 		master->camera->pos->z -= 0.1;
// 	else if (key == K_A)
// 		master->camera->pos->x -= 0.1;
// 	else if (key == K_D)
// 		master->camera->pos->x += 0.1;
// }

// void	rt_update_camera_dir(int key, t_master *master)
// {
// 	if (key == K_I)
// 		master->camera->dir->y += 0.2;
// 	else if (key == K_K)
// 		master->camera->dir->y += -0.2;
// 	else if (key == K_J)
// 		master->camera->dir->x += -0.2;
// 	else if (key == K_L)
// 		master->camera->dir->x += 0.2;
// }

static int	rt_update_selected_object(int key, t_master *master, int object)
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

static int	rt_update_selected_axis(int key)
{
	if (key == K_X)
		return (AXIS_X);
	else if (key == K_Y)
		return (AXIS_Y);
	else if (key == K_Z)
		return (AXIS_Z);
	return (-1);
}

static void	rt_update_obj_pos(int key, t_master *master, int object, int axis)
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

int	key_hook(int key, t_master *master)
{
	static int	object = -1;
	static int	axis = -1;

	if (key == K_ESC)
		exit_x(master);
	else
	{
		// if (key == K_W || key == K_S || key == K_A || key == K_D)
		// 	rt_update_camera_pos(key, master);
		// else if (key == K_I || key == K_K || key == K_J || key == K_L)
		// 	rt_update_camera_dir(key, master);
		if (key == K_LEFT || key == K_RIGHT)
			object = rt_update_selected_object(key, master, object);
		else if (key == K_X || key == K_Y || key == K_Z)
			axis = rt_update_selected_axis(key);
		else if (key == K_UP || key == K_DOWN)
			rt_update_obj_pos(key, master, object, axis);
		// else if (key == PV_PLUS || key == PV_MINUS)
		// 	rt_update_object_size(key, master, object);
		rt_display_scene(master);
	}
	return (0);
}
