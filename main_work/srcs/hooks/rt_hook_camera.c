/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hook_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:45:57 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/13 16:53:00 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Move the camera forward, backward, left or right depending on the key pressed
void	rt_update_camera_pos(int key, t_master *master)
{
	float	move;

	move = 0;
	if (key == K_W)
		move += 0.25;
	else if (key == K_S)
		move -= 0.25;
	master->camera->pos->x += master->camera->dir->x * move;
	master->camera->pos->y += master->camera->dir->y * move;
	master->camera->pos->z += master->camera->dir->z * move;
}

//Turn the camera angle up, down, left or right depending on the key pressed
void	rt_update_camera_dir(int key, t_master *master)
{
	t_matrix	newm_y;
	t_matrix	newm_x;
	t_matrix	newm;
	float		ud_angle;
	float		lr_angle;

	ud_angle = 0;
	lr_angle = 0;
	if (key == K_I) //haut
		ud_angle += 0.1;
	else if (key == K_K) //bas
		ud_angle -= 0.1;
	else if (key == K_J) //gauche
		lr_angle += 0.1;
	else if (key == K_L) //droite
		lr_angle -= 0.1;
	dprintf(1, "before : x = %f | y = %f | z = %f\n", master->camera->dir->x, master->camera->dir->y, master->camera->dir->z);
	newm_y = rt_matrix_rot_x(ud_angle);
	newm_x = rt_matrix_rot_y(lr_angle);
	newm = rt_multiply_matrix(newm_x, newm_y);
	*master->camera->dir = rt_multiply_matrix_vector(newm, *master->camera->dir);
	// *master->camera->dir = rt_multiply_matrix_vector(newm_y, *master->camera->dir);
	// *master->camera->dir = rt_multiply_matrix_vector(newm_x, *master->camera->dir);
	dprintf(1, "after : x = %f | y = %f | z = %f\n", master->camera->dir->x, master->camera->dir->y, master->camera->dir->z);
}
