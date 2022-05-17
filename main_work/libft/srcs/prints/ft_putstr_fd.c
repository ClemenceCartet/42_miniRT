/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:59:13 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 09:07:17 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	a;

	a = 0;
	if (!s)
		return ;
	while (s[a])
		a++;
	write(fd, s, a);
}
