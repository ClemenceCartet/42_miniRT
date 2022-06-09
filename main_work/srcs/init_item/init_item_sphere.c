/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_item_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:57:29 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/09 09:14:55 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Loop to init all three RGB values of Sphere
static int	rt_init_sphere_rgb(t_sphere *sphere, char *value)
{
	int	a;

	a = 0;
	while (a < 3)
	{
		sphere->rgb[a] = rt_init_value_rgb(value, a, "SP RGB");
		if (sphere->rgb[a] == -1)
			return (1);
		a++;
	}
	return (0);
}

//Loop to init all three p_xyz values of Sphere
static int	rt_init_sphere_p_xyz(t_sphere *sphere, char *value)
{
	int	err;
	int	a;

	err = 0;
	a = 0;
	while (a < 3)
	{
		sphere->p_xyz[a] = rt_init_value_p_xyz(value, a, "SP p_xyz", &err);
		if (err)
			return (1);
		a++;
	}
	return (0);
}

// Initialize every values of structure sphere to 0
int	rt_init_sphere_values(t_sphere *sphere, char **split)
{
	if (rt_init_sphere_p_xyz(sphere, split[0]))
		return (-1);
	sphere->diameter = rt_init_value_size(split[1], "SP diameter");
	if (sphere->diameter == -1)
		return (-1);
	if (rt_init_sphere_rgb(sphere, split[2]))
		return (-1);
	return (SP);
}
