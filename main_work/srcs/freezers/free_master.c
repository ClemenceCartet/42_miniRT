/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_master.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:59:13 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 08:59:22 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Function to free everything that has been allocated through initialization
int	rt_free_master(t_master *master)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	if (master->object)
	{
		rt_free_object_list(master->object);
		free(master->object);
	}
	if (master->ambient)
		free(master->ambient);
	if (master->camera)
		free(master->camera);
	if (master->light)
		free(master->light);
	if (master->mlxdata)
	{
		free(master->mlxdata->init);
		free(master->mlxdata->window);
		free(master->mlxdata);
	}
	return (0);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}
