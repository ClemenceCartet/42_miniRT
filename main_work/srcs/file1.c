/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 08:20:42 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/02 11:43:55 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Split content with \n and iterates through that split to init values
int	rt_parse_content(t_master *master, char *content)
{
	char	**split;
	int		a;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// dprintf(STDOUT_FILENO, "char *content :\n%s\n\n", content);
	a = 0;
	split = ft_split(content, '\n');
	if (!split)
	{
		ft_free(&content);
		return (rt_write_int_error(E_MALLOC, NULL));
	}
	// display_split(split);
	ft_free(&content);
	while (split[a])
	{
		if (rt_get_line_content(master, split[a]))
		{
			ft_free_split(split);
			return (1);
		}
		a++;
	}
	ft_free_split(split);
	master->object->start = master->object->lst;
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (0);
}

// Check content to see if the file content is valid
int	rt_check_content(char *content)
{
	int	a;

	a = 0;
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	dprintf(STDOUT_FILENO, "char *content :\n%s\n\n", content);
	if (!content || !content[0])
	{
		if (!content[0])
			ft_free(&content);
		return (rt_write_int_error(E_EMPTY, NULL));
	}
	while (content[a])
	{
		if (!ft_ischarset(content[a], PARSING_CHARSET))
		{
			dprintf(STDOUT_FILENO, "content[a] : %c\n", content[a]);
			ft_free(&content);
			return (rt_write_int_error(E_UNKNOWN, NULL));
		}
		a++;
	}
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (0);
}

// Get content of file using get_next_line and strjoin
char	*rt_get_content(char *filename)
{
	char	*content;
	int		fd;
	int		i;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// dprintf(STDOUT_FILENO, "char *filename : %s\n\n", filename);
	if (!filename || !filename[0])
		return (rt_write_char_error(E_NO_FILENAME, NULL));
	i = ft_int_strrchr(filename, '.');
	if (i == -1)
		return (rt_write_char_error(E_NO_EXT, NULL));
	if (ft_strncmp(ft_strrchr(filename, '.'), ".rt", 4) != 0)
		return (rt_write_char_error(E_WRONG_EXT, NULL));
	fd = open(filename, O_RDWR);
	if (fd == -1)
		return (rt_write_char_error(E_OPEN, filename));
	content = ft_gnl_join(fd);
	// dprintf(STDOUT_FILENO, "\nchar *gnl_join :\n%s\n", content);
	if (!content)
		return (rt_write_char_error(E_READ, filename));
	if (close(fd) == -1)
	{
		ft_free(&content);
		return (rt_write_char_error(E_CLOSE, filename));
	}
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (content);
}

// Initialize master content to NULL and allocate object structure
int	rt_set_master(t_master *master)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	master->mlxdata = NULL;
	master->ambient = NULL;
	master->camera = NULL;
	master->light = NULL;
	master->object = ft_calloc(1, sizeof(t_object));
	if (!master->object)
		return (rt_write_int_error(E_MALLOC, NULL));
	master->object->lst = NULL;
	master->object->lst_size = 0;
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (0);
}

// Main function for the initialization and parsing of the program
int	rt_init_master(t_master *master, char *filename)
{
	char	*content;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// dprintf(STDOUT_FILENO, "char *filename : %s\n\n", filename);
	if (rt_set_master(master))
		return (1);
	content = rt_get_content(filename);
	dprintf(STDOUT_FILENO, "rt_get_content:\n%s\n\n", content);
	if (rt_check_content(content))
		return (1);
	if (rt_parse_content(master, content))
		return (1);
	dprintf(1, "\033[1m\033[32mEverything worked correctly\033[0m\n");
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (0);
}
