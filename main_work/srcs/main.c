/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:00:22 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/06 11:28:15 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	main(int ac, char **av)
{
	t_master	master;

	if (ac != 2)
		return (rt_write_int_error(E_USAGE, NULL));
	if (rt_init_master(&master, av[1]))
		return (rt_free_master(&master) + 1);
	return (rt_free_master(&master));
}
