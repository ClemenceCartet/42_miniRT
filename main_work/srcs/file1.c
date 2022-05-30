/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 08:20:42 by ljohnson          #+#    #+#             */
/*   Updated: 2022/05/30 13:28:02 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	rt_init_data(t_master *master, char *content)
{
	char	**split;

	split = ft_split(content, '\n');
	if (!split)
	{
		free (content);
		return (rt_write_int_error(E_MALLOC, NULL));
	}
	// Check content + separate content + Search for ACLO + State machine or bool ?
}

// Check content to see if the file content is valid
int	rt_check_content(char *content)
{
	int	a;

	a = 0;
	if (!content || !content[0])
		return (rt_write_int_error(E_EMPTY, NULL));
	while (content[a])
	{
		if (!ft_ischarset(content[a], PARSING_CHARSET))
		{
			free (content);
			return (rt_write_int_error(E_UNKNOWN, NULL));
		}
		a++;
	}
	return (0);
}

// Get content of file using get_next_line and strjoin
char	*rt_get_content(char *filename)
{
	char	*content;
	int		fd;
	int		i;

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
	if (!content)
		return (rt_write_char_error(E_READ, filename));
	if (close (fd) == -1)
	{
		ft_free (&content);
		return (rt_write_char_error(E_CLOSE, filename));
	}
	return (content);
}

int	rt_init_master(t_master *master, char *filename)
{
	char	*content;

	content = rt_get_content(filename);
	if (rt_check_content(content))
		return (1);
	if (rt_init_data(master, content))
		return (1);
	dprintf(1, "\033[1m\033[32mEverything worked correctly\033[0m\n");
	ft_free (&content);
	return (0);
}
