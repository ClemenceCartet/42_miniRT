/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:11:21 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/09 09:13:43 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

float	rt_init_value_size(char *value, char *name)
{
	float	size;

	size = 0;
	if (!value || !value[0])
		return (rt_write_int_error(E_MISSING, name) * -1);
	if (rt_check_float_syntax(value, name))
		return (-1);
	size = ft_atof(value);
	if (size < 0 || isnan(size) || isinf(size))
		return (rt_write_int_error(E_RANGE, "positive") * -1);
	return (size);
}
