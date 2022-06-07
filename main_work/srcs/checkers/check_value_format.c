/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:16:49 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:40:30 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	rt_check_value_format(char *value, char *charset)
{
	int	a;

	a = 0;
	if (!value || !value[0])
		return (rt_write_int_error(E_FORMAT, value));
	while (value[a])
	{
		if (!ft_ischarset(value[a], charset))
			return (rt_write_int_error(E_FORMAT, value));
		a++;
	}
	return (0);
}
