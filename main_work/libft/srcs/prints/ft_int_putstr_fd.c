/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_putstr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 09:06:53 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 09:07:05 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_int_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		write (fd, "(null)", 6);
		return (6);
	}
	else
		write (fd, s, ft_strlen(s));
	return (ft_strlen(s));
}
