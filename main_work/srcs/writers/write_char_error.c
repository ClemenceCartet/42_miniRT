/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:45:50 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 08:45:56 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Write an error message in two parts and return NULL for string
char	*rt_write_char_error(char *str, char *str2)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	ft_putstr_fd("\033[1m", STDOUT_FILENO);
	ft_putstr_fd("\033[31m", STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	if (str2)
		ft_putstr_fd(str2, STDOUT_FILENO);
	ft_putstr_fd("\033[0m", STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (NULL);
}
