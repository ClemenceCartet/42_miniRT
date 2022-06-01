/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 08:22:56 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/01 08:25:27 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

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

void	rt_init_ambient_values(t_ambient *ambient)
{
	ambient->ratio = 0;
	ambient->rgb[0] = 0;
	ambient->rgb[1] = 0;
	ambient->rgb[2] = 0;
}

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
