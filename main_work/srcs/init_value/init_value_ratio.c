/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value_ratio.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:00:33 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/09 09:10:23 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

float	rt_init_value_ratio(char *value, char *name)
{
	float	ratio;

	if (!value || !value[0])
		return (rt_write_int_error(E_MISSING, name) * -1);
	if (rt_check_float_syntax(value, name))
		return (-1);
	ratio = ft_atof(value);
	if (ratio > 1 || ratio < 0 || isnan(ratio) || isinf(ratio))
		return (rt_write_int_error(E_RANGE, "0.0/1.0") * -1);
	return (ratio);
}
