/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:35:35 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/09 15:02:31 by ljohnson         ###   ########lyon.fr   */
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
	if (!light->pos)
		return (1);
	light->ratio = ft_atof(split[2]);
	if (rt_check_ratio(light->ratio, split)) //function needed
		return (1);
	light->rgb = rt_init_rgb(split[3]); //function needed
	if (!light->rgb)
		return (1);
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
	if (!camera->pos)
		return (1);
	camera->dir = rt_init_dir(split[2]); //function needed
	if (!camera->dir)
		return (1);
	camera->fov = ft_atoi(split[3]);
	if (rt_check_fov(camera->fov, split)) //function needed
		return (1);
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
	ambient->ratio = ft_atof(split[1]);
	if (rt_check_ratio(ambient->ratio, split)) //function needed
		return (1);
	ambient->rgb = rt_init_rgb(split[2]); //function needed
	if (!ambient->rgb)
		return (1);
	return (0);
}
