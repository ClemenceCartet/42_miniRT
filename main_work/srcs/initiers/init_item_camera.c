/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_item_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:55:43 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 11:55:55 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Initialize every values of structure camera to 0
void	rt_init_item_camera(t_camera *camera, char **split)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	camera->p_xyz[0] = 0;
	camera->p_xyz[1] = 0;
	camera->p_xyz[2] = 0;
	camera->o_xyz[0] = 0;
	camera->o_xyz[1] = 0;
	camera->o_xyz[2] = 0;
	camera->fov = 0;
	// test_camera_values(camera);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}
