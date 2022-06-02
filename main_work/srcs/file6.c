/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:31:20 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/02 14:01:08 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Check the existence of the given value, split it and check splitlen
char	**rt_check_value(char *value, char c, int splitlen, char *name)
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
	// display_split(split);
	if ((int)ft_splitlen(split) != splitlen)
	{
		ft_free_split(split);
		return (rt_write_split_error(E_SPLIT_SIZE, name));
	}
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (split);
}

// Check splitlen and initialize object pointer depending on ID given
void	*rt_init_object_ptr(char **split, int valid_splitlen, char *name)
{
	void	*object_ptr;
	int		splitlen;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// display_split(split);
	// dprintf(STDOUT_FILENO, "valid_splitlen: %d\n", valid_splitlen);
	// dprintf(STDOUT_FILENO, "name: %s\n", name);
	object_ptr = NULL;
	splitlen = ft_splitlen(split);
	// dprintf(STDOUT_FILENO, "splitlen: %d\n", splitlen);
	if (splitlen != valid_splitlen)
		return (rt_write_char_error(E_SPLIT_SIZE, name));
	if (!ft_strncmp(split[0], "A", 2))
		object_ptr = ft_calloc(1, sizeof(t_ambient));
	else if (!ft_strncmp(split[0], "C", 2))
		object_ptr = ft_calloc(1, sizeof(t_camera));
	else if (!ft_strncmp(split[0], "L", 2))
		object_ptr = ft_calloc(1, sizeof(t_light));
	else if (!ft_strncmp(split[0], "sp", 3))
		object_ptr = ft_calloc(1, sizeof(t_sphere));
	else if (!ft_strncmp(split[0], "pl", 3))
		object_ptr = ft_calloc(1, sizeof(t_plane));
	else if (!ft_strncmp(split[0], "cy", 3))
		object_ptr = ft_calloc(1, sizeof(t_cylinder));
	else
		return (rt_write_char_error(E_ID, NULL));
	if (!object_ptr)
		return (rt_write_char_error(E_MALLOC, NULL));
	dprintf(STDOUT_FILENO, "\033[33m\033[1m%p | %s\033[0m\n", object_ptr, name);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (object_ptr);
}
