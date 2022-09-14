/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_master.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 09:48:45 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/13 17:18:15 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Init the corresponding data structure depending on ID given as split[0]
static int	rt_parse_line(t_master *master, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (rt_write_int_error(E_MALLOC, NULL, DFI, DLI));
	if (!ft_strncmp(split[0], "A", 2))
		return (rt_init_ambient(&master->ambient, split));
	else if (!ft_strncmp(split[0], "C", 2))
		return (rt_init_camera(&master->camera, split));
	else if (!ft_strncmp(split[0], "L", 2))
		return (rt_init_light(&master->light, split));
	else if (!ft_strncmp(split[0], "sp", 3)
		|| !ft_strncmp(split[0], "pl", 3)
		|| !ft_strncmp(split[0], "cy", 3))
		return (rt_init_obj_data(&master->obj_data, split));
	ft_free_split(split);
	return (rt_write_int_error(E_ID, NULL, DFI, DLI));
}

//Loop with GNL to get lines one by one and initialize structures with them
static int	rt_get_file_content(t_master *master, char *filename)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (rt_write_int_error(E_OPEN, filename, DFI, DLI));
	while (fd)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else if (line[0] != '\n')
		{
			ft_replace_char(line, '\n', '\0');
			if (rt_parse_line(master, line))
			{
				free (line);
				return (1);
			}
		}
		free (line);
	}
	close(fd);
	return (0);
}

//Check filename to be sure it follows a valid syntax
static int	rt_check_filename(char *filename)
{
	int		i;
	char	*ext;

	if (!filename || !filename[0])
		return (rt_write_int_error(E_NO_FILENAME, NULL, DFI, DLI));
	i = ft_int_strrchr(filename, '.');
	if (i == -1 || i == 0)
		return (rt_write_int_error(E_NO_EXT, filename, DFI, DLI));
	if (filename[i - 1] == '/')
		return (rt_write_int_error(E_NO_NAME, NULL, DFI, DLI));
	ext = ft_strrchr(filename, '.');
	if (ft_strncmp(ext, ".rt", 4) != 0)
		return (rt_write_int_error(E_WRONG_EXT, ext, DFI, DLI));
	return (0);
}

//Check if base data are correctly initialized
static int	rt_check_init_master(t_master *master)
{
	if (!master->ambient)
		return (rt_write_int_error(E_MISSING, "Ambient Light", DFI, DLI));
	if (!master->camera)
		return (rt_write_int_error(E_MISSING, "Camera", DFI, DLI));
	if (!master->light)
		return (rt_write_int_error(E_MISSING, "Light", DFI, DLI));
	if (!master->obj_data)
		return (rt_write_int_error(E_MISSING, "Object Data", DFI, DLI));
	if (!master->obj_data->lst_size)
		return (rt_write_int_error(E_MISSING, "Objects", DFI, DLI));
	return (0);
}

//Call everything to initialize base data from a given file
int	rt_init_master(t_master *master, char *filename)
{
	master->init = NULL;
	master->wdw = NULL;
	master->mlx = NULL;
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
	if (rt_init_additional_data(master))
		return (1);
	return (0);
}
