/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_manage_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:56:26 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/03 12:00:02 by ljohnson         ###   ########lyon.fr   */
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

// void	move_object(int key, t_master *master)
// {
// 	float	ratio;
// 	int		i;

// 	i = 0;
// 	if (key == K_UP || key == K_RIGHT)
// 	{
// 		ratio = 0.2;
// 		master->obj_data->objects[1]->pos->z += 0.2;
// 		master->obj_data->objects[2]->pos->z += 0.2;
// 		master->obj_data->objects[3]->pos->z += 0.2;
// 	}
// 	else
// 		ratio = -0.2;
// 	while (master->obj_data->objects[i])
// 	{
// 		if (key == K_UP || key == K_DOWN)
// 			master->obj_data->objects[i]->pos->z += ratio;
// 		else
// 			master->obj_data->objects[i]->pos->x += ratio;
// 		i++;
// 	}
// }
	// if (key == K_UP || key == K_DOWN || key == K_LEFT || key == K_RIGHT)
	// 	move_object(key, master);

void	rt_update_camera_pos(int key, t_master *master)
{
	if (key == K_W)
		master->camera->pos->z += 0.1;
	else if (key == K_S)
		master->camera->pos->z -= 0.1;
	else if (key == K_A)
		master->camera->pos->x -= 0.1;
	else if (key == K_D)
		master->camera->pos->x += 0.1;
}

void	rt_update_camera_dir(int key, t_master *master)
{
	if (key == K_I)
		master->camera->dir->y += 0.2;
	else if (key == K_K)
		master->camera->dir->y += -0.2;
	else if (key == K_J)
		master->camera->dir->x += -0.2;
	else if (key == K_L)
		master->camera->dir->x += 0.2;
}

int	key_hook(int key, t_master *master)
{
	if (key == K_ESC)
		exit_x(master);
	else
	{
		if (key == K_W || key == K_S || key == K_A || key == K_D)
			rt_update_camera_pos(key, master);
		if (key == K_I || key == K_K || key == K_J || key == K_L)
			rt_update_camera_dir(key, master);
		rt_display_scene(master);
	}
	return (0);
}
