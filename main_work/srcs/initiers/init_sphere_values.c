/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:55:31 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 08:55:36 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Initialize every values of structure sphere to 0
int	rt_init_sphere_values(t_sphere *sphere)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	sphere->p_xyz[0] = 0;
	sphere->p_xyz[1] = 0;
	sphere->p_xyz[2] = 0;
	sphere->diameter = 0;
	sphere->rgb[0] = 0;
	sphere->rgb[1] = 0;
	sphere->rgb[2] = 0;
	// display_sphere(sphere);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (SP);
}
