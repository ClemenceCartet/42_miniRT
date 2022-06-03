/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:00:22 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 09:29:21 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	main(int ac, char **av)
{
	t_master	master;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	if (ac != 2)
		return (rt_write_int_error(E_USAGE, NULL));
	if (rt_parse_master(&master, av[1]))
		return (rt_free_master(&master) + 1);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (rt_free_master(&master));
}
