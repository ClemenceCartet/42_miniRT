/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:52:28 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/28 13:57:05 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Check splitlen and syntax of each values for struct pos
int	rt_check_pos(char **split)
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

//Initialize pos struct for Camera, Light, Sphere, Plane and Cylinder
t_coords	*rt_init_pos(char *values)
{
	t_coords	*pos;
	char		**split;

	pos = NULL;
	if (rt_check_values(values, POS_CHARSET, "pos"))
		return (NULL);
	split = ft_split(values, ',');
	if (!split)
		return (rt_write_ptr_error(E_MALLOC, NULL));
	if (rt_check_pos(split))
		return (NULL);
	pos = rt_calloc_struct(split, sizeof(t_coords));
	if (!pos)
		return (NULL);
	pos->x = ft_atof(split[0]);
	pos->y = ft_atof(split[1]);
	pos->z = ft_atof(split[2]);
	ft_free_split(split);
	if (isnan(pos->x) || isinf(pos->x) || isnan(pos->y)
		|| isinf(pos->y) || isnan(pos->z) || isinf(pos->z))
	{
		free (pos);
		return (rt_write_ptr_error(E_NUMBER, "pos"));
	}
	return (pos);
}
