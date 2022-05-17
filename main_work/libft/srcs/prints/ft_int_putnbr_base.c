/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_putnbr_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 09:14:25 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 09:14:34 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_int_putnbr_base(unsigned int nbr, char *base)
{
	int				count;
	unsigned int	hexnb;
	size_t			baselen;

	count = 0;
	hexnb = nbr;
	baselen = ft_strlen(base);
	if (hexnb >= baselen)
		count += ft_int_putnbr_base(hexnb / baselen, base);
	count += ft_int_putchar(base[hexnb % baselen]);
	return (count);
}
