/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 09:13:37 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 09:13:48 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_int_putnbr(int n)
{
	long int	a;
	int			count;

	a = n;
	count = 0;
	if (a < 0)
	{
		count += ft_int_putchar('-');
		a = -a;
	}
	if (a > 9)
	{
		count += ft_int_putnbr(a / 10);
		a %= 10;
	}
	count += ft_int_putchar(a + '0');
	return (count);
}
