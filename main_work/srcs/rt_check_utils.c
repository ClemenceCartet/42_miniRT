/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:52:00 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/06 14:11:46 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Check RGB existence, syntax and range
int	rt_check_rgb_syntax(char *value)
{
	int	a;
	int	nb;

	a = 0;
	nb = 0;
	if (!value || !value[0])
		return (rt_write_int_error(E_NO_VALUE, "rt_check_rgb_syntax", DFI, DLI));
	while (value[a])
	{
		if (ft_isnotcharset(value[a], INT_CHARSET))
			return (rt_write_int_error(E_SYNTAX, value, DFI, DLI));
		a++;
	}
	nb = ft_atoi(value);
	if (nb < 0 || nb > 255)
		return (rt_write_int_error(E_RANGE, "0 / 255", DFI, DLI));
	return (0);
}

//Check float value for diameter and height
int	rt_check_float(float size, char **split, int isratio)
{
	if (!isratio && size < 0)
	{
		ft_free_split(split);
		return (rt_write_int_error(E_RANGE, "positive", DFI, DLI));
	}
	else if (isratio && (size < 0 || size > 1))
	{
		ft_free_split(split);
		return (rt_write_int_error(E_RANGE, "0.0 / 1.0", DFI, DLI));
	}
	if (isnan(size) || isinf(size))
	{
		ft_free_split(split);
		return (rt_write_int_error(E_NUMBER, "float size", DFI, DLI));
	}
	return (0);
}

//Check RGB / Pos / Dir values with charset and comma
int	rt_check_values(char *values, char *charset, char *name)
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	if (!values || !values[0])
		return (rt_write_int_error(E_NO_VALUE, name, DFI, DLI));
	dprintf(STDOUT_FILENO, "\033[35m");
	dprintf(STDOUT_FILENO, "values = %s\ncharset = %s\nname = %s", values, charset, name);
	dprintf(STDOUT_FILENO, "\033[0m\n");
	while (values[a])
	{
		dprintf(STDOUT_FILENO, "\033[35mchar = %c\033[0m\n", values[a]);
		if (ft_isnotcharset(values[a], charset))
			return (rt_write_int_error(E_SYNTAX, name, DFI, DLI));
		if (values[a] == ',')
			count++;
		a++;
	}
	if (count != 2)
		return (rt_write_int_error(E_SYNTAX, name, DFI, DLI));
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
		return (rt_write_int_error(E_NO_VALUE, "rt_check_float_syntax", DFI, DLI));
	while (value[a])
	{
		if (ft_isnotcharset(value[a], FLOAT_CHARSET))
			return (rt_write_int_error(E_SYNTAX, value, DFI, DLI));
		if (midnb && (value[a] == '-' || value[a] == '+'))
			return (rt_write_int_error(E_SYNTAX, value, DFI, DLI));
		if (!midnb && ft_ischarset(value[a], "0123456789"))
			midnb = 1;
		if (point && value[a] == '.')
			return (rt_write_int_error(E_SYNTAX, value, DFI, DLI));
		if (!point && value[a] == '.')
			point = 1;
		a++;
	}
	return (0);
}
