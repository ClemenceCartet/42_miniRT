/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:39:42 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:45:17 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_find_next_prime(int nb)
{
	int	a;

	if (nb <= 2)
		return (2);
	a = nb;
	if (a % 2 == 0)
		a++;
	while (a)
	{
		if (ft_isprime(a))
			return (a);
		a += 2;
	}
	return (0);
}
