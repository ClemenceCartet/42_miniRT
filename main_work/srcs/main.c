/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:00:22 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/27 16:15:07 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

/*
	//entry should be <nb>,<nb>,<nb> only
	//count splitlen
		//else check values
			//for each
				//if empty / void char return error
				//if isnotdigit return error
	//rt_calloc_struct(sizeof(t_coords))
		//if NULL return error
	//ft_atof all 3 values
		//for each
			//if isnan / isinf return error
*/

//THIS ONE SHOULDNT CHANGE
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

int	rt_check_pos(char **split)
{
	int	a;
	int	b;

	a = 0;
	if (ft_splitlen(split) != 3)
	{
		ft_free_split(split);
		return (rt_write_int_error(E_SPLIT_SIZE, "pos"));
	}
	while (split[a])
	{
		b = 0;
		while (split[a][b])
		{
			if (ft_isnotcharset(split[a][b], FLOAT_CHARSET))
			{
				ft_free_split(split);
				return (rt_write_int_error(E_SYNTAX, "pos"));
			}
			b++;
		}
		a++;
	}
	//STILL WORKING HERE
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
	//OUAF NEED CHECK EVERYTHING AND INIT
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
