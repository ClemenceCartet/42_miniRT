/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_split_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:45:12 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:44:13 by ljohnson         ###   ########lyon.fr   */
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
