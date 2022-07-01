/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:49:50 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:40:50 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Get content of file using get_next_line and strjoin
char	*rt_get_file_content(char *filename)
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
	if (close(fd) == -1)
	{
		ft_free(&content);
		return (rt_write_char_error(E_CLOSE, filename));
	}
	return (content);
}
