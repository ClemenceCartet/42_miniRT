/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_check_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:55:27 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/12 13:15:12 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Check if value goes further beyond INT_MAX or INT_MIN
int	rt_check_overflow(char *value, char **split)
{
	if (!value || !value[0])
		return (rt_return_int_error(split, NULL, E_NO_VALUE, NULL));
	if (ft_strlen(value) > 9)
	{
		if (value[0] == '-')
		{
			if (ft_strncmp(value, CHARINT_MIN, 12) > 0)
				return (rt_return_int_error(split, NULL, E_NUMBER, NULL));
		}
		else if (ft_strncmp(value, CHARINT_MAX, 11) > 0)
			return (rt_return_int_error(split, NULL, E_NUMBER, NULL));
	}
	return (0);
}

//Check if float value is below or above given range
int	rt_check_float_range(float value, float min, float max, char *range)
{
	if (isnan(value) || isinf(value))
		return (rt_write_int_error(E_NUMBER, NULL, DFI, DLI));
	if (value < min)
		return (rt_write_int_error(E_RANGE, range, DFI, DLI));
	if (min < max)
	{
		if (value > max)
			return (rt_write_int_error(E_RANGE, range, DFI, DLI));
	}
	return (0);
}

//Check if int value is below or above given range
int	rt_check_int_range(int value, int min, int max, char *range)
{
	if (isnan(value) || isinf(value))
		return (rt_write_int_error(E_NUMBER, NULL, DFI, DLI));
	if (value < min)
		return (rt_write_int_error(E_RANGE, range, DFI, DLI));
	if (min < max)
	{
		if (value > max)
			return (rt_write_int_error(E_RANGE, range, DFI, DLI));
	}
	return (0);
}
