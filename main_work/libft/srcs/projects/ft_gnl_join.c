/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:04:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:44:36 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_gnljoin(int fd)
{
	char	*str;
	char	*gnl;

	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	gnl = (char *)1;
	while (fd > -1)
	{
		gnl = get_next_line(fd);
		if (!gnl)
		{
			free (gnl);
			break ;
		}
		str = ft_strfreejoin(str, gnl);
		if (!str)
			return (NULL);
	}
	return (str);
}
