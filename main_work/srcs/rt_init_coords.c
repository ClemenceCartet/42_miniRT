/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:33:41 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/06 11:48:25 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Check splitlen and syntax of each values for struct pos
int	rt_check_coords_values(char **split)
{
	int	a;

	a = 0;
	if (ft_splitlen(split) != 3)
	{
		ft_free_split(split);
		return (rt_write_int_error(E_SPLIT_SIZE, "pos"));
	}
	while (split[a])
	{
		if (rt_check_float_syntax(split[a]))
		{
			ft_free_split(split);
			return (1);
		}
		a++;
	}
	return (0);
}

//Check numbers of struct coords to avoid wrong numbers
int	rt_check_coords_numbers(t_coords *coord, int isdir)
{
	if (isnan(coord->x) || isinf(coord->x))
		return (rt_write_int_error(E_NUMBER, "x"));
	if (isnan(coord->y) || isinf(coord->y))
		return (rt_write_int_error(E_NUMBER, "y"));
	if (isnan(coord->z) || isinf(coord->z))
		return (rt_write_int_error(E_NUMBER, "z"));
	if (isdir)
	{
		if (coord->x > 1 || coord->x < -1)
			return (rt_write_int_error(E_RANGE, "-1 / 1"));
		if (coord->y > 1 || coord->y < -1)
			return (rt_write_int_error(E_RANGE, "-1 / 1"));
		if (coord->z > 1 || coord->z < -1)
			return (rt_write_int_error(E_RANGE, "-1 / 1"));
	}
	return (0);
}

//Initialize every values of the structure and call error checks
t_coords	*rt_init_coords_numbers(char *values)
{
	t_coords	*coord;
	char		**split;

	coord = NULL;
	if (rt_check_values(values, COORD_CHARSET, "coord"))
		return (NULL);
	split = ft_split(values, ',');
	if (!split)
		return (rt_write_ptr_error(E_MALLOC, NULL));
	if (rt_check_coords_values(split))
		return (NULL);
	coord = rt_calloc_struct(split, sizeof(t_coords));
	if (!coord)
		return (NULL);
	coord->x = ft_atof(split[0]);
	coord->y = ft_atof(split[1]);
	coord->z = ft_atof(split[2]);
	ft_free_split(split);
	return (coord);
}

//Initialize pos or dir struct for objects
t_coords	*rt_init_coords(char *values, int isdir)
{
	t_coords	*coord;

	coord = rt_init_coords_numbers(values);
	if (!coord)
		return (NULL);
	if (rt_check_coords_numbers(coord, isdir))
	{
		free (coord);
		return (NULL);
	}
	return (coord);
}
