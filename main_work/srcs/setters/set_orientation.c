/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_orientation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:52:31 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:43:52 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	rt_set_orientation(float o_xyz[3], char *value, char *name)
{
	char	**split;

	split = rt_get_split_from_raw(value, ',', 3, name);
	if (!split)
		return (1);
	ft_free_split(split);
	return (0);
}
