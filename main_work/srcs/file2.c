/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:17:06 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/02 14:40:11 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Add an object to the object list by initializing the corresponding structure
int	rt_parse_object(t_master *master, char **split)
{
	t_obj_link	*obj_link;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// display_split(split);
	// dprintf(STDOUT_FILENO, "\n");
	obj_link = ft_calloc(1, sizeof(t_obj_link));
	if (!obj_link)
		return (rt_write_int_error(E_MALLOC, NULL));
	if (!ft_strncmp(split[0], "sp", 3))
		obj_link->object_ptr = rt_parse_sphere(&obj_link->id, split);
	else if (!ft_strncmp(split[0], "pl", 3))
		obj_link->object_ptr = rt_parse_plane(&obj_link->id, split);
	else if (!ft_strncmp(split[0], "cy", 3))
		obj_link->object_ptr = rt_parse_cylinder(&obj_link->id, split);
	if (!obj_link->object_ptr)
		return (1);
	master->object->lst_size++;
	dprintf(STDOUT_FILENO, "\033[33m\033[1m%p | %s\033[0m\n", obj_link->object_ptr, split[0]);
	ft_lstadd_back(&master->object->lst, ft_lstnew(obj_link));
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (0);
}

// Create light structure and initialize it while checking value errors
int	rt_parse_light(t_master *master, char **split)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// display_split(split);
	if (master->light)
		return (rt_write_int_error(E_EXISTING_ID, "Light"));
	master->light = rt_init_object_ptr(split, 4, "Light");
	if (!master->light)
		return (1);
	rt_init_light_values(master->light);
	if (rt_set_coordinates(master->light->p_xyz, split[1], "Light coordinates"))
		return (1);
	if (rt_set_ratio(master->light->ratio, split[2], "Light ratio"))
		return (1);
	if (rt_set_rgb(master->light->rgb, split[3], "Light RGB"))
		return (1);
	// display_light(light);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (0);
}

// Create camera structure and initialize it while checking value errors
int	rt_parse_camera(t_master *master, char **split)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// display_split(split);
	if (master->camera)
		return (rt_write_int_error(E_EXISTING_ID, "Camera"));
	master->camera = rt_init_object_ptr(split, 4, "Camera");
	if (!master->camera)
		return (1);
	rt_init_camera_values(master->camera);
	if (rt_set_coordinates(master->camera->p_xyz, split[1], "Cam coordinates"))
		return (1);
	if (rt_set_orientation(master->camera->o_xyz, split[2], "Cam orientation"))
		return (1);
	if (rt_set_fov(master->camera->fov, split[3], "Camera FOV"))
		return (1);
	// display_camera(camera);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (0);
}

// Create ambient light structure and initialize it while checking value errors
int	rt_parse_ambient(t_master *master, char **split)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// display_split(split);
	if (master->ambient)
		return (rt_write_int_error(E_EXISTING_ID, "Ambient Light"));
	master->ambient = rt_init_object_ptr(split, 3, "Ambient Light");
	if (!master->ambient)
		return (1);
	rt_init_ambient_values(master->ambient);
	if (rt_set_ratio(master->ambient->ratio, split[1], "Ambient Light ratio"))
		return (1);
	if (rt_set_rgb(master->ambient->rgb, split[2], "Ambient Light RGB"))
		return (1);
	// display_ambient(ambient);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (0);
}

// Split line with whitespaces and throw the appropriate parsing function
int	rt_get_line_content(t_master *master, char *line)
{
	char	**split;
	int		val;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// dprintf(STDOUT_FILENO, "char *line : %s\n", line);
	// dprintf(STDOUT_FILENO, "\n");
	val = 1;
	split = ft_split(line, ' ');
	if (!split)
		return (rt_write_int_error(E_MALLOC, NULL));
	// display_split(split);
	if (!ft_strncmp(split[0], "A", 2))
		val = rt_parse_ambient(master, split);
	else if (!ft_strncmp(split[0], "C", 2))
		val = rt_parse_camera(master, split);
	else if (!ft_strncmp(split[0], "L", 2))
		val = rt_parse_light(master, split);
	else if (!ft_strncmp(split[0], "sp", 3) || !ft_strncmp(split[0], "pl", 3)
		|| !ft_strncmp(split[0], "cy", 3))
		val = rt_parse_object(master, split);
	else
	{
		ft_free_split (split);
		return (rt_write_int_error(E_ID, NULL));
	}
	ft_free_split (split);
	// dprintf(STDOUT_FILENO, "val: %d\n", val);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	if (!val)
		return (0);
	return (1);
}
