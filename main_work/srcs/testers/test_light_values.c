/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_light_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:01:55 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 09:27:57 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	test_light_values(t_light *light)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "light->p_xyz[0] : %f\n", light->p_xyz[0]);
	dprintf(STDOUT_FILENO, "light->p_xyz[1] : %f\n", light->p_xyz[1]);
	dprintf(STDOUT_FILENO, "light->p_xyz[2] : %f\n", light->p_xyz[2]);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "light->ratio : %f\n", light->ratio);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "light->rgb[0] : %d\n", light->rgb[0]);
	dprintf(STDOUT_FILENO, "light->rgb[1] : %d\n", light->rgb[1]);
	dprintf(STDOUT_FILENO, "light->rgb[2] : %d\n", light->rgb[2]);
	dprintf(STDOUT_FILENO, "---\n");
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}
