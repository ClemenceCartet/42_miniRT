/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_p_xyz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 08:15:58 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/13 09:26:29 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	test_p_xyz(void)
{
	float	p_xyz;
	int		err;

	dprintf(STDOUT_FILENO, "\n\n\033[35m\033[1m%s\033[0m\n\n", DFU);
	p_xyz = rt_init_value_p_xyz("1,2,3", 0, "ouaf1", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s\n", 1, p_xyz, err, "1,2,3");
	p_xyz = rt_init_value_p_xyz("1,2,3", 1, "ouaf2", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s\n", 2, p_xyz, err, "1,2,3");
	p_xyz = rt_init_value_p_xyz("1,2,3", 2, "ouaf3", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s\n", 3, p_xyz, err, "1,2,3");
	p_xyz = rt_init_value_p_xyz("123,212,13", 0, "ouaf4", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s\n", 123, p_xyz, err, "123,212,13");
	p_xyz = rt_init_value_p_xyz("123,212,13", 1, "ouaf5", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s\n", 212, p_xyz, err, "123,212,13");
	p_xyz = rt_init_value_p_xyz("123,212,13", 2, "ouaf6", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s\n", 13, p_xyz, err, "123,212,13");
	p_xyz = rt_init_value_p_xyz("0,0,0", 0, "ouaf7", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s\n", 0, p_xyz, err, "0,0,0");
	p_xyz = rt_init_value_p_xyz("0,0,0", 1, "ouaf8", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s\n", 0, p_xyz, err, "0,0,0");
	p_xyz = rt_init_value_p_xyz("0,0,0", 2, "ouaf9", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s\n", 0, p_xyz, err, "0,0,0");
	p_xyz = rt_init_value_p_xyz("0,,0", 1, "ouaf10", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s | ERROR\n", 0, p_xyz, err, "0,,0");
	p_xyz = rt_init_value_p_xyz(",0,0", 0, "ouaf11", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s | ERROR\n", 0, p_xyz, err, ",0,0");
	p_xyz = rt_init_value_p_xyz("0,0,", 3, "ouaf12", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s | ERROR\n", 0, p_xyz, err, "0,0,");
	p_xyz = rt_init_value_p_xyz(",0,0,0,", 1, "ouaf13", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s | ERROR\n", 0, p_xyz, err, ",0,0,0,");
	p_xyz = rt_init_value_p_xyz("255,255,255", 1, "ouaf14", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s\n", 255, p_xyz, err, "255,255,255");
	p_xyz = rt_init_value_p_xyz("", 0, "ouaf15", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s | ERROR\n", 0, p_xyz, err, "void");
	p_xyz = rt_init_value_p_xyz(NULL, 0, "ouaf16", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s | ERROR\n", 0, p_xyz, err, "NULL");
	p_xyz = rt_init_value_p_xyz("\0", 0, "ouaf17", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s | ERROR\n", 0, p_xyz, err, "NULL char");
	p_xyz = rt_init_value_p_xyz("       ", 0, "ouaf18", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s | ERROR\n", 0, p_xyz, err, "spaces");
	p_xyz = rt_init_value_p_xyz("	", 0, "ouaf19", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s | ERROR\n", 0, p_xyz, err, "tab");
	p_xyz = rt_init_value_p_xyz("123.42,212.15,13.47859", 0, "ouaf20", &err);
	dprintf(STDOUT_FILENO, "%f | %f | %d | %s\n", 123.42, p_xyz, err, "123.42,212.15,13.47859");
	p_xyz = rt_init_value_p_xyz("123.42,212.15,13.47859", 1, "ouaf21", &err);
	dprintf(STDOUT_FILENO, "%f | %f | %d | %s\n", 212.15, p_xyz, err, "123.42,212.15,13.47859");
	p_xyz = rt_init_value_p_xyz("123.42,212.15,13.47859", 2, "ouaf22", &err);
	dprintf(STDOUT_FILENO, "%f | %f | %d | %s\n", 13.47859, p_xyz, err, "123.42,212.15,13.47859");
	p_xyz = rt_init_value_p_xyz("-260.42,-260.78452,-26047.000101", 0, "ouaf23", &err);
	dprintf(STDOUT_FILENO, "%f | %f | %d | %s\n", -260.42, p_xyz, err, "-260.42,-260.78452,-26047.000101");
	p_xyz = rt_init_value_p_xyz("-260.42,-260.78452,-26047.000101", 1, "ouaf24", &err);
	dprintf(STDOUT_FILENO, "%f | %f | %d | %s\n", -260.78452, p_xyz, err, "-260.42,-260.78452,-26047.000101");
	p_xyz = rt_init_value_p_xyz("-260.42,-260.78452,-26047.000101", 2, "ouaf25", &err);
	dprintf(STDOUT_FILENO, "%f | %f | %d | %s\n", -26047.000101, p_xyz, err, "-260.42,-260.78452,-26047.000101");
	p_xyz = rt_init_value_p_xyz("-1,-2,-3", 0, "ouaf26", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s\n", -1, p_xyz, err, "-1,-2,-3");
	p_xyz = rt_init_value_p_xyz("-1,-2,-3", 1, "ouaf27", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s\n", -2, p_xyz, err, "-1,-2,-3");
	p_xyz = rt_init_value_p_xyz("-1,-2,-3", 2, "ouaf28", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s\n", -3, p_xyz, err, "-1,-2,-3");
	p_xyz = rt_init_value_p_xyz("---", 1, "ouaf29", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s | ERROR\n", -3, p_xyz, err, "---");
	p_xyz = rt_init_value_p_xyz("+++", 1, "ouaf30", &err);
	dprintf(STDOUT_FILENO, "%d | %f | %d | %s | ERROR\n", -3, p_xyz, err, "+++");
}
