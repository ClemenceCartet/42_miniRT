/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:00:22 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/04 23:55:25 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	rt_init_ambient(t_ambient *ambient, char **split)
{
	if (ambient)
	{
		ft_free_split(split);
		return (rt_write_int_error(E_EXISTING_ID, "ambient light"));
	}
	if (ft_splitlen(split) != 3)
	{
		ft_free_split(split);
		return (rt_write_int_error(E_SPLIT_SIZE, "ambient light"));
	}
	ambient = ft_calloc(1, sizeof(t_ambient));
	if (!ambient)
	{
		ft_free_split(split);
		return (rt_write_int_error(E_MALLOC, NULL));
	}
	ambient->ratio = ft_atof(split[1]);
	return (0);
}

int	main(int ac, char **av)
{
	t_master	master;

	if (ac != 2)
		return (rt_write_int_error(E_USAGE, NULL));
	if (rt_init_master(&master, av[1]))
		return (rt_free_master(&master) + 1);
	//insérer suite du code ici
	return (rt_free_master(&master));
}
