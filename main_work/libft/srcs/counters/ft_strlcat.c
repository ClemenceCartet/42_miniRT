/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:22:06 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:45:09 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;
	size_t	srclen;

	a = ft_strlen(dst);
	b = 0;
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	if (dstsize <= a)
		return (dstsize + srclen);
	while (dstsize && (--dstsize - a) && src[b])
	{
		dst[a + b] = src[b];
		b++;
	}
	dst[a + b] = '\0';
	return (srclen + a);
}
