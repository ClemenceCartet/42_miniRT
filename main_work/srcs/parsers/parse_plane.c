/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:43:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 11:45:26 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create Plane structure to put in the object list while checking errors
void	*rt_parse_plane(int *object_id, char **split)
{
	t_plane	*plane;
	char	**split;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// test_split_values(split);
	plane = rt_init_object_ptr(split, 4, "Plane");
	*object_id = rt_init_plane_values(plane, split);
	dprintf(STDOUT_FILENO, "object_id: %d\n", *object_id);
	// test_plane_values(plane);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (plane);
}
