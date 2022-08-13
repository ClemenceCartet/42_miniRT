/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_item_ambient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:55:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/09 09:13:58 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Loop to init all three RGB values of Ambient Light
static int	rt_init_ambient_rgb(t_ambient *ambient, char *value)
{
	int	a;

	a = 0;
	while (a < 3)
	{
		ambient->rgb[a] = rt_init_value_rgb(value, a, "ambient RGB");
		if (ambient->rgb[a] == -1)
			return (1);
		a++;
	}
	return (0);
}

// Initialize every values of structure ambient light to 0
int	rt_init_item_ambient(t_ambient *ambient, char **split)
{
	ambient->ratio = rt_init_value_ratio(split[0], "ambient ratio");
	if (ambient->ratio == -2)
		return (1);
	if (rt_init_ambient_rgb(ambient, split[1]))
		return (1);
	return (0);
}
