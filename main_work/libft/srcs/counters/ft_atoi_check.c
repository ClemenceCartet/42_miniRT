/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:25:13 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 13:26:30 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_atoi_check(const char *str, int *negative)
{
	int	a;

	a = 0;
	while (str[a] && (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13)))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			*negative = -1;
		a++;
	}
	return (a);
}
