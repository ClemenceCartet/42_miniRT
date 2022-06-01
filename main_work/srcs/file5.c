/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:22:13 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/01 11:19:16 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	rt_set_coordinates(float *p_xyz[3], char *value, char *name)
{
	char	**split;

	split = rt_check_value(value, ',', 3, name);
	if (!split)
		return (1);
	return (0);
}

int	rt_set_orientation(float *o_xyz[3], char *value, char *name)
{
	char	**split;

	split = rt_check_value(value, ',', 3, name);
	if (!split)
		return (1);
	return (0);
}

int	rt_set_rgb(int *rgb[3], char *value, char *name)
{
	char	**split;

	split = rt_check_value(value, ',', 3, name);
	if (!split)
		return (1);
	return (0);
}

int	rt_set_fov(int *fov, char *value, char *name)
{
	return (0);
}

int	rt_set_ratio(float *ratio, char *value, char *name)
{
	return (0);
}

int	rt_set_diameter(float *diameter, char *value, char *name)
{
	return (0);
}
