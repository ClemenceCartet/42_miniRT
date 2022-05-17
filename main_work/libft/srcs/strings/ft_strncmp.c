/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:39:50 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:44:41 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			a;
	unsigned char	*str1;
	unsigned char	*str2;

	a = 0;
	if (!s1 || !s2)
		return (256);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[a] || str2[a]) && (a < n))
	{
		if (str1[a] == str2[a])
			a++;
		else
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
	}
	return (0);
}
