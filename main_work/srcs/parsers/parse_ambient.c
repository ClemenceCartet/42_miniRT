/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:41:31 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 08:41:35 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create ambient light structure and initialize it while checking value errors
int	rt_parse_ambient(t_master *master, char **split)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// display_split(split);
	if (master->ambient)
		return (rt_write_int_error(E_EXISTING_ID, "Ambient Light"));
	master->ambient = rt_init_object_ptr(split, 3, "Ambient Light");
	if (!master->ambient)
		return (1);
	rt_init_ambient_values(master->ambient);
	if (rt_set_ratio(master->ambient->ratio, split[1], "Ambient Light ratio"))
		return (1);
	if (rt_set_rgb(master->ambient->rgb, split[2], "Ambient Light RGB"))
		return (1);
	// display_ambient(ambient);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (0);
}
