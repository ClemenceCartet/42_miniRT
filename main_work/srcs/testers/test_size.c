/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:44:56 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/13 08:09:41 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	test_size(void)
{
	float	size;

	dprintf(STDOUT_FILENO, "\n\n\033[35m\033[1m%s\033[0m\n\n", DFU);
	size = rt_init_value_size("0.1", "ouaf1");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.1, size, "0.1");
	size = rt_init_value_size("0.2", "ouaf2");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.2, size, "0.2");
	size = rt_init_value_size("0.3", "ouaf3");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.3, size, "0.3");
	size = rt_init_value_size("0.4", "ouaf4");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.4, size, "0.4");
	size = rt_init_value_size("0.5", "ouaf5");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.5, size, "0.5");
	size = rt_init_value_size("0.6", "ouaf6");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.6, size, "0.6");
	size = rt_init_value_size("0.7", "ouaf7");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.7, size, "0.7");
	size = rt_init_value_size("0.8", "ouaf8");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.8, size, "0.8");
	size = rt_init_value_size("0.9", "ouaf9");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.9, size, "0.9");
	size = rt_init_value_size("1.0", "ouaf10");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 1.0, size, "1.0");
	size = rt_init_value_size("0.0", "ouaf11");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.0, size, "0.0");
	size = rt_init_value_size("0", "ouaf12");
	dprintf(STDOUT_FILENO, "%d | %f | %s\n", 0, size, "0");
	size = rt_init_value_size("1", "ouaf13");
	dprintf(STDOUT_FILENO, "%d | %f | %s\n", 1, size, "1");
	size = rt_init_value_size("0.505", "ouaf14");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.505, size, "0.505");
	size = rt_init_value_size("0.50", "ouaf15");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.50, size, "0.50");
	size = rt_init_value_size("1.5", "ouaf16");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 1.5, size, "1.5");
	size = rt_init_value_size("-1.5", "ouaf17");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, size, "-1.5");
	size = rt_init_value_size("111.5", "ouaf18");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 111.5, size, "111.5");
	size = rt_init_value_size("1...5", "ouaf19");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, size, "1...5");
	size = rt_init_value_size(".1.5.", "ouaf20");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, size, ".1.5.");
	size = rt_init_value_size("ouaf", "ouaf21");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, size, "ouaf");
	size = rt_init_value_size("14a", "ouaf22");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, size, "14a");
	size = rt_init_value_size("", "ouaf23");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, size, "void");
	size = rt_init_value_size(NULL, "ouaf24");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, size, "NULL");
	size = rt_init_value_size("         ", "ouaf25");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, size, "spaces");
	size = rt_init_value_size("	", "ouaf26");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, size, "tab");
	size = rt_init_value_size("\0", "ouaf27");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, size, "NULL char");
	size = rt_init_value_size("---", "ouaf28");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, size, "---");
	size = rt_init_value_size("+++", "ouaf29");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, size, "+++");
}
