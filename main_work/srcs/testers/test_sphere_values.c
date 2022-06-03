/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sphere_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:02:14 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 09:02:19 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	display_sphere(t_sphere *sphere)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "sphere->p_xyz[0] : %f\n", sphere->p_xyz[0]);
	dprintf(STDOUT_FILENO, "sphere->p_xyz[1] : %f\n", sphere->p_xyz[1]);
	dprintf(STDOUT_FILENO, "sphere->p_xyz[2] : %f\n", sphere->p_xyz[2]);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "sphere->diameter : %f\n", sphere->diameter);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "sphere->rgb[0] : %d\n", sphere->rgb[0]);
	dprintf(STDOUT_FILENO, "sphere->rgb[1] : %d\n", sphere->rgb[1]);
	dprintf(STDOUT_FILENO, "sphere->rgb[2] : %d\n", sphere->rgb[2]);
	dprintf(STDOUT_FILENO, "---\n");
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}
