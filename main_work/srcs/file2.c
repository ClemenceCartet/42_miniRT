/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:17:06 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/01 11:36:10 by ljohnson         ###   ########lyon.fr   */
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
		if (rt_parse_sphere(&object_ptr, split))
			return (1);
	}
	else if (!ft_strncmp(split[0], "pl", 3))
	{
		if (rt_parse_plane(&object_ptr, split))
			return (1);
	}
	else if (!ft_strncmp(split[0], "cy", 3))
	{
		if (rt_parse_cylinder(&object_ptr, split))
			return (1);
	}
	object->lst_size++;
	ft_lstadd_back(&object->lst, ft_lstnew(object_ptr));
	return (0);
}

// Create light structure and initialize it while checking value errors
int	rt_parse_light(t_light *light, char **split)
{
	if (light)
		return (rt_write_int_error(E_EXISTING_ID, "Light"));
	light = rt_init_object_ptr(split, 4, "Light");
	if (!light)
		return (1);
	rt_init_light_values(light);
	if (rt_set_coordinates(&light->p_xyz, split[1], "Light coordinates"))
		return (1);
	if (rt_set_ratio(&light->ratio, split[2], "Light ratio"))
		return (1);
	if (rt_set_rgb(&light->rgb, split[3], "Light RGB"))
		return (1);
	return (0);
}

// Create camera structure and initialize it while checking value errors
int	rt_parse_camera(t_camera *camera, char **split)
{
	if (camera)
		return (rt_write_int_error(E_EXISTING_ID, "Camera"));
	camera = rt_init_object_ptr(split, 4, "Camera");
	if (!camera)
		return (1);
	rt_init_camera_values(camera);
	if (rt_set_coordinates(&camera->p_xyz, split[1], "Camera coordinates"))
		return (1);
	if (rt_set_orientation(&camera->o_xyz, split[2], "Camera orientation"))
		return (1);
	if (rt_set_fov(&camera->fov, split[3], "Camera FOV"))
		return (1);
	return (0);
}

// Create ambient light structure and initialize it while checking value errors
int	rt_parse_ambient(t_ambient *ambient, char **split)
{
	if (ambient)
		return (rt_write_int_error(E_EXISTING_ID, "Ambient Light"));
	ambient = rt_init_object_ptr(split, 3, "Ambient Light");
	if (!ambient)
		return (1);
	rt_init_ambient_values(ambient);
	if (rt_set_ratio(&ambient->ratio, split[1], "Ambient Light ratio"))
		return (1);
	if (rt_set_rgb(&ambient->rgb, split[2], "Ambient Light RGB"))
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
