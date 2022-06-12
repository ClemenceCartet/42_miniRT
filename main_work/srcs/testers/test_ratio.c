/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ratio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:44:40 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/12 09:44:45 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	test_ratio(void)
{
	float	ratio;

	dprintf(STDOUT_FILENO, "\n\n\033[35m\033[1m%s\033[0m\n\n", DFU);
	ratio = rt_init_value_ratio("0.1", "ouaf1");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.1, ratio, "0.1");
	ratio = rt_init_value_ratio("0.2", "ouaf2");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.2, ratio, "0.2");
	ratio = rt_init_value_ratio("0.3", "ouaf3");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.3, ratio, "0.3");
	ratio = rt_init_value_ratio("0.4", "ouaf4");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.4, ratio, "0.4");
	ratio = rt_init_value_ratio("0.5", "ouaf5");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.5, ratio, "0.5");
	ratio = rt_init_value_ratio("0.6", "ouaf6");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.6, ratio, "0.6");
	ratio = rt_init_value_ratio("0.7", "ouaf7");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.7, ratio, "0.7");
	ratio = rt_init_value_ratio("0.8", "ouaf8");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.8, ratio, "0.8");
	ratio = rt_init_value_ratio("0.9", "ouaf9");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.9, ratio, "0.9");
	ratio = rt_init_value_ratio("1.0", "ouaf10");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 1.0, ratio, "1.0");
	ratio = rt_init_value_ratio("0.0", "ouaf11");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.0, ratio, "0.0");
	ratio = rt_init_value_ratio("0", "ouaf12");
	dprintf(STDOUT_FILENO, "%d | %f | %s\n", 0, ratio, "0");
	ratio = rt_init_value_ratio("1", "ouaf13");
	dprintf(STDOUT_FILENO, "%d | %f | %s\n", 1, ratio, "1");
	ratio = rt_init_value_ratio("0.505", "ouaf14");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.505, ratio, "0.505");
	ratio = rt_init_value_ratio("0.50", "ouaf15");
	dprintf(STDOUT_FILENO, "%f | %f | %s\n", 0.50, ratio, "0.50");
	ratio = rt_init_value_ratio("1.5", "ouaf16");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, ratio, "1.5");
	ratio = rt_init_value_ratio("-1.5", "ouaf17");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, ratio, "-1.5");
	ratio = rt_init_value_ratio("111.5", "ouaf18");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, ratio, "111.5");
	ratio = rt_init_value_ratio("1...5", "ouaf19");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, ratio, "1...5");
	ratio = rt_init_value_ratio(".1.5.", "ouaf20");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, ratio, ".1.5.");
	ratio = rt_init_value_ratio("ouaf", "ouaf21");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, ratio, "ouaf");
	ratio = rt_init_value_ratio("14a", "ouaf22");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, ratio, "14a");
	ratio = rt_init_value_ratio("", "ouaf23");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, ratio, "void");
	ratio = rt_init_value_ratio(NULL, "ouaf24");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, ratio, "NULL");
	ratio = rt_init_value_ratio("         ", "ouaf25");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, ratio, "spaces");
	ratio = rt_init_value_ratio("	", "ouaf26");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, ratio, "tab");
	ratio = rt_init_value_ratio("\0", "ouaf27");
	dprintf(STDOUT_FILENO, "%d | %f | %s | ERROR\n", -1, ratio, "NULL char");
}
