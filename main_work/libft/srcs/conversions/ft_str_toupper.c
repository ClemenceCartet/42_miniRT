/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:51:52 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/12 09:00:46 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_str_toupper(const char *str)
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
		if (ft_islower(str[a]))
			newstr[a] = ft_toupper(str[a]);
		else
			newstr[a] = str[a];
		a++;
	}
	newstr[a] = '\0';
	return (newstr);
}
