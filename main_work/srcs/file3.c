/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:28:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/05/31 14:08:22 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create Sphere structure to put in the object list while checking errors
int	rt_parse_sphere(void **object_ptr, char **split, int splitlen)
{
	t_sphere	*sphere;

	if (splitlen != 4)
		return (rt_write_int_error(E_SPLIT_SIZE, "Sphere"));
	sphere = ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
		return (rt_write_int_error(E_MALLOC, NULL));
	sphere->id = SP;
	if (rt_set_coordinates(sphere->p_xyz, split[1], "Sphere")) // Need to create rt_set_coordinates
		return (1);
	if (rt_set_diameter(sphere->diameter, split[2], "Sphere")) // Need to create rt_set_diameter
		return (1);
	if (rt_set_rgb(sphere->rgb, split[3], "Sphere")) // Need to create rt_set_rgb
		return (1);
	object_ptr = sphere;
	return (0);
}

// Create Plane structure to put in the object list while checking errors
int	rt_parse_plane(void **object_ptr, char **split, int splitlen)
{
	t_plane	*plane;

	if (splitlen != 4)
		return (rt_write_int_error(E_SPLIT_SIZE, "Plane"));
	plane = ft_calloc(1, sizeof(t_plane));
	if (!plane)
		return (rt_write_int_error(E_MALLOC, NULL));
	plane->id = PL;
	if (rt_set_coordinates(plane->p_xyz, split[1], "Plane")) // Need to create rt_set_coordinates
		return (1);
	if (rt_set_orientation(plane->o_xyz, split[2], "Plane")) // Need to create rt_set_orientation
		return (1);
	if (rt_set_rgb(plane->rgb, split[3], "Plane")) // Need to create rt_set_rgb
		return (1);
	object_ptr = plane;
	return (0);
}

// Create Cylinder structure to put in the object list while checking errors
int	rt_parse_cylinder(void **object_ptr, char **split, int splitlen)
{
	t_cylinder	*cylinder;

	if (splitlen != 6)
		return (rt_write_int_error(E_SPLIT_SIZE, "Cylinder"));
	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
		return (rt_write_int_error(E_MALLOC, NULL));
	cylinder->id = CY;
	if (rt_set_coordinates(cylinder->p_xyz, split[1], "Cylinder")) // Need to create rt_set_coordinates
		return (1);
	if (rt_set_orientation(cylinder->o_xyz, split[2], "Cylinder")) // Need to create rt_set_orientation
		return (1);
	if (rt_set_diameter(cylinder->diameter, split[3], "Cylinder")) // Need to create rt_set_diameter
		return (1);
	if (rt_set_height(cylinder->height, split[4], "Cylinder")) // Need to create rt_set_height
		return (1);
	if (rt_set_rgb(cylinder->rgb, split[5], "Cylinder")) // Need to create rt_set_rgb
		return (1);
	object_ptr = cylinder;
	return (0);
}
