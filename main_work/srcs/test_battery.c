/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_battery.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:26:12 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/06 13:45:12 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

static void	error_messages(void)
{
	dprintf(STDOUT_FILENO, "\n==================================================\n");
	dprintf(STDOUT_FILENO, "Error messages : rt_write_int_error\n\n");
	rt_write_int_error(E_MALLOC, NULL, DFI, DLI);
	rt_write_int_error(E_USAGE, NULL, DFI, DLI);
	rt_write_int_error(E_NO_FILENAME, NULL, DFI, DLI);
	rt_write_int_error(E_NO_EXT, NULL, DFI, DLI);
	rt_write_int_error(E_WRONG_EXT, NULL, DFI, DLI);
	rt_write_int_error(E_OPEN, NULL, DFI, DLI);
	rt_write_int_error(E_READ, NULL, DFI, DLI);
	rt_write_int_error(E_CLOSE, NULL, DFI, DLI);
	rt_write_int_error(E_MISSING, NULL, DFI, DLI);
	rt_write_int_error(E_ID, NULL, DFI, DLI);
	rt_write_int_error(E_EXISTING_ID, NULL, DFI, DLI);
	rt_write_int_error(E_SPLIT_SIZE, NULL, DFI, DLI);
	rt_write_int_error(E_RANGE, NULL, DFI, DLI);
	rt_write_int_error(E_SYNTAX, NULL, DFI, DLI);
	rt_write_int_error(E_NUMBER, NULL, DFI, DLI);
	rt_write_int_error(E_NO_VALUE, NULL, DFI, DLI);
	
	dprintf(STDOUT_FILENO, "\n");
	
	rt_write_int_error(E_MALLOC, "ouaf", DFI, DLI);
	rt_write_int_error(E_USAGE, "ouaf", DFI, DLI);
	rt_write_int_error(E_NO_FILENAME, "ouaf", DFI, DLI);
	rt_write_int_error(E_NO_EXT, "ouaf", DFI, DLI);
	rt_write_int_error(E_WRONG_EXT, "ouaf", DFI, DLI);
	rt_write_int_error(E_OPEN, "ouaf", DFI, DLI);
	rt_write_int_error(E_READ, "ouaf", DFI, DLI);
	rt_write_int_error(E_CLOSE, "ouaf", DFI, DLI);
	rt_write_int_error(E_MISSING, "ouaf", DFI, DLI);
	rt_write_int_error(E_ID, "ouaf", DFI, DLI);
	rt_write_int_error(E_EXISTING_ID, "ouaf", DFI, DLI);
	rt_write_int_error(E_SPLIT_SIZE, "ouaf", DFI, DLI);
	rt_write_int_error(E_RANGE, "ouaf", DFI, DLI);
	rt_write_int_error(E_SYNTAX, "ouaf", DFI, DLI);
	rt_write_int_error(E_NUMBER, "ouaf", DFI, DLI);
	rt_write_int_error(E_NO_VALUE, "ouaf", DFI, DLI);
	dprintf(STDOUT_FILENO, "\n==================================================\n");
}

void	test_battery(t_master *master, int ac, char **av)
{
	dprintf(STDOUT_FILENO, "ac = %d\n", ac);
	for (int i = 0; av[i]; i++)
		dprintf(STDOUT_FILENO, "av[%d] = %s\n", i, av[i]);
	dprintf(STDOUT_FILENO, "%p\n", master);
	error_messages();
	
}
