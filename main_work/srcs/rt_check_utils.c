/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:52:00 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/28 13:52:19 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Check RGB / Pos / Dir values with charset and comma
int	rt_check_values(char *values, char *charset, char *name)
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	if (!values || !values[0])
		return (rt_write_int_error(E_NO_VALUE, name));
	while (values[a])
	{
		if (ft_isnotcharset(values[a], charset))
			return (rt_write_int_error(E_SYNTAX, name));
		if (values[a] == ',')
			count++;
		a++;
	}
	if (count != 2)
		return (rt_write_int_error(E_SYNTAX, name));
	return (0);
}

//Check float existence and syntax with signs and points
int	rt_check_float_syntax(char *value)
{
	int	a;
	int	midnb;
	int	point;

	a = 0;
	midnb = 0;
	point = 0;
	if (!value || !value[0])
		return (rt_write_int_error(E_NO_VALUE, "rt_check_float_syntax"));
	while (value[a])
	{
		if (ft_isnotcharset(value[a], FLOAT_CHARSET))
			return (rt_write_int_error(E_SYNTAX, value));
		if (midnb && value[a] == '-' || value[a] == '+')
			return (rt_write_int_error(E_SYNTAX, value));
		if (!midnb && ft_ischarset(value[a], "0123456789"))
			midnb = 1;
		if (point && value[a] == '.')
			return (rt_write_int_error(E_SYNTAX, value));
		if (!point && value[a] == '.')
			point = 1;
		a++;
	}
	return (0);
}
