/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:55:17 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 08:55:22 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Initialize every values of structure plane to 0
int	rt_init_plane_values(t_plane *plane)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	plane->p_xyz[0] = 0;
	plane->p_xyz[1] = 0;
	plane->p_xyz[2] = 0;
	plane->o_xyz[0] = 0;
	plane->o_xyz[1] = 0;
	plane->o_xyz[2] = 0;
	plane->rgb[0] = 0;
	plane->rgb[1] = 0;
	plane->rgb[2] = 0;
	// display_plane(plane);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (PL);
}
