/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_item_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:43:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:43:01 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create Plane structure to put in the object list while checking errors
void	*rt_parse_plane(int *object_id, char **split)
{
	t_plane	*plane;
	char	**split;

	plane = rt_init_object_ptr(split, 4, "Plane");
	*object_id = rt_init_plane_values(plane, split);
	return (plane);
}
