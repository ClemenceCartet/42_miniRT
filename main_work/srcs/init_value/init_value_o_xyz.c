/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value_o_xyz.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 08:52:03 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/09 09:03:41 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

float	rt_init_value_o_xyz(char *value, int index, char *name)
{
	float	o_xyz;
	char	**split;

	o_xyz = 0;
	if (!value || !value[0])
		return (rt_write_int_error(E_MISSING, name));
	split = rt_get_split_from_raw(value, ',', 3, name);
	if (!split)
		return (-2);
	if (rt_check_float_syntax(split[index], name))
	{
		ft_free_split(split);
		return (-2);
	}
	o_xyz = ft_atof(split[index]);
	if (o_xyz > 1 || o_xyz < -1 || isnan(o_xyz) || isinf(o_xyz))
	{
		ft_free_split(split);
		return (rt_write_int_error(E_RANGE, "-1.0/1.0") * -2);
	}
	ft_free_split(split);
	return (o_xyz);
}
