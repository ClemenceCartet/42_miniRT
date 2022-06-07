/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_item_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:56:45 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 11:56:54 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Initialize every values of structure light to 0
void	rt_init_item_light(t_light *light, char **split)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	light->p_xyz[0] = 0;
	light->p_xyz[1] = 0;
	light->p_xyz[2] = 0;
	light->ratio = 0;
	light->rgb[0] = 0;
	light->rgb[1] = 0;
	light->rgb[2] = 0;
	// test_light_values(light);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}
