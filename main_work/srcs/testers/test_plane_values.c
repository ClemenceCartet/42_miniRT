/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_plane_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:02:29 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 09:28:19 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	test_plane_values(t_plane *plane)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "plane->p_xyz[0] : %f\n", plane->p_xyz[0]);
	dprintf(STDOUT_FILENO, "plane->p_xyz[1] : %f\n", plane->p_xyz[1]);
	dprintf(STDOUT_FILENO, "plane->p_xyz[2] : %f\n", plane->p_xyz[2]);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "plane->o_xyz[0] : %f\n", plane->o_xyz[0]);
	dprintf(STDOUT_FILENO, "plane->o_xyz[1] : %f\n", plane->o_xyz[1]);
	dprintf(STDOUT_FILENO, "plane->o_xyz[2] : %f\n", plane->o_xyz[2]);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "plane->rgb[0] : %d\n", plane->rgb[0]);
	dprintf(STDOUT_FILENO, "plane->rgb[1] : %d\n", plane->rgb[1]);
	dprintf(STDOUT_FILENO, "plane->rgb[2] : %d\n", plane->rgb[2]);
	dprintf(STDOUT_FILENO, "---\n");
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}
