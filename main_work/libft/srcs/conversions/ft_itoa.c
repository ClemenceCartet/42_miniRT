/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:54:23 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/12 09:00:34 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	size_t	a;

	nb = n;
	a = ft_count_char(nb);
	str = malloc(sizeof(char) * (a + 1));
	if (!str)
		return (NULL);
	str[a] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		str[a - 1] = '0' + (nb % 10);
		nb = nb / 10;
		a--;
	}
	return (str);
}
