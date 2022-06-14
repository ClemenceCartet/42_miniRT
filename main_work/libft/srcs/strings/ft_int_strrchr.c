/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_strrchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:44:32 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/14 10:51:43 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_int_strrchr(const char *s, int c)
{
	int	a;

	a = ft_strlen(s);
	while (a > 0)
	{
		if (s[a] == (char)c)
			return (a);
		a--;
	}
	if (s[a] == (char)c)
		return (a);
	return (-1);
}
