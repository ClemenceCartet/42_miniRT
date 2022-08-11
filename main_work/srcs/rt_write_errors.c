/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_write_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:06:39 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/03 11:06:39 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Write error messages
void	rt_display_error(char *str, char *str2)
{
	ft_putstr_fd("\033[1m", STDERR_FILENO);
	ft_putstr_fd("\033[31m", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	if (str2)
	{
		ft_putchar_fd(' ', STDERR_FILENO);
		ft_putstr_fd(str2, STDERR_FILENO);
	}
	ft_putstr_fd("\033[0m", STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

// Write an error message in two parts and return NULL for split
char	**rt_write_split_error(char *str, char *str2, char *dfi, int dli)
{
	ft_putstr_fd("\033[33m", STDERR_FILENO);
	dprintf(STDERR_FILENO, "%s | %d\n", dfi, dli);
	ft_putstr_fd("\033[0m", STDERR_FILENO);
	rt_display_error(str, str2);
	return (NULL);
}

// Write an error message in two parts and return 1
int	rt_write_int_error(char *str, char *str2, char *dfi, int dli)
{
	ft_putstr_fd("\033[33m", STDERR_FILENO);
	dprintf(STDERR_FILENO, "%s | %d\n", dfi, dli);
	ft_putstr_fd("\033[0m", STDERR_FILENO);
	rt_display_error(str, str2);
	return (1);
}

// Write an error message in two parts and return NULL for string
char	*rt_write_char_error(char *str, char *str2, char *dfi, int dli)
{
	ft_putstr_fd("\033[33m", STDERR_FILENO);
	dprintf(STDERR_FILENO, "%s | %d\n", dfi, dli);
	ft_putstr_fd("\033[0m", STDERR_FILENO);
	rt_display_error(str, str2);
	return (NULL);
}

// Write an error message in two parts and return NULL for pointer
void	*rt_write_ptr_error(char *str, char *str2, char *dfi, int dli)
{
	ft_putstr_fd("\033[33m", STDERR_FILENO);
	dprintf(STDERR_FILENO, "%s | %d\n", dfi, dli);
	ft_putstr_fd("\033[0m", STDERR_FILENO);
	rt_display_error(str, str2);
	return (NULL);
}
