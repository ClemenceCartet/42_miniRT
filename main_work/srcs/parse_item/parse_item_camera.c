/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_item_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:41:55 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:42:44 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create camera structure and initialize it while checking value errors
int	rt_parse_camera(t_master *master, char **split)
{
	if (master->camera)
		return (rt_write_int_error(E_EXISTING_ID, "Camera"));
	master->camera = rt_init_object_ptr(split, 4, "Camera");
	if (!master->camera)
		return (1);
	rt_init_camera_values(master->camera, split);
	return (0);
}
