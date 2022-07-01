/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:00:22 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/01 11:26:47 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// int	main(int ac, char **av)
// {
// 	t_master	master;

// 	if (ac != 2)
// 		return (rt_write_int_error(E_USAGE, NULL));
// 	if (rt_parse_master(&master, av[1]))
// 		return (rt_free_master(&master) + 1);
// 	return (rt_free_master(&master));
// 	return (0);
// }

int	main(void)
{
	test_unit();
	return (0);
}
