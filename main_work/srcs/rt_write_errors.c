/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_write_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 09:45:12 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/13 16:58:08 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Write error messages
static void	rt_display_error(char *str, char *str2)
{
	ft_putstr_fd("\033[1m", STDOUT_FILENO);
	ft_putstr_fd("\033[31m", STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	if (str2)
	{
		ft_putchar_fd(' ', STDOUT_FILENO);
		ft_putstr_fd(str2, STDOUT_FILENO);
	}
	ft_putstr_fd("\033[0m", STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

// Write an error message in two parts and return 1
int	rt_write_int_error(char *str, char *str2, char *dfi, int dli)
{
	ft_putstr_fd("\033[33m", STDOUT_FILENO);
	dprintf(STDOUT_FILENO, "%s | %d\n", dfi, dli);
	ft_putstr_fd("\033[0m", STDOUT_FILENO);
	rt_display_error(str, str2);
	return (1);
}

// Write an error message in two parts and return NULL for pointer
void	*rt_write_ptr_error(char *str, char *str2, char *dfi, int dli)
{
	ft_putstr_fd("\033[33m", STDOUT_FILENO);
	dprintf(STDOUT_FILENO, "%s | %d\n", dfi, dli);
	ft_putstr_fd("\033[0m", STDOUT_FILENO);
	rt_display_error(str, str2);
	return (NULL);
}

// Write an error message in two parts and return NULL for string
char	*rt_write_char_error(char *str, char *str2, char *dfi, int dli)
{
	ft_putstr_fd("\033[33m", STDOUT_FILENO);
	dprintf(STDOUT_FILENO, "%s | %d\n", dfi, dli);
	ft_putstr_fd("\033[0m", STDOUT_FILENO);
	rt_display_error(str, str2);
	return (NULL);
}

// Write an error message in two parts and return NULL for split
char	**rt_write_split_error(char *str, char *str2, char *dfi, int dli)
{
	ft_putstr_fd("\033[33m", STDOUT_FILENO);
	dprintf(STDOUT_FILENO, "%s | %d\n", dfi, dli);
	ft_putstr_fd("\033[0m", STDOUT_FILENO);
	rt_display_error(str, str2);
	return (NULL);
}
