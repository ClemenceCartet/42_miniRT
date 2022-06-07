/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_orientation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:52:31 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 10:56:52 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	rt_set_orientation(float o_xyz[3], char *value, char *name)
{
	char	**split;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	dprintf(STDOUT_FILENO, "char *value : %s\n", value);
	dprintf(STDOUT_FILENO, "char *name : %s\n", name);
	dprintf(STDOUT_FILENO, "float o_xyz[0]: %f\n", o_xyz[0]);
	dprintf(STDOUT_FILENO, "float o_xyz[1]: %f\n", o_xyz[1]);
	dprintf(STDOUT_FILENO, "float o_xyz[2]: %f\n", o_xyz[2]);
	split = rt_get_split_from_raw(value, ',', 3, name);
	if (!split)
		return (1);
	test_split_values(split);
	ft_free_split(split);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (0);
}
