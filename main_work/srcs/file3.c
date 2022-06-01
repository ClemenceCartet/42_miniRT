/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:28:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/01 11:38:02 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create Sphere structure to put in the object list while checking errors
int	rt_parse_sphere(void **object_ptr, char **split)
{
	t_sphere	*sphere;

	sphere = rt_init_object_ptr(split, 4, "Sphere");
	if (!sphere)
		return (1);
	rt_init_sphere_values(sphere);
	if (rt_set_coordinates(&sphere->p_xyz, split[1], "Sphere coordinates"))
		return (1);
	if (rt_set_diameter(&sphere->diameter, split[2], "Sphere diameter"))
		return (1);
	if (rt_set_rgb(&sphere->rgb, split[3], "Sphere RGB"))
		return (1);
	object_ptr = sphere;
	return (0);
}

// Create Plane structure to put in the object list while checking errors
int	rt_parse_plane(void **object_ptr, char **split)
{
	t_plane	*plane;

	plane = rt_init_object_ptr(split, 4, "Plane");
	rt_init_plane_values(plane);
	if (rt_set_coordinates(&plane->p_xyz, split[1], "Plane coordinates"))
		return (1);
	if (rt_set_orientation(&plane->o_xyz, split[2], "Plane orientation"))
		return (1);
	if (rt_set_rgb(&plane->rgb, split[3], "Plane RGB"))
		return (1);
	object_ptr = plane;
	return (0);
}

// Create Cylinder structure to put in the object list while checking errors
int	rt_parse_cylinder(void **object_ptr, char **split)
{
	t_cylinder	*cylinder;

	cylinder = rt_init_object_ptr(split, 6, "Cylinder");
	rt_init_cylinder_values(cylinder);
	if (rt_set_coordinates(&cylinder->p_xyz, split[1], "Cylinder coordinates"))
		return (1);
	if (rt_set_orientation(&cylinder->o_xyz, split[2], "Cylinder orientation"))
		return (1);
	if (rt_set_diameter(&cylinder->diameter, split[3], "Cylinder diameter"))
		return (1);
	if (rt_set_diameter(&cylinder->height, split[4], "Cylinder height"))
		return (1);
	if (rt_set_rgb(&cylinder->rgb, split[5], "Cylinder RGB"))
		return (1);
	object_ptr = cylinder;
	return (0);
}
