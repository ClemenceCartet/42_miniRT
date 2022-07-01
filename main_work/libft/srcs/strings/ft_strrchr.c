/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:43:58 by ljohnson          #+#    #+#             */
/*   Updated: 2022/05/30 10:50:28 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	int	a;

	a = ft_strlen(s);
	while (a > 0)
	{
		if (s[a] == (char)c)
			return ((char *)&s[a]);
		a--;
	}
	if (s[a] == (char)c)
		return ((char *)&s[a]);
	return (0);
}
