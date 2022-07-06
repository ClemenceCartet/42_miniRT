/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:32:55 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/06 11:13:56 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Object initialization (SP / PL / CY)
int	rt_init_obj_data(t_obj_data *obj_data, char **split)
{
	t_object	*object;

	object = NULL;
	if (!obj_data)
	{
		obj_data = rt_calloc_struct(split, sizeof(t_obj_data));
		if (!obj_data)
			return (1);
		obj_data->lst = NULL;
		obj_data->lst_size = 0;
	}
	if (!ft_strncmp(split[0], "SP", 3))
		object = rt_init_sphere(split);
	else if (!ft_strncmp(split[0], "PL", 3))
		object = rt_init_plane(split);
	else if (!ft_strncmp(split[0], "CY", 3))
		object = rt_init_cylinder(split);
	if (!object)
		return (1);
	ft_lstadd_back(&obj_data->lst, ft_lstnew(object));
	obj_data->lst_size++;
	return (0);
}

//Light initialization (L)
int	rt_init_light(t_light *light, char **split)
{
	if (rt_check_struct(light, split, 4, "light"))
		return (1);
	light = rt_calloc_struct(split, sizeof(t_light));
	if (!light)
		return (1);
	light->pos = rt_init_pos(split[1]); //function needed
	light->ratio = ft_atof(split[2]); //check error needed
	light->rgb = rt_init_rgb(split[3]); //function needed
	return (0);
}

//Camera initialization (C)
int	rt_init_camera(t_camera *camera, char **split)
{
	if (rt_check_struct(camera, split, 4, "camera"))
		return (1);
	camera = rt_calloc_struct(split, sizeof(t_camera));
	if (!camera)
		return (1);
	camera->pos = rt_init_pos(split[1]); //function needed
	camera->dir = rt_init_dir(split[2]); //function needed
	camera->fov = ft_atoi(split[3]); //check error needed
	return (0);
}

//Ambient Light initialization (A)
int	rt_init_ambient(t_ambient *ambient, char **split)
{
	if (rt_check_struct(ambient, split, 3, "ambient light"))
		return (1);
	ambient = rt_calloc_struct(split, sizeof(t_ambient));
	if (!ambient)
		return (1);
	ambient->ratio = ft_atof(split[1]); //check error needed
	ambient->rgb = rt_init_rgb(split[2]); //function needed
	return (0);
}
