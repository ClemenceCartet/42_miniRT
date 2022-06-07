/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_item_ambient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:55:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 11:55:30 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Initialize every values of structure ambient light to 0
void	rt_init_item_ambient(t_ambient *ambient, char **split)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	ambient->ratio = 0;
	ambient->rgb[0] = 0;
	ambient->rgb[1] = 0;
	ambient->rgb[2] = 0;
	// test_ambient_values(ambient);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}
