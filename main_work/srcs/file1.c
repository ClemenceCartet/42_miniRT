/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 08:20:42 by ljohnson          #+#    #+#             */
/*   Updated: 2022/05/30 09:26:49 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

char	*rt_get_content(char *filename)
{
	char	*content;
	int		fd;

	fd = open(filename, O_RDWR);
	if (fd == -1)
		return (rt_write_char_error(E_OPEN, filename));
	content = ft_gnl_join(fd);
	if (!content)
		return (rt_write_char_error(E_READ, filename));
	if (close (fd) == -1)
		return (rt_write_char_error(E_CLOSE, filename));
	return (content);
}

int	rt_init_master(t_master *master, char *filename)
{
	char	*content;

	(void)master;
	content = rt_get_content(filename);
	if (!content)
		return (1);
	// dprintf(1, "%s\n", content);
	// free (content);
	return (0);
}
