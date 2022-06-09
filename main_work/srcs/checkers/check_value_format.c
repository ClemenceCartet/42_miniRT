/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:16:49 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/09 11:46:33 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//check value through a given charset
int	rt_check_value_format(char *value, char *charset)
{
	int	a;
	int	symbol;

	a = 0;
	symbol = 0;
	if (!value || !value[0])
		return (rt_write_int_error(E_NO_VALUE, value));
	while (value[a])
	{
		if (!ft_ischarset(value[a], charset))
			return (rt_write_int_error(E_FORMAT, value));
		if (symbol && (value[a] == '-' || value[a] == '+' || value[a] == '.'))
			return (rt_write_int_error(E_FORMAT, value));
		if (!symbol && (value[a] == '-' || value[a] == '+' || value[a] == '.'))
			symbol = 1;
		a++;
	}
	return (0);
}
