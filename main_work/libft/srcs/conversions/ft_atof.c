/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:26:43 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/11 09:52:27 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

float	ft_atof(const char *str)
{
	int		result;
	float	decimal;
	int		negative;
	int		point;
	int		a;

	negative = 1;
	decimal = 0;
	point = 1;
	a = ft_atoi_check(str, &negative);
	result = ft_add_str_to_int(str, &a);
	if (str[a] == '.')
	{
		a++;
		point = a;
		decimal = ft_add_str_to_int(str, &a);
		point = a - point;
	}
	return ((result + (decimal / ft_power(10, point))) * negative);
}
