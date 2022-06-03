/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:43:29 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 09:28:08 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create Sphere structure to put in the object list while checking errors
void	*rt_parse_sphere(int *object_id, char **split)
{
	t_sphere	*sphere;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// test_split_values(split);
	sphere = rt_init_object_ptr(split, 4, "Sphere");
	if (!sphere)
		return (NULL);
	*object_id = rt_init_sphere_values(sphere);
	if (rt_set_coordinates(sphere->p_xyz, split[1], "Sphere coordinates"))
		return (NULL);
	if (rt_set_diameter(sphere->diameter, split[2], "Sphere diameter"))
		return (NULL);
	if (rt_set_rgb(sphere->rgb, split[3], "Sphere RGB"))
		return (NULL);
	// test_sphere_values(sphere);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (sphere);
}
