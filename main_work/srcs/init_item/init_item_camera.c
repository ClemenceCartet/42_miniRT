/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_item_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:55:55 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/09 09:14:19 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Loop to init all three o_xyz values of Camera
static int	rt_init_camera_o_xyz(t_camera *camera, char *value)
{
	int	a;

	a = 0;
	while (a < 3)
	{
		camera->o_xyz[a] = rt_init_value_o_xyz(value, a, "C o_xyz");
		if (camera->o_xyz[a] == -2)
			return (1);
		a++;
	}
	return (0);
}

//Loop to init all three p_xyz values of Camera
static int	rt_init_camera_p_xyz(t_camera *camera, char *value)
{
	int	err;
	int	a;

	err = 0;
	a = 0;
	while (a < 3)
	{
		camera->p_xyz[a] = rt_init_value_p_xyz(value, a, "C p_xyz", &err);
		if (err)
			return (1);
		a++;
	}
	return (0);
}

// Initialize every values of structure camera to 0
int	rt_init_item_camera(t_camera *camera, char **split)
{
	if (rt_init_camera_p_xyz(camera, split[0]))
		return (1);
	if (rt_init_camera_o_xyz(camera, split[1]))
		return (1);
	camera->fov = rt_init_value_fov(split[2], "C FOV");
	if (camera->fov == -1)
		return (1);
	return (0);
}
