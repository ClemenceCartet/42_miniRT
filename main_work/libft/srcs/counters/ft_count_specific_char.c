/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_specific_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:23:11 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/11 09:26:36 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_count_specific_char(char *str, int c)
{
	int	count;
	int	a;

	count = 0;
	a = 0;
	while (str[a])
	{
		if (str[a] == c)
			count++;
		a++;
	}
	return (count);
}
