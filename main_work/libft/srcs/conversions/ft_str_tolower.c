/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:47:46 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/12 09:00:12 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_str_tolower(const char *str)
{
	char	*newstr;
	int		a;
	int		len;

	a = 0;
	len = ft_strlen(str);
	newstr = malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	while (a < len)
	{
		if (ft_isupper(str[a]))
			newstr[a] = ft_tolower(str[a]);
		else
			newstr[a] = str[a];
		a++;
	}
	newstr[a] = '\0';
	return (newstr);
}
