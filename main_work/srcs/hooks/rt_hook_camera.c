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

//Turn the camera angle up, down, left or right depending on the key pressed
void	rt_update_camera(int key, t_master *master)
{
	float			move;
	static float	ud_angle;
	static float	lr_angle;

	move = 0;
	if (key == K_W)
		move += 0.25;
	else if (key == K_S)
		move -= 0.25;
	else if (key == K_I) //haut
		ud_angle -= 0.1;
	else if (key == K_K) //bas
		ud_angle += 0.1;
	else if (key == K_J) //gauche
		lr_angle += 0.1;
	else if (key == K_L) //droite
		lr_angle -= 0.1;
	//dprintf(1, "before : x = %f | y = %f | z = %f\n", master->camera->pos->x, master->camera->pos->y, master->camera->pos->z);
	master->camera->mat_rot = rt_multiply_matrix(rt_matrix_rot_x(ud_angle),
		rt_matrix_rot_y(lr_angle));
	*master->camera->dir = rt_multiply_matrix_vector(master->camera->mat_rot, *master->camera->dir);
	*master->camera->pos = rt_add_vec(*master->camera->pos, rt_scale_vec(*master->camera->dir, move));
	//dprintf(1, "after : x = %f | y = %f | z = %f\n", master->camera->pos->x, master->camera->pos->y, master->camera->pos->z);
}
