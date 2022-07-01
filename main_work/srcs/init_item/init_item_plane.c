/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_item_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:57:00 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/09 08:57:34 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Loop to init all three RGB values of Plane
static int	rt_init_plane_rgb(t_plane *plane, char *value)
{
	int	a;

	a = 0;
	while (a < 3)
	{
		plane->rgb[a] = rt_init_value_rgb(value, a, "PL RGB");
		if (plane->rgb[a] == -1)
			return (1);
		a++;
	}
	return (0);
}

//Loop to init all three p_xyz values of Plane
static int	rt_init_plane_p_xyz(t_plane *plane, char *value)
{
	int	err;
	int	a;

	err = 0;
	a = 0;
	while (a < 3)
	{
		plane->p_xyz[a] = rt_init_value_p_xyz(value, a, "PL p_xyz", &err);
		if (err)
			return (1);
		a++;
	}
	return (0);
}

//Loop to init all three o_xyz values of Plane
static int	rt_init_plane_o_xyz(t_plane *plane, char *value)
{
	int	a;

	a = 0;
	while (a < 3)
	{
		plane->o_xyz[a] = rt_init_value_o_xyz(value, a, "PL o_xyz");
		if (plane->o_xyz[a] == -2)
			return (1);
		a++;
	}
	return (0);
}

// Initialize every values of structure plane to 0
int	rt_init_item_plane(t_plane *plane, char **split)
{
	if (rt_init_plane_p_xyz(plane, split[0]))
		return (-1);
	if (rt_init_plane_o_xyz(plane, split[1]))
		return (-1);
	if (rt_init_plane_rgb(plane, split[2]))
		return (-1);
	return (PL);
}
