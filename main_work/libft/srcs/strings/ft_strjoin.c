/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 08:13:28 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:44:40 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		a;
	int		b;

	if (!s1 || !s2)
		return (NULL);
	a = 0;
	b = 0;
	str = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[a])
	{
		str[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		str[a + b] = s2[b];
		b++;
	}
	str[a + b] = '\0';
	return (str);
}
