/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hook_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:45:57 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/15 10:44:37 by ccartet          ###   ########.fr       */
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
	*master->camera->pos = rt_add_vec(*master->camera->pos,
			rt_scale_vec(*master->camera->dir, move));
}

//Turn the camera angle up, down, left or right depending on the key pressed
void	rt_update_camera_dir(int key, t_master *master)
{
	float	ud_angle;
	float	lr_angle;
	t_matrix		newm_y;
	t_matrix		newm_x;

	ud_angle = 0.0;
	lr_angle = 0.0;
	if (key == K_I)
		ud_angle = -(10 * M_PI / 180);
	else if (key == K_K)
		ud_angle = (10 * M_PI / 180);
	else if (key == K_J)
		lr_angle = (10 * M_PI / 180);
	else if (key == K_L)
		lr_angle = -(10 * M_PI / 180);
	newm_y = rt_matrix_rot_x(ud_angle);
	newm_x = rt_matrix_rot_y(lr_angle);
	master->camera->rotate = rt_multiply_matrix(newm_y, newm_x);
	*master->camera->dir = rt_multiply_matrix_vector(master->camera->rotate,
			*master->camera->dir);
}
