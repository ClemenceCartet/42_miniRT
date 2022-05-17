/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 08:31:20 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 09:14:33 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_base_fd(unsigned int nbr, char *base, int fd)
{
	unsigned int	hexnb;
	size_t			baselen;

	hexnb = nbr;
	baselen = ft_strlen(base);
	if (hexnb >= baselen)
		ft_putnbr_base_fd(hexnb / baselen, base, fd);
	ft_putchar_fd(base[hexnb % baselen], fd);
}
