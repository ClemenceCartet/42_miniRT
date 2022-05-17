/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:04:27 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:44:39 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	a;
	size_t	b;

	if (!dst || !src)
		return (NULL);
	a = ft_strlen(src);
	b = 0;
	while (b < a)
	{
		dst[b] = src[b];
		b++;
	}
	dst[b] = '\0';
	return (dst);
}
