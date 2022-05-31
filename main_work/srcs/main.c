/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:00:22 by ljohnson          #+#    #+#             */
/*   Updated: 2022/05/31 12:28:07 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	rt_free_object_list(t_object *object)
{
	void	*tmp;

	tmp = NULL;
	object->lst = object->start;
	while (object->lst)
	{
		free(object->lst->content);
		tmp = object->lst;
		object->lst = object->lst->next;
		free(tmp);
	}
}

int	rt_free_master(t_master *master)
{
	if (master->object)
	{
		rt_free_object_list(master->object);
		free(master->object);
	}
	if (master->ambient)
		free(master->ambient);
	if (master->camera)
		free(master->camera);
	if (master->light)
		free(master->light);
	if (master->mlxdata)
	{
		free(master->mlxdata->init);
		free(master->mlxdata->window);
		free(master->mlxdata);
	}
	free(master);
	return (0);
}

// Write an error message in two parts and return NULL
char	*rt_write_char_error(char *str, char *str2)
{
	ft_putstr_fd("\033[1m", STDERR_FILENO);
	ft_putstr_fd("\033[31m", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	if (str2)
		ft_putstr_fd(str2, STDERR_FILENO);
	ft_putstr_fd("\033[0m", STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (NULL);
}

// Write an error message in two parts and return 1
int	rt_write_int_error(char *str, char *str2)
{
	ft_putstr_fd("\033[1m", STDERR_FILENO);
	ft_putstr_fd("\033[31m", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	if (str2)
		ft_putstr_fd(str2, STDERR_FILENO);
	ft_putstr_fd("\033[0m", STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (1);
}

int	main(int ac, char **av)
{
	t_master	*master;

	master = NULL;
	if (ac != 2)
		return (rt_write_int_error(E_USAGE, NULL));
	if (rt_init_master(&master, av[1]))
		return (rt_free_master(&master) + 1);
	return (rt_free_master(&master));
}
