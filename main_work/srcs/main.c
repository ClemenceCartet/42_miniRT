/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:00:22 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/28 11:30:39 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Check RGB / Pos / Dir values with charset and comma
int	rt_check_values(char *values, char *charset, char *name)
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	if (!values || !values[0])
		return (rt_write_int_error(E_NO_VALUE, name));
	while (values[a])
	{
		if (ft_isnotcharset(values[a], charset))
			return (rt_write_int_error(E_SYNTAX, name));
		if (values[a] == ',')
			count++;
		a++;
	}
	if (count != 2)
		return (rt_write_int_error(E_SYNTAX, name));
	return (0);
}

//Check float existence and syntax with signs and points
int	rt_check_float_syntax(char *value)
{
	int	a;
	int	midnb;
	int	point;

	a = 0;
	midnb = 0;
	point = 0;
	if (!value || !value[0])
		return (rt_write_int_error(E_NO_VALUE, "rt_check_float_syntax"));
	while (value[a])
	{
		if (ft_isnotcharset(value[a], FLOAT_CHARSET))
			return (rt_write_int_error(E_SYNTAX, value));
		if (midnb && value[a] == '-' || value[a] == '+')
			return (rt_write_int_error(E_SYNTAX, value));
		if (!midnb && ft_ischarset(value[a], "0123456789"))
			midnb = 1;
		if (point && value[a] == '.')
			return (rt_write_int_error(E_SYNTAX, value));
		if (!point && value[a] == '.')
			point = 1;
		a++;
	}
	return (0);
}

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

int	main(int ac, char **av)
{
	t_master	master;

	if (ac != 2)
		return (rt_write_int_error(E_USAGE, NULL));
	if (rt_init_master(&master, av[1]))
		return (rt_free_master(&master) + 1);
	return (rt_free_master(&master));
}
