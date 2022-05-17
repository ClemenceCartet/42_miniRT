/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:00:40 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:45:04 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_isprime(int nb)
{
	int	a;

	a = 2;
	if (nb < a)
		return (0);
	while (a <= nb / a)
	{
		if (nb % a == 0)
			return (0);
		a++;
	}
	return (1);
}
