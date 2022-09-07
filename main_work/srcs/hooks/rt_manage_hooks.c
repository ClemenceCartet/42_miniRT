/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_manage_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:56:26 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/07 13:13:34 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Exit the program completely, it's sad to call this function :c
int	rt_exit_program(t_master *master)
{
	mlx_clear_window(master->init, master->wdw);
	mlx_destroy_window(master->init, master->wdw);
	rt_free_master(master);
	exit(0);
	return (0);
}

//Will call the appropriate function depending on the key pressed for objects
static void	rt_object_hook_hub(int key, t_master *master)
{
	static int	object = -1;
	static int	axis = -1;
	static int	obj_size = -1;

	if (key == K_LEFT || key == K_RIGHT)
		object = rt_update_selected_object(key, master, object);
	else if (key == K_X || key == K_Y || key == K_Z)
		axis = rt_update_selected_axis(key);
	else if (key == K_T)
		obj_size = rt_update_selected_size(obj_size);
	else if (key == K_UP || key == K_DOWN)
		rt_update_obj_pos(key, master, object, axis);
	else if (key == PV_PLUS || key == PV_MINUS)
		rt_update_obj_size(key, master, object, obj_size);
	else if (key == PV_8 || key == PV_2)
		rt_update_light_pos(key, master, axis);
}

//Will call the appropriate function depending on the key pressed for camera
static void	rt_camera_hook_hub(int key, t_master *master)
{
	if (key == K_W || key == K_S || key == K_A || key == K_D
		|| key == K_Q || key == K_E)
		rt_update_camera_pos(key, master);
	else if (key == K_I || key == K_K || key == K_J || key == K_L)
		rt_update_camera_dir(key, master);
}

//Will call all hub function to check which function to use
int	rt_key_hook_hub(int key, t_master *master)
{
	if (key == K_ESC)
		rt_exit_program(master);
	else
	{
		rt_camera_hook_hub(key, master);
		rt_object_hook_hub(key, master);
		rt_display_scene(master);
	}
	return (0);
}
