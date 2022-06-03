/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:42:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 09:27:57 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create light structure and initialize it while checking value errors
int	rt_parse_light(t_master *master, char **split)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// test_split_values(split);
	if (master->light)
		return (rt_write_int_error(E_EXISTING_ID, "Light"));
	master->light = rt_init_object_ptr(split, 4, "Light");
	if (!master->light)
		return (1);
	rt_init_light_values(master->light);
	if (rt_set_coordinates(master->light->p_xyz, split[1], "Light coordinates"))
		return (1);
	if (rt_set_ratio(master->light->ratio, split[2], "Light ratio"))
		return (1);
	if (rt_set_rgb(master->light->rgb, split[3], "Light RGB"))
		return (1);
	// test_light_values(light);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (0);
}
