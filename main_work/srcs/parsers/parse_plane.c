/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:43:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 08:43:20 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create Plane structure to put in the object list while checking errors
void	*rt_parse_plane(int *object_id, char **split)
{
	t_plane	*plane;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// display_split(split);
	plane = rt_init_object_ptr(split, 4, "Plane");
	*object_id = rt_init_plane_values(plane);
	if (rt_set_coordinates(plane->p_xyz, split[1], "Plane coordinates"))
		return (NULL);
	if (rt_set_orientation(plane->o_xyz, split[2], "Plane orientation"))
		return (NULL);
	if (rt_set_rgb(plane->rgb, split[3], "Plane RGB"))
		return (NULL);
	// display_plane(plane);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (plane);
}
