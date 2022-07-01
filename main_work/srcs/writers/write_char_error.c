/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:45:50 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:44:03 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

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
