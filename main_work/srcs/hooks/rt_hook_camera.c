/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hook_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:45:57 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/09 13:43:33 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//rotation haut/bas
static void	rot_x(t_matrix *mat, float rot, int isradian)
{
	if (isradian)
		rot = rot * 180 / M_PI;
	mat->x.x = 1;
	mat->x.y = 0;
	mat->x.z = 0;
	mat->y.x = 0;
	mat->y.y = cos(rot);
	mat->y.z = sin(rot);
	mat->z.x = 0;
	mat->z.y = asin(rot);
	mat->z.z = cos(rot);
}

//rotation gauche/droite
static void	rot_y(t_matrix *mat, float rot, int isradian)
{
	if (isradian)
		rot = rot * 180 / M_PI;
	mat->x.x = cos(rot);
	mat->x.y = 0;
	mat->x.z = asin(rot);
	mat->y.x = 0;
	mat->y.y = 1;
	mat->y.z = 0;
	mat->z.x = sin(rot);
	mat->z.y = 0;
	mat->z.z = cos(rot);
}

//tangage gauche/droite
static void	rot_z(t_matrix *mat, float rot, int isradian)
{
	if (isradian)
		rot = rot * 180 / M_PI;
	mat->x.x = cos(rot);
	mat->x.y = sin(rot);
	mat->x.z = 0;
	mat->y.x = asin(rot);
	mat->y.y = cos(rot);
	mat->y.z = 0;
	mat->z.x = 0;
	mat->z.y = 0;
	mat->z.z = 1;
}

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
	static float	rotx = 0.0;
	static float	roty = 0.0;
	static float	rotz = 0.0;

	if (key == K_I)
		rotx += 0.1;
	else if (key == K_J)
		roty += -0.1;
	else if (key == K_K)
		rotx += -0.1;
	else if (key == K_L)
		roty += 0.1;
	else if (key == K_U)
		rotz += -0.1;
	else if (key == K_O)
		rotz += 0.1;
	rot_x(&master->camera->idm, rotx, 1);
	rot_y(&master->camera->idm, roty, 1);
	rot_z(&master->camera->idm, rotz, 1);
	set_new_dir(&master->camera->dir, master->camera->idm);
}
