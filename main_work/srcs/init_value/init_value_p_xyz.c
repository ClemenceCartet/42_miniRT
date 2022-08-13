/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value_p_xyz.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:29:36 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/09 08:56:04 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

float	rt_init_value_p_xyz(char *value, int index, char *name, int *err)
{
	float	p_xyz;
	char	**split;

	p_xyz = 0;
	split = rt_get_split_from_raw(value, ',', 3, name);
	if (!split)
		return (*err = 1);
	if (rt_check_float_syntax(split[index], name))
	{
		ft_free_split(split);
		return (*err = 1);
	}
	p_xyz = ft_atof(split[index]);
	if (isnan(p_xyz) || isinf(p_xyz))
	{
		ft_free_split(split);
		return (*err = rt_write_int_error(E_NUMBER, name));
	}
	ft_free_split(split);
	return (p_xyz);
}
