/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:59:00 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:44:38 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcat(char *dst, const char *src)
{
	int	a;
	int	b;

	if (!dst || !src)
		return (NULL);
	a = ft_strlen(dst);
	b = 0;
	while (src[b])
	{
		dst[a + b] = src[b];
		b++;
	}
	dst[a + b] = '\0';
	return (dst);
}
