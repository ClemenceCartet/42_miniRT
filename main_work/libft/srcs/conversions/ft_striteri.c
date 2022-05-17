/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:30:11 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:45:07 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	a;

	a = 0;
	if (s)
	{
		while (s[a])
		{
			(*f)(a, &s[a]);
			a++;
		}
	}
}
