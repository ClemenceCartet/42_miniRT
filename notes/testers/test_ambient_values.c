/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ambient_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:01:26 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 09:27:19 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	test_ambient_values(t_ambient *ambient)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "ambient->ratio : %f\n", ambient->ratio);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "ambient->rgb[0] : %d\n", ambient->rgb[0]);
	dprintf(STDOUT_FILENO, "ambient->rgb[1] : %d\n", ambient->rgb[1]);
	dprintf(STDOUT_FILENO, "ambient->rgb[2] : %d\n", ambient->rgb[2]);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}
