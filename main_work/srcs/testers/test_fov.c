/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:43:59 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/12 09:44:06 by ljohnson         ###   ########lyon.fr   */
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
