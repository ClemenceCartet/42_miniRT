/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 08:22:56 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/01 10:56:31 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Initialize every values of structure sphere to 0
void	rt_init_sphere_values(t_sphere *sphere)
{
	sphere->id = SP;
	sphere->p_xyz[0] = 0;
	sphere->p_xyz[1] = 0;
	sphere->p_xyz[2] = 0;
	sphere->diameter = 0;
	sphere->rgb[0] = 0;
	sphere->rgb[1] = 0;
	sphere->rgb[2] = 0;
}

// Initialize every values of structure plane to 0
void	rt_init_plane_values(t_plane *plane)
{
	plane->id = PL;
	plane->p_xyz[0] = 0;
	plane->p_xyz[1] = 0;
	plane->p_xyz[2] = 0;
	plane->o_xyz[0] = 0;
	plane->o_xyz[1] = 0;
	plane->o_xyz[2] = 0;
	plane->rgb[0] = 0;
	plane->rgb[1] = 0;
	plane->rgb[2] = 0;
}

// Initialize every values of structure cylinder to 0
void	rt_init_cylinder_values(t_cylinder *cylinder)
{
	cylinder->id = CY;
	cylinder->p_xyz[0] = 0;
	cylinder->p_xyz[1] = 0;
	cylinder->p_xyz[2] = 0;
	cylinder->o_xyz[0] = 0;
	cylinder->o_xyz[1] = 0;
	cylinder->o_xyz[2] = 0;
	cylinder->diameter = 0;
	cylinder->height = 0;
	cylinder->rgb[0] = 0;
	cylinder->rgb[1] = 0;
	cylinder->rgb[2] = 0;
}

// Initialize every values of structure light to 0
void	rt_init_light_values(t_light *light)
{
	light->p_xyz[0] = 0;
	light->p_xyz[1] = 0;
	light->p_xyz[2] = 0;
	light->ratio = 0;
	light->rgb[0] = 0;
	light->rgb[1] = 0;
	light->rgb[2] = 0;
}

// Initialize every values of structure ambient light to 0
void	rt_init_ambient_values(t_ambient *ambient)
{
	ambient->ratio = 0;
	ambient->rgb[0] = 0;
	ambient->rgb[1] = 0;
	ambient->rgb[2] = 0;
}

// Initialize every values of structure camera to 0
void	rt_init_camera_values(t_camera *camera)
{
	camera->p_xyz[0] = 0;
	camera->p_xyz[1] = 0;
	camera->p_xyz[2] = 0;
	camera->o_xyz[0] = 0;
	camera->o_xyz[1] = 0;
	camera->o_xyz[2] = 0;
	camera->fov = 0;
}
