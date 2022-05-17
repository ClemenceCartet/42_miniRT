/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:49:50 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:44:38 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	a;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!split)
		return (NULL);
	a = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s && *s != c)
		{
			if (ft_int_strchr(s, c) != -1)
				split[a++] = ft_substr(s, 0, ft_int_strchr(s, c));
			else
				split[a++] = ft_substr(s, 0, ft_int_strchr(s, '\0'));
			while (*s && *s != c)
				s++;
		}
	}
	split[a] = NULL;
	return (split);
}
