/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_putnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 09:13:22 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 09:13:31 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_int_putnbr_fd(int n, int fd)
{
	long int	a;
	int			count;

	a = n;
	count = 0;
	if (a < 0)
	{
		count += ft_int_putchar_fd('-', fd);
		a = -a;
	}
	if (a > 9)
	{
		count += ft_int_putnbr_fd(a / 10, fd);
		a %= 10;
	}
	count += ft_int_putchar_fd(a + '0', fd);
	return (count);
}
