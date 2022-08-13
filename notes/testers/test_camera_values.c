/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_camera_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:01:42 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 09:27:47 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	test_camera_values(t_camera *camera)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "camera->p_xyz[0] : %f\n", camera->p_xyz[0]);
	dprintf(STDOUT_FILENO, "camera->p_xyz[1] : %f\n", camera->p_xyz[1]);
	dprintf(STDOUT_FILENO, "camera->p_xyz[2] : %f\n", camera->p_xyz[2]);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "camera->o_xyz[0] : %f\n", camera->o_xyz[0]);
	dprintf(STDOUT_FILENO, "camera->o_xyz[1] : %f\n", camera->o_xyz[1]);
	dprintf(STDOUT_FILENO, "camera->o_xyz[2] : %f\n", camera->o_xyz[2]);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "camera->fov : %d\n", camera->fov);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}
