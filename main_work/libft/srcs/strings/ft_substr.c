/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:50:20 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/14 10:46:48 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*newstr;
	size_t	s_len;

	if (!s)
		return (NULL);
	a = 0;
	s_len = ft_strlen(s);
	if (len > s_len)
		len = s_len;
	newstr = malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	while (s[start + a] && a < len && start < s_len && (start + a) < s_len)
	{
		newstr[a] = s[start + a];
		a++;
	}
	newstr[a] = '\0';
	return (newstr);
}
