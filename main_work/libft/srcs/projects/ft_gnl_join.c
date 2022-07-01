/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:04:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/02 11:42:48 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_gnl_join(int fd)
{
	char	*str;
	char	*gnl;

	str = NULL;
	gnl = NULL;
	while (fd > -1)
	{
		gnl = get_next_line(fd);
		if (!gnl)
		{
			free (gnl);
			return (str);
		}
		if (!str)
			str = gnl;
		else
			str = ft_strfreejoin(str, gnl);
		if (!str)
			return (NULL);
	}
	return (NULL);
}
