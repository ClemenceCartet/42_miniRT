/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:44:21 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/12 09:49:54 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	test_rgb(void)
{
	int	rgb;

	dprintf(STDOUT_FILENO, "\n\n\033[35m\033[1m%s\033[0m\n\n", DFU);
	rgb = rt_init_value_rgb("1,2,3", 0, "ouaf1");
	dprintf(STDOUT_FILENO, "%d | %d | %s\n", 1, rgb, "1,2,3");
	rgb = rt_init_value_rgb("1,2,3", 1, "ouaf2");
	dprintf(STDOUT_FILENO, "%d | %d | %s\n", 2, rgb, "1,2,3");
	rgb = rt_init_value_rgb("1,2,3", 2, "ouaf3");
	dprintf(STDOUT_FILENO, "%d | %d | %s\n", 3, rgb, "1,2,3");
	rgb = rt_init_value_rgb("123,212,13", 0, "ouaf4");
	dprintf(STDOUT_FILENO, "%d | %d | %s\n", 123, rgb, "123,212,13");
	rgb = rt_init_value_rgb("123,212,13", 1, "ouaf5");
	dprintf(STDOUT_FILENO, "%d | %d | %s\n", 212, rgb, "123,212,13");
	rgb = rt_init_value_rgb("123,212,13", 2, "ouaf6");
	dprintf(STDOUT_FILENO, "%d | %d | %s\n", 13, rgb, "123,212,13");
	rgb = rt_init_value_rgb("0,0,0", 0, "ouaf7");
	dprintf(STDOUT_FILENO, "%d | %d | %s\n", 0, rgb, "0,0,0");
	rgb = rt_init_value_rgb("0,0,0", 1, "ouaf8");
	dprintf(STDOUT_FILENO, "%d | %d | %s\n", 0, rgb, "0,0,0");
	rgb = rt_init_value_rgb("0,0,0", 2, "ouaf9");
	dprintf(STDOUT_FILENO, "%d | %d | %s\n", 0, rgb, "0,0,0");
	rgb = rt_init_value_rgb("0,,0", 1, "ouaf10");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, rgb, "0,,0");
	rgb = rt_init_value_rgb(",0,0", 0, "ouaf11");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, rgb, ",0,0");
	rgb = rt_init_value_rgb("0,0,", 3, "ouaf12");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, rgb, "0,0,");
	rgb = rt_init_value_rgb(",0,0,0,", 1, "ouaf13");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, rgb, ",0,0,0,");
	rgb = rt_init_value_rgb("255,255,255", 1, "ouaf14");
	dprintf(STDOUT_FILENO, "%d | %d | %s\n", 255, rgb, "255,255,255");
	rgb = rt_init_value_rgb("", 0, "ouaf15");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, rgb, "void");
	rgb = rt_init_value_rgb(NULL, 0, "ouaf16");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, rgb, "NULL");
	rgb = rt_init_value_rgb("\0", 0, "ouaf17");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, rgb, "NULL char");
	rgb = rt_init_value_rgb("       ", 0, "ouaf18");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, rgb, "spaces");
	rgb = rt_init_value_rgb("	", 0, "ouaf19");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, rgb, "tab");
	rgb = rt_init_value_rgb("123,212.15,13", 1, "ouaf20");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, rgb, "123,212.15,13");
	rgb = rt_init_value_rgb("260,260,260", 0, "ouaf21");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, rgb, "260,260,260");
	rgb = rt_init_value_rgb("260,260,260", 1, "ouaf22");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, rgb, "260,260,260");
	rgb = rt_init_value_rgb("260,260,260", 2, "ouaf23");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, rgb, "260,260,260");
	rgb = rt_init_value_rgb("-1,-2,-3", 0, "ouaf24");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, rgb, "-1,-2,-3");
	rgb = rt_init_value_rgb("-1,-2,-3", 1, "ouaf25");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, rgb, "-1,-2,-3");
	rgb = rt_init_value_rgb("-1,-2,-3", 2, "ouaf26");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, rgb, "-1,-2,-3");
}
