/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:56:37 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/06 14:15:01 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_replace_char(char *str, char c, char rep)
{
	int	a;

	a = 0;
	if (!str)
		return ;
	while (str[a])
	{
		if (str[a] == c)
			str[a] = rep;
		a++;
	}
}
