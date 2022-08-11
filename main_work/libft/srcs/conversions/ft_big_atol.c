/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_atol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:13:17 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/11 12:21:37 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

long	ft_big_atol(const char *str)
{
	long	result;
	int		negative;
	int		a;

	negative = 1;
	a = ft_atoi_check(str, &negative);
	result = ft_add_str_to_int(str, &a);
	return (result * negative);
}
