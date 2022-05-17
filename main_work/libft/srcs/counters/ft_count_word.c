/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:35:01 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:45:08 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_count_word(const char *str, const char c)
{
	size_t	a;
	size_t	count;

	a = 0;
	count = 0;
	while (str[a])
	{
		if (a == 0)
		{
			if (str[a] != c)
				count++;
		}
		else
		{
			if (str[a - 1] == c && str[a] != c)
				count++;
		}
		a++;
	}
	return (count);
}
