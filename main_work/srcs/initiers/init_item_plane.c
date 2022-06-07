/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_item_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:57:00 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 11:57:16 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Initialize every values of structure plane to 0
int	rt_init_item_plane(t_plane *plane, char **split)
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
	// test_plane_values(plane);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (PL);
}
