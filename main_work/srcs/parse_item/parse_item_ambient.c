/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_item_ambient.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:41:31 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:42:39 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create ambient light structure and initialize it while checking value errors
int	rt_parse_ambient(t_master *master, char **split)
{
	if (master->ambient)
		return (rt_write_int_error(E_EXISTING_ID, "Ambient Light"));
	master->ambient = rt_init_object_ptr(split, 3, "Ambient Light");
	if (!master->ambient)
		return (1);
	if (rt_init_ambient_values(master->ambient, split))
		return (1);
	return (0);
}
