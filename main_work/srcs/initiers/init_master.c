/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_master.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:55:47 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:42:24 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Initialize master content to NULL and allocate object structure
int	rt_init_master(t_master *master)
{
	master->mlxdata = NULL;
	master->ambient = NULL;
	master->camera = NULL;
	master->light = NULL;
	master->object = ft_calloc(1, sizeof(t_object));
	if (!master->object)
		return (rt_write_int_error(E_MALLOC, NULL));
	master->object->lst = NULL;
	master->object->lst_size = 0;
	return (0);
}
