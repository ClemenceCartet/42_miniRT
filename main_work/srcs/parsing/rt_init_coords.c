/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:44:05 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/28 11:04:33 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Check splitlen, existence, float syntax, overflow, isnan, isinf, range
static int	rt_check_coords_data(char **data, char **split, int isdir)
{
	int		a;
	float	tmp;

	if (ft_splitlen(split) != 3)
		return (rt_ret_int_error(data, split, E_SPLITLEN, "coords"));
	a = 0;
	while (split[a])
	{
		if (!split[a] || !split[a][0])
			return (rt_ret_int_error(data, split, E_NO_VALUE, NULL));
		if (rt_check_float_syntax(split[a]))
			return (rt_ret_int_error(data, split, NULL, NULL));
		if (rt_check_overflow(split[a], split))
			return (rt_ret_int_error(data, NULL, NULL, NULL));
		tmp = ft_atof(split[a]);
		if (isnan(tmp) || isinf(tmp))
			return (rt_ret_int_error(data, split, E_NUMBER, NULL));
		if (isdir)
			if (rt_check_float_range(tmp, -1, 1, "-1 / 1"))
				return (rt_ret_int_error(data, split, NULL, NULL));
		a++;
	}
	return (0);
}

//Check dir values for objects and camera
static t_coord	*rt_check_dir(t_coord * coord, char **data, char **split)
{

	if (ft_strncmp(data[0], "C", 2) != 0)
	{
		if (!coord->x && !coord->y && !coord->z)
		{
			free (coord);
			return (rt_ret_ptr_error(data, split, E_NUMBER, NULL));
		}
	}
	else
	{
		if (!coord->z)
			coord->z = 1;
	}
	ft_free_split(split);
	return (coord);
}

//Initialize coord module for pos or dir (C, L, SP, PL, CY)
t_coord	*rt_init_coords(char **data, char *values, int isdir)
{
	t_coord	*coord;
	char	**split;

	if (rt_check_comma(values))
		return (rt_ret_ptr_error(data, NULL, NULL, NULL));
	split = ft_split(values, ',');
	if (!split)
		return (rt_ret_ptr_error(data, split, E_MALLOC, NULL));
	if (rt_check_coords_data(data, split, isdir))
		return (NULL);
	coord = rt_calloc_struct(sizeof(t_coord), split);
	if (!coord)
		return (rt_ret_ptr_error(data, split, NULL, NULL));
	coord->x = ft_atof(split[0]);
	coord->y = ft_atof(split[1]);
	coord->z = ft_atof(split[2]);
	if (isdir)
		return (rt_check_dir(coord, data, split));
	ft_free_split(split);
	return (coord);
}
