/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 08:33:19 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 09:12:31 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_putptr_base_fd(unsigned long long nbr, char *base, int fd)
{
	unsigned long long	hexptr;
	size_t				baselen;

	hexptr = nbr;
	baselen = ft_strlen(base);
	if (hexptr >= baselen)
		ft_putptr_base_fd(hexptr / baselen, base, fd);
	ft_putchar_fd(base[hexptr % baselen], fd);
}

void	ft_putptr_fd(unsigned long long nbr, int fd)
{
	ft_putstr_fd("0x", fd);
	ft_putptr_base_fd(*(unsigned long long *)&nbr, LOWERHEX, fd);
}
