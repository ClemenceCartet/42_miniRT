/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:40:02 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:44:39 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	int	a;

	a = 0;
	while (s[a])
	{
		if (s[a] == (char)c)
			return ((char *)&s[a]);
		a++;
	}
	if (s[a] == (char)c)
		return ((char *)&s[a]);
	return (0);
}
