/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:55:00 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 08:55:07 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Initialize every values of structure cylinder to 0
int	rt_init_cylinder_values(t_cylinder *cylinder)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	cylinder->p_xyz[0] = 0;
	cylinder->p_xyz[1] = 0;
	cylinder->p_xyz[2] = 0;
	cylinder->o_xyz[0] = 0;
	cylinder->o_xyz[1] = 0;
	cylinder->o_xyz[2] = 0;
	cylinder->diameter = 0;
	cylinder->height = 0;
	cylinder->rgb[0] = 0;
	cylinder->rgb[1] = 0;
	cylinder->rgb[2] = 0;
	// display_cylinder(cylinder);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (CY);
}
