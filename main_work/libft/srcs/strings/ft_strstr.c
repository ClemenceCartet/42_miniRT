/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:13:25 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:44:43 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	a;
	size_t	b;

	if (!needle || !needle[0])
		return ((char *)haystack);
	a = 0;
	while (haystack[a])
	{
		b = 0;
		if (haystack[a] == needle[b])
		{
			while (haystack[a + b] == needle[b])
			{
				b++;
				if (!needle[b])
					return ((char *)&haystack[a]);
			}
		}
		a++;
	}
	return (NULL);
}
