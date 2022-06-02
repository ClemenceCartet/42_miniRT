/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:22:13 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/02 10:18:22 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	rt_set_coordinates(float p_xyz[3], char *value, char *name)
{
	char	**split;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// dprintf(STDOUT_FILENO, "value : %s\n", value);
	// dprintf(STDOUT_FILENO, "name : %s\n", name);
	// dprintf(STDOUT_FILENO, "p_xyz : 0: %f | 1: %f | 2: %f\n", p_xyz[0], p_xyz[1], p_xyz[2]);
	split = rt_check_value(value, ',', 3, name);
	if (!split)
		return (1);
	// display_split(split);
	return (0);
}

int	rt_set_orientation(float o_xyz[3], char *value, char *name)
{
	char	**split;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// dprintf(STDOUT_FILENO, "value : %s\n", value);
	// dprintf(STDOUT_FILENO, "name : %s\n", name);
	// dprintf(STDOUT_FILENO, "o_xyz : 0: %f | 1: %f | 2: %f\n", o_xyz[0], o_xyz[1], o_xyz[2]);
	split = rt_check_value(value, ',', 3, name);
	if (!split)
		return (1);
	// display_split(split);
	return (0);
}

int	rt_set_rgb(int rgb[3], char *value, char *name)
{
	char	**split;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// dprintf(STDOUT_FILENO, "value : %s\n", value);
	// dprintf(STDOUT_FILENO, "name : %s\n", name);
	// dprintf(STDOUT_FILENO, "rgb : 0: %f | 1: %f | 2: %f\n", rgb[0], rgb[1], rgb[2]);
	split = rt_check_value(value, ',', 3, name);
	if (!split)
		return (1);
	// display_split(split);
	return (0);
}

int	rt_set_fov(int fov, char *value, char *name)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// dprintf(STDOUT_FILENO, "fov : %s\n", fov);
	// dprintf(STDOUT_FILENO, "value : %s\n", value);
	// dprintf(STDOUT_FILENO, "name : %s\n", name);
	return (0);
}

int	rt_set_ratio(float ratio, char *value, char *name)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// dprintf(STDOUT_FILENO, "ratio : %s\n", ratio);
	// dprintf(STDOUT_FILENO, "value : %s\n", value);
	// dprintf(STDOUT_FILENO, "name : %s\n", name);
	return (0);
}

int	rt_set_diameter(float diameter, char *value, char *name)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// dprintf(STDOUT_FILENO, "diameter : %s\n", diameter);
	// dprintf(STDOUT_FILENO, "value : %s\n", value);
	// dprintf(STDOUT_FILENO, "name : %s\n", name);
	return (0);
}
