/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnotcharset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 08:48:34 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:45:04 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_isnotcharset(char c, char *set)
{
	size_t	a;

	a = 0;
	while (set[a])
	{
		if (c != set[a])
			return (1);
		a++;
	}
	return (0);
}
