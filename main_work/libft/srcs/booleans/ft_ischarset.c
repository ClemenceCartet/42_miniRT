/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 10:35:33 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:45:03 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_ischarset(char c, char *set)
{
	size_t	a;

	a = 0;
	while (set[a])
	{
		if (c == set[a])
			return (1);
		a++;
	}
	return (0);
}
