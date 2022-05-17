/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_putptr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 09:12:22 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 09:15:12 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_int_putptr_base_fd(unsigned long long nbr, char *base, int fd)
{
	int					count;
	unsigned long long	hexptr;
	size_t				baselen;

	count = 0;
	hexptr = nbr;
	baselen = ft_strlen(base);
	if (hexptr >= baselen)
		count += ft_int_putptr_base_fd(hexptr / baselen, base, fd);
	count += ft_int_putchar_fd(base[hexptr % baselen], fd);
	return (count);
}

int	ft_int_putptr_fd(unsigned long long nbr, int fd)
{
	int	count;

	count = 0;
	count += ft_int_putstr_fd("0x", fd);
	count += ft_int_putptr_base_fd(*(unsigned long long *)&nbr, LOWERHEX, fd);
	return (count);
}
