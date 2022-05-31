/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:17:06 by ljohnson          #+#    #+#             */
/*   Updated: 2022/05/31 14:16:04 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Add an object to the object list by initializing the corresponding structure
int	rt_parse_object(t_object *object, char **split)
{
	void	*object_ptr;
	int		splitlen;

	splitlen = ft_splitlen(split);
	object_ptr = NULL;
	if (!ft_strncmp(split[0], "sp", 3))
	{
		if (rt_parse_sphere(&object_ptr, split, splitlen))
			return (1);
	}
	else if (!ft_strncmp(split[0], "pl", 3))
	{
		if (rt_parse_plane(&object_ptr, split, splitlen))
			return (1);
	}
	else if (!ft_strncmp(split[0], "cy", 3))
	{
		if (rt_parse_cylinder(&object_ptr, split, splitlen))
			return (1);
	}
	object->lst_size++;
	ft_lstadd_back(&object->lst, ft_lstnew(object_ptr));
	return (0);
}

// Create light structure and initialize it while checking value errors
int	rt_parse_light(t_light *light, char **split)
{
	int	splitlen;

	splitlen = ft_splitlen(split);
	if (light)
		return (rt_write_int_error(E_EXISTING_ID, "Light"));
	if (splitlen < 4)
		return (rt_write_int_error(E_SPLIT_SIZE, "Light"));
	light = ft_calloc(1, sizeof(t_light));
	if (!light)
		return (rt_write_int_error(E_MALLOC, NULL));
	if (rt_set_coordinates(light->p_xyz, split[1], "Light")) // Need to create rt_set_coordinates
		return (1);
	if (rt_set_ratio(light->ratio, split[2], "Light")) // Need to create rt_set_ratio
		return (1);
	if (rt_set_rgb(light->rgb, split[3], "Light")) // Need to create rt_set_rgb
		return (1);
	return (0);
}

// Create camera structure and initialize it while checking value errors
int	rt_parse_camera(t_camera *camera, char **split)
{
	int	splitlen;

	splitlen = ft_splitlen(split);
	if (camera)
		return (rt_write_int_error(E_EXISTING_ID, "Camera"));
	if (splitlen < 4)
		return (rt_write_int_error(E_SPLIT_SIZE, "Camera"));
	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
		return (rt_write_int_error(E_MALLOC, NULL));
	if (rt_set_coordinates(camera->p_xyz, split[1], "Camera")) // Need to create rt_set_coordinates
		return (1);
	if (rt_set_orientation(camera->o_xyz, split[2], "Camera")) // Need to create rt_set_orientation
		return (1);
	if (rt_set_fov(camera->fov, split[3], "Camera")) // Need to create rt_set_fov
		return (1);
	return (0);
}

// Create ambient light structure and initialize it while checking value errors
int	rt_parse_ambient(t_ambient *ambient, char **split)
{
	int	splitlen;

	splitlen = ft_splitlen(split);
	if (ambient)
		return (rt_write_int_error(E_EXISTING_ID, "Ambient Light"));
	if (splitlen < 3)
		return (rt_write_int_error(E_SPLIT_SIZE, "Ambient Light"));
	ambient = ft_calloc(1, sizeof(t_ambient));
	if (!ambient)
		return (rt_write_int_error(E_MALLOC, NULL));
	if (rt_set_ratio(ambient->ratio, split[1], "Ambient Light")) // Need to create rt_set_ratio
		return (1);
	if (rt_set_rgb(ambient->rgb, split[2], "Ambient Light")) // Need to create rt_set_rgb
		return (1);
	return (0);
}

// Split line with whitespaces and throw the appropriate parsing function
int	rt_get_line_content(t_master *master, char *line)
{
	char	**split;
	int		val;

	val = 1;
	split = ft_split(line, ' ');
	if (!split)
		return (rt_write_int_error(E_MALLOC, NULL));
	if (!ft_strncmp(split[0], "A", 2))
		val = rt_parse_ambient(master->ambient, split);
	else if (!ft_strncmp(split[0], "C", 2))
		val = rt_parse_camera(master->camera, split);
	else if (!ft_strncmp(split[0], "L", 2))
		val = rt_parse_light(master->light, split);
	else if (!ft_strncmp(split[0], "sp", 3) || !ft_strncmp(split[0], "pl", 3)
		|| !ft_strncmp(split[0], "cy", 3))
		val = rt_parse_object(master->object, split);
	else
	{
		ft_free_split (split);
		return (rt_write_int_error(E_ID, NULL));
	}
	ft_free_split (split);
	if (!val)
		return (0);
	return (1);
}
