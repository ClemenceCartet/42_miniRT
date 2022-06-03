/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str_to_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:25:35 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 13:29:08 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_add_str_to_int(const char *str, int *a)
{
	int	result;

	result = 0;
	while (ft_isdigit(str[*a]))
	{
		result = result * 10 + str[*a] - '0';
		*a++;
	}
	return (result);
}
