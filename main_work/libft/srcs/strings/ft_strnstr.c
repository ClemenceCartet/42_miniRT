/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:01:23 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:44:42 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0 || len < needle_len - 1)
		return (NULL);
	a = 0;
	while (haystack[a] && a < len - needle_len + 1)
	{
		b = 0;
		while (haystack[a + b] == needle[b] && b <= len)
		{
			b++;
			if (!(needle[b] != '\0' && b != len))
				return ((char *)&haystack[a]);
		}
		a++;
	}
	return (NULL);
}
