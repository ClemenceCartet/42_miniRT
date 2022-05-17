/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:19:00 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:44:43 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*start;
	const char	*end;
	char		*str;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (*start && ft_strchr(set, *start))
		start++;
	while (end > s1 && ft_strchr(set, *end))
		end--;
	if (start >= end)
		return (NULL);
	str = ft_substr(start, 0, end - start + 1);
	return (str);
}
