/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:37:55 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/11 09:05:06 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	test_fov(void)
{
	int	fov;

	dprintf(STDOUT_FILENO, "\n\n\033[35m\033[1m%s\033[0m\n\n", DFU);
	fov = rt_init_value_fov("105", "ouaf1");
	dprintf(STDOUT_FILENO, "%d | %d | %s\n", 105, fov, "105");
	fov = rt_init_value_fov("90", "ouaf2");
	dprintf(STDOUT_FILENO, "%d | %d | %s\n", 90, fov, "90");
	fov = rt_init_value_fov("0", "ouaf3");
	dprintf(STDOUT_FILENO, "%d | %d | %s\n", 0, fov, "0");
	fov = rt_init_value_fov("180", "ouaf4");
	dprintf(STDOUT_FILENO, "%d | %d | %s\n", 180, fov, "180");
	fov = rt_init_value_fov("-1", "ouaf5");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "-1");
	fov = rt_init_value_fov("-10", "ouaf6");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "-10");
	fov = rt_init_value_fov("1000", "ouaf7");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "1000");
	fov = rt_init_value_fov("ouaf", "ouaf8");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "ouaf");
	fov = rt_init_value_fov("14a", "ouaf9");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "14a");
	fov = rt_init_value_fov(NULL, "ouaf10");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "NULL");
	fov = rt_init_value_fov("", "ouaf11");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "void");
	fov = rt_init_value_fov("        ", "ouaf12");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "spaces");
	fov = rt_init_value_fov("	", "ouaf13");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "tab");
	fov = rt_init_value_fov("\0", "ouaf14");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "NULL char");
	fov = rt_init_value_fov("a14", "ouaf15");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "a14");
	fov = rt_init_value_fov("155,140,124", "ouaf16");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "155,140,124");
	fov = rt_init_value_fov("---", "ouaf17");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "---");
	fov = rt_init_value_fov("+++", "ouaf18");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "+++");
	fov = rt_init_value_fov("10.15", "ouaf19");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "10.15");
	fov = rt_init_value_fov("180.42", "ouaf20");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "180.42");
	fov = rt_init_value_fov("0.1", "ouaf21");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "0.1");
	fov = rt_init_value_fov("0.0", "ouaf22");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "0.0");
	fov = rt_init_value_fov("0..0", "ouaf23");
	dprintf(STDOUT_FILENO, "%d | %d | %s | ERROR\n", -1, fov, "0..0");
}

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
}

void	test_unit(void)
{
	dprintf(STDOUT_FILENO, "\033[33m\033[1mexpected | given | value\033[0m\n");
	test_fov();
	test_rgb();
}
