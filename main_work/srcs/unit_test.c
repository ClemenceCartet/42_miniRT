/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:44:04 by ljohnson          #+#    #+#             */
/*   Updated: 2022/05/30 09:44:58 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	display_split(char **split)
{
	int	a;

	a = 0;
	while (split[a])
	{
		dprintf(1, "%d | %s\n", a, split[a]);
		a++;
	}
}