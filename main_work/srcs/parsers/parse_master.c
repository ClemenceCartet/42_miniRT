/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_master.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:40:09 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 08:40:14 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Main function for the initialization and parsing of the program
int	rt_parse_master(t_master *master, char *filename)
{
	char	*content;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// dprintf(STDOUT_FILENO, "char *filename : %s\n\n", filename);
	if (rt_set_master(master))
		return (1);
	content = rt_get_content(filename);
	// dprintf(STDOUT_FILENO, "rt_get_content:\n%s\n\n", content);
	if (rt_check_content(content))
		return (1);
	if (rt_parse_content(master, content))
		return (1);
	dprintf(1, "\033[1m\033[32mEverything worked correctly\033[0m\n");
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (0);
}
