/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:35:42 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:45:07 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char				*str;
	unsigned int		a;

	a = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[a])
	{
		str[a] = (*f)(a, s[a]);
		a++;
	}
	str[a] = '\0';
	return (str);
}
