/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:52:09 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:45:05 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

long	ft_atol(const char *str)
{
	long	result;
	int		negative;
	int		a;

	negative = 1;
	result = 0;
	a = 0;
	while (str[a] && (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13)))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			negative = -negative;
		a++;
	}
	while (ft_isdigit(str[a]))
	{
		result = result * 10 + str[a] - '0';
		a++;
	}
	if (result > LONG_MAX && negative == -1)
		return (0);
	else if (result > LONG_MAX && negative == 1)
		return (-1);
	return (result * negative);
}
