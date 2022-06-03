/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cylinder_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:02:44 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 09:02:49 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	display_cylinder(t_cylinder *cylinder)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "cylinder->p_xyz[0] : %f\n", cylinder->p_xyz[0]);
	dprintf(STDOUT_FILENO, "cylinder->p_xyz[1] : %f\n", cylinder->p_xyz[1]);
	dprintf(STDOUT_FILENO, "cylinder->p_xyz[2] : %f\n", cylinder->p_xyz[2]);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "cylinder->o_xyz[0] : %f\n", cylinder->o_xyz[0]);
	dprintf(STDOUT_FILENO, "cylinder->o_xyz[1] : %f\n", cylinder->o_xyz[1]);
	dprintf(STDOUT_FILENO, "cylinder->o_xyz[2] : %f\n", cylinder->o_xyz[2]);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "cylinder->diameter : %f\n", cylinder->diameter);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "cylinder->height : %f\n", cylinder->height);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "cylinder->rgb[0] : %d\n", cylinder->rgb[0]);
	dprintf(STDOUT_FILENO, "cylinder->rgb[1] : %d\n", cylinder->rgb[1]);
	dprintf(STDOUT_FILENO, "cylinder->rgb[2] : %d\n", cylinder->rgb[2]);
	dprintf(STDOUT_FILENO, "---\n");
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}
