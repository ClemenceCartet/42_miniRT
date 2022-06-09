/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_item_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:56:45 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/09 09:14:39 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Loop to init all three RGB values of Light
static int	rt_init_light_rgb(t_light *light, char *value)
{
	int	a;

	a = 0;
	while (a < 3)
	{
		light->rgb[a] = rt_init_value_rgb(value, a, "L RGB");
		if (light->rgb == -1)
			return (1);
		a++;
	}
	return (0);
}

//Loop to init all three p_xyz values of Light
static int	rt_init_light_p_xyz(t_light *light, char *value)
{
	int	err;
	int	a;

	a = 0;
	err = 0;
	while (a < 3)
	{
		light->p_xyz[a] = rt_init_value_p_xyz(value, a, "L p_xyz", &err);
		if (err)
			return (1);
		a++;
	}
	return (0);
}

// Initialize every values of structure light to 0
int	rt_init_item_light(t_light *light, char **split)
{
	if (rt_init_light_p_xyz(light, split[0]))
		return (1);
	light->ratio = rt_init_value_ratio(split[1], "L ratio");
	if (light->ratio == -1)
		return (1);
	if (rt_init_light_rgb(light, split[2]))
		return (1);
	return (0);
}
