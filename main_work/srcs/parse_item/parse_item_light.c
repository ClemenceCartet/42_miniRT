/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_item_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:42:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:42:56 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create light structure and initialize it while checking value errors
int	rt_parse_light(t_master *master, char **split)
{
	if (master->light)
		return (rt_write_int_error(E_EXISTING_ID, "Light"));
	master->light = rt_init_object_ptr(split, 4, "Light");
	if (!master->light)
		return (1);
	rt_init_light_values(master->light, split);
	return (0);
}
