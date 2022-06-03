/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:41:55 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 08:42:03 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create camera structure and initialize it while checking value errors
int	rt_parse_camera(t_master *master, char **split)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// display_split(split);
	if (master->camera)
		return (rt_write_int_error(E_EXISTING_ID, "Camera"));
	master->camera = rt_init_object_ptr(split, 4, "Camera");
	if (!master->camera)
		return (1);
	rt_init_camera_values(master->camera);
	if (rt_set_coordinates(master->camera->p_xyz, split[1], "Cam coordinates"))
		return (1);
	if (rt_set_orientation(master->camera->o_xyz, split[2], "Cam orientation"))
		return (1);
	if (rt_set_fov(master->camera->fov, split[3], "Camera FOV"))
		return (1);
	// display_camera(camera);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (0);
}
