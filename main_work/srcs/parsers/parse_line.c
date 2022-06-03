/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:41:16 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 08:41:20 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Split line with whitespaces and throw the appropriate parsing function
int	rt_parse_line(t_master *master, char *line)
{
	char	**split;
	int		val;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// dprintf(STDOUT_FILENO, "char *line : %s\n", line);
	// dprintf(STDOUT_FILENO, "\n");
	val = 1;
	split = ft_split(line, ' ');
	if (!split)
		return (rt_write_int_error(E_MALLOC, NULL));
	// display_split(split);
	if (!ft_strncmp(split[0], "A", 2))
		val = rt_parse_ambient(master, split);
	else if (!ft_strncmp(split[0], "C", 2))
		val = rt_parse_camera(master, split);
	else if (!ft_strncmp(split[0], "L", 2))
		val = rt_parse_light(master, split);
	else if (!ft_strncmp(split[0], "sp", 3) || !ft_strncmp(split[0], "pl", 3)
		|| !ft_strncmp(split[0], "cy", 3))
		val = rt_parse_object(master, split);
	else
	{
		ft_free_split (split);
		return (rt_write_int_error(E_ID, NULL));
	}
	ft_free_split (split);
	// dprintf(STDOUT_FILENO, "val: %d\n", val);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	if (!val)
		return (0);
	return (1);
}
