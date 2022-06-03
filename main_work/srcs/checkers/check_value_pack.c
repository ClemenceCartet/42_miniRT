/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value_pack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:48:26 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 09:27:34 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Check the existence of the given value, split it and check splitlen
char	**rt_check_value_pack(char *value, char c, int splitlen, char *name)
{
	char	**split;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// dprintf(STDOUT_FILENO, "value: %s\n", value);
	// dprintf(STDOUT_FILENO, "c: %c\n", c);
	// dprintf(STDOUT_FILENO, "splitlen: %d\n", splitlen);
	// dprintf(STDOUT_FILENO, "name: %s\n", name);
	if (!value || !value[0])
		return (rt_write_split_error(E_MISSING, name));
	split = ft_split(value, c);
	if (!split)
		return (rt_write_split_error(E_MALLOC, NULL));
	// test_split_values(split);
	if ((int)ft_splitlen(split) != splitlen)
	{
		ft_free_split(split);
		return (rt_write_split_error(E_SPLIT_SIZE, name));
	}
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (split);
}
