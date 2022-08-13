/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_check_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:55:27 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/13 18:20:45 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Compare the full size of s1 and s2, doesn't stop at the first diff found
static int	rt_full_strcmp(char *s1, char *s2)
{
	size_t			a;
	size_t			s1_size;
	size_t			s2_size;

	s1_size = 0;
	s2_size = 0;
	a = 0;
	while (s1[a])
	{
		s1_size += s1[a];
		a++;
	}
	a = 0;
	while (s2[a])
	{
		s2_size += s2[a];
		a++;
	}
	return (s1_size - s2_size);
}

//Check if value goes further beyond INT_MAX or INT_MIN
int	rt_check_overflow(char *value, char **split)
{
	if (!value || !value[0])
		return (rt_return_int_error(split, NULL, E_NO_VALUE, NULL));
	if (ft_strlen(value) > 9)
	{
		if (value[0] == '-')
		{
			if (rt_full_strcmp(value, CHARINT_MIN) > 0)
				return (rt_return_int_error(split, NULL, E_NUMBER, NULL));
			// if (ft_strncmp(value, CHARINT_MIN, 12) > 0)
			// 	return (rt_return_int_error(split, NULL, E_NUMBER, NULL));
		}
		else if (rt_full_strcmp(value, CHARINT_MAX) > 0)
			return (rt_return_int_error(split, NULL, E_NUMBER, NULL));
		// else if (ft_strncmp(value, CHARINT_MAX, 11) > 0)
		// 	return (rt_return_int_error(split, NULL, E_NUMBER, NULL));
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
