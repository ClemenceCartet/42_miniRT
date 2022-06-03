/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:54:47 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 08:54:53 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Initialize every values of structure light to 0
void	rt_init_light_values(t_light *light)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	light->p_xyz[0] = 0;
	light->p_xyz[1] = 0;
	light->p_xyz[2] = 0;
	light->ratio = 0;
	light->rgb[0] = 0;
	light->rgb[1] = 0;
	light->rgb[2] = 0;
	// display_light(light);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}
