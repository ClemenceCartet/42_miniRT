/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:28:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/02 14:30:58 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create Sphere structure to put in the object list while checking errors
void	*rt_parse_sphere(int *object_id, char **split)
{
	t_sphere	*sphere;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// display_split(split);
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
	// display_sphere(sphere);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (sphere);
}

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

// Create Cylinder structure to put in the object list while checking errors
void	*rt_parse_cylinder(int *object_id, char **split)
{
	t_cylinder	*cylinder;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// display_split(split);
	cylinder = rt_init_object_ptr(split, 6, "Cylinder");
	*object_id = rt_init_cylinder_values(cylinder);
	if (rt_set_coordinates(cylinder->p_xyz, split[1], "Cylinder coordinates"))
		return (NULL);
	if (rt_set_orientation(cylinder->o_xyz, split[2], "Cylinder orientation"))
		return (NULL);
	if (rt_set_diameter(cylinder->diameter, split[3], "Cylinder diameter"))
		return (NULL);
	if (rt_set_diameter(cylinder->height, split[4], "Cylinder height"))
		return (NULL);
	if (rt_set_rgb(cylinder->rgb, split[5], "Cylinder RGB"))
		return (NULL);
	// display_cylinder(cylinder);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (cylinder);
}
