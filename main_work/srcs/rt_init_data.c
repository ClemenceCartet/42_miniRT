/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:16:25 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/03 12:16:25 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Init the corresponding data structure depending on ID given as split[0]
int	rt_parse_line(t_master *master, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (rt_write_int_error(E_MALLOC, NULL));
	if (!ft_strncmp(split[0], "A", 2))
		return (rt_init_ambient(master->ambient, split));
	else if (!ft_strncmp(split[0], "C", 2))
		return (rt_init_camera(master->camera, split));
	else if (!ft_strncmp(split[0], "L", 2))
		return (rt_init_light(master->light, split));
	else if (!ft_strncmp(split[0], "SP", 2)
		|| !ft_strncmp(split[0], "PL", 2)
		|| !ft_strncmp(split[0], "CY", 2))
		return (rt_init_obj_data(master->obj_data, split));
	ft_free_split(split);
	return (rt_write_int_error(E_ID, NULL));
}

//Loop with GNL to get lines one by one and initialize structures with them
int	rt_get_file_content(t_master *master, char *filename)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (rt_write_int_error(E_OPEN, filename));
	while (fd)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (rt_parse_line(master, line))
			return (1);
		free (line);
	}
	if (close(fd) == -1)
		return (rt_write_int_error(E_CLOSE, filename));
	return (0);
}

//Check if base data are correctly initialized
int	rt_check_init_master(t_master *master)
{
	if (!master->ambient)
		return (rt_write_int_error(E_MISSING, "Ambient Light"));
	if (!master->camera)
		return (rt_write_int_error(E_MISSING, "Camera"));
	if (!master->light)
		return (rt_write_int_error(E_MISSING, "Light"));
	if (!master->obj_data)
		return (rt_write_int_error(E_MISSING, "Object Data"));
	if (!master->obj_data->lst_size)
		return (rt_write_int_error(E_MISSING, "Objects"));
	return (0);
}

//Check filename to be sure it follows a valid syntax
int	rt_check_filename(char *filename)
{
	int		i;
	char	*ext;

	if (!filename || !filename[0])
		return (rt_write_int_error(E_NO_FILENAME, NULL));
	i = ft_int_strrchr(filename, '.');
	if (i == -1 || i == 0)
		return (rt_write_int_error(E_NO_EXT, filename));
	ext = ft_strrchr(filename, '.');
	if (ft_strncmp(ext, ".rt", 4) != 0)
		return (rt_write_int_error(E_WRONG_EXT, ext));
	return (0);
}

//Call everything to initialize base data from a given file
int	rt_init_master(t_master *master, char *filename)
{
	master->mlx_data = NULL;
	master->obj_data = NULL;
	master->ambient = NULL;
	master->camera = NULL;
	master->light = NULL;
	if (rt_check_filename(filename))
		return (1);
	if (rt_get_file_content(master, filename))
		return (1);
	if (rt_check_init_master(master))
		return (1);
	return (0);
}
