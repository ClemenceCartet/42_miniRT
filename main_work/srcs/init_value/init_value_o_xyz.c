/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value_o_xyz.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:29:36 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/08 13:08:45 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

float	rt_init_value_o_xyz(char *value, int index, char *name, int *err)
{
	float	o_xyz;
	char	**split;

	o_xyz = 0;
	split = rt_get_split_from_raw(value, ',', index, name);
	if (!split)
		return (*err = 1);
	if (rt_check_float_syntax(split[index], name))
	{
		ft_free_split(split);
		return (*err = 1);
	}
	o_xyz = ft_atof(split[index]);
	if (o_xyz > 1 || o_xyz < -1)
	{
		ft_free_split(split);
		return (*err = rt_write_int_error(E_RANGE, name));
	}
	if (isnan(o_xyz) || isinf(o_xyz))
		return (*err = rt_write_int_error(E_NUMBER, name));
	ft_free_split(split);
	return (o_xyz);
}
