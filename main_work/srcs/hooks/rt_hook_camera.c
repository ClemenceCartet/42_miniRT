/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hook_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:45:57 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/11 11:44:05 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Move the camera forward, backward, left or right depending on the key pressed
void	rt_update_camera_pos(int key, t_master *master)
{
	if (key == K_W)
		master->camera->pos->z += 0.1;
	else if (key == K_A)
		master->camera->pos->x -= 0.1;
	else if (key == K_S)
		master->camera->pos->z -= 0.1;
	else if (key == K_D)
		master->camera->pos->x += 0.1;
	else if (key == K_E)
		master->camera->pos->y += 0.1;
	else if (key == K_Q)
		master->camera->pos->y -= 0.1;
}

//Turn the camera angle up, down, left or right depending on the key pressed
void	rt_update_camera_dir(int key, t_master *master)
{
	if (key == K_I)
		master->camera->dir->x += 0.01;
	else if (key == K_J)
		master->camera->dir->y += -0.01;
	else if (key == K_K)
		master->camera->dir->x += -0.01;
	else if (key == K_L)
		master->camera->dir->y += 0.01;
	else if (key == K_U)
		master->camera->dir->z += -0.01;
	else if (key == K_O)
		master->camera->dir->z += 0.01;
	*master->camera->dir = rt_matrix_rotate(*master->camera->dir);
}
