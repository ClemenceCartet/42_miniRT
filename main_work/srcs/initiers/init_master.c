/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_master.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:55:47 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 08:55:51 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Initialize master content to NULL and allocate object structure
int	rt_init_master(t_master *master)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	master->mlxdata = NULL;
	master->ambient = NULL;
	master->camera = NULL;
	master->light = NULL;
	master->object = ft_calloc(1, sizeof(t_object));
	if (!master->object)
		return (rt_write_int_error(E_MALLOC, NULL));
	master->object->lst = NULL;
	master->object->lst_size = 0;
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (0);
}
