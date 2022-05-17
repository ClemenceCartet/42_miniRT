/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:03:08 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:45:09 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	length;

	a = 0;
	length = ft_strlen(src);
	if (dstsize > 0)
	{
		while (a + 1 < dstsize && src[a])
		{
			dst[a] = src[a];
			a++;
		}
		dst[a] = '\0';
	}
	return (length);
}
