/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:00:22 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/02 10:54:47 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Write an error message in two parts and return NULL for split
char	**rt_write_split_error(char *str, char *str2)
{
	ft_putstr_fd("\033[1m", STDOUT_FILENO);
	ft_putstr_fd("\033[31m", STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	if (str2)
		ft_putstr_fd(str2, STDOUT_FILENO);
	ft_putstr_fd("\033[0m", STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (NULL);
}

// Write an error message in two parts and return 1
int	rt_write_int_error(char *str, char *str2)
{
	ft_putstr_fd("\033[1m", STDOUT_FILENO);
	ft_putstr_fd("\033[31m", STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	if (str2)
		ft_putstr_fd(str2, STDOUT_FILENO);
	ft_putstr_fd("\033[0m", STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (1);
}

// Write an error message in two parts and return NULL for string
char	*rt_write_char_error(char *str, char *str2)
{
	ft_putstr_fd("\033[1m", STDOUT_FILENO);
	ft_putstr_fd("\033[31m", STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	if (str2)
		ft_putstr_fd(str2, STDOUT_FILENO);
	ft_putstr_fd("\033[0m", STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (NULL);
}

int	rt_init_master(t_master *master, char *filename)
{
	master->mlx_data = NULL;
	master->obj_data = NULL;
	master->ambient = NULL;
	master->camera = NULL;
	master->light = NULL;
	//That function will change
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
