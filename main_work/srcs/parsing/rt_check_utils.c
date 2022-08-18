/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:35:03 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/18 09:57:17 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Check if ACL pointer already exist and return an error if it does
int	rt_check_ptr(void *ptr, char **split)
{
	if (ptr)
	{
		if (!ft_strncmp(split[0], "A", 2))
			return (rt_ret_int_error(split, NULL, E_EXISTING_ID, "A"));
		else if (!ft_strncmp(split[0], "C", 2))
			return (rt_ret_int_error(split, NULL, E_EXISTING_ID, "C"));
		else if (!ft_strncmp(split[0], "L", 2))
			return (rt_ret_int_error(split, NULL, E_EXISTING_ID, "L"));
	}
	return (0);
}

//Check number of comma of values RGB, POS, DIR
int	rt_check_comma(char *values)
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	if (!values || !values[0])
		return (rt_write_int_error(E_NO_VALUE, NULL, DFI, DLI));
	while (values[a])
	{
		if (values[a] == ',')
			count++;
		a++;
	}
	if (count != 2)
		return (rt_write_int_error(E_SYNTAX, values, DFI, DLI));
	return (0);
}

//Check syntax of a value depending on a specific charset
int	rt_check_charset(char *value, char *charset)
{
	int	a;

	a = 0;
	if (!value || !value[0])
		return (rt_write_int_error(E_NO_VALUE, NULL, DFI, DLI));
	while (value[a])
	{
		if (ft_isnotcharset(value[a], charset))
			return (rt_write_int_error(E_SYNTAX, value, DFI, DLI));
		a++;
	}
	return (0);
}

//Check float existence and syntax with signs and points
int	rt_check_float_syntax(char *value)
{
	int	a;
	int	point;

	a = 0;
	point = 0;
	if (!value || !value[0])
		return (rt_write_int_error(E_NO_VALUE, NULL, DFI, DLI));
	while (value[a])
	{
		if (ft_isnotcharset(value[a], FLOAT_CHARSET))
			return (rt_write_int_error(E_SYNTAX, value, DFI, DLI));
		if (a > 0 && (value[a] == '-' || value[a] == '+'))
			return (rt_write_int_error(E_SYNTAX, value, DFI, DLI));
		if (point && value[a] == '.')
			return (rt_write_int_error(E_SYNTAX, value, DFI, DLI));
		if (!point && value[a] == '.')
			point = 1;
		a++;
	}
	return (0);
}
