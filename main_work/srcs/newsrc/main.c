/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 09:44:34 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/12 09:47:21 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	main(int ac, char **av)
{
	t_master	master;
	
	if (ac != 2)
		return (rt_write_int_error(E_USAGE, NULL, DFI, DLI));
	if (rt_init_master(&master, av[1]))
		return (rt_free_master(&master) + 1);
	test_battery(&master, ac, av);
	return (rt_free_master(&master));
}
