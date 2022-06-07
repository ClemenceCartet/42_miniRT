/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_item_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:56:04 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:39:41 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Loop to init all three RGB values of Cylinder
static int	rt_init_cylinder_rgb(t_cylinder *cylinder, char *value)
{
	int	a;

	a = 0;
	while (a < 3)
	{
		cylinder->rgb[a] = rt_init_value_rgb(value, a, "CY RGB");
		if (cylinder->rgb[a] == -1)
			return (1);
		a++;
	}
	return (0);
}

//Loop to init all three p_xyz values of Cylinder
static int	rt_init_cylinder_p_xyz(t_cylinder *cylinder, char *value)
{
	int	err;
	int	a;

	err = 0;
	a = 0;
	while (a < 3)
	{
		cylinder->p_xyz[a] = rt_init_value_p_xyz(value, a, "CY p_xyz", &err);
		if (err)
			return (1);
		a++;
	}
	return (0);
}

//Loop to init all three o_xyz values of Cylinder
static int	rt_init_cylinder_o_xyz(t_cylinder *cylinder, char *value)
{
	int	a;

	a = 0;
	while (a < 3)
	{
		cylinder->o_xyz[a] = rt_init_value_o_xyz(value, a, "CY o_xyz");
		if (cylinder->o_xyz[a] == -2)
			return (1);
		a++;
	}
	return (0);
}

// Initialize every values of structure cylinder to 0
int	rt_init_item_cylinder(t_cylinder *cylinder, char **split)
{
	if (rt_init_cylinder_p_xyz(cylinder, split[0]))
		return (-1);
	if (rt_init_cylinder_o_xyz(cylinder, split[1]))
		return (-1);
	cylinder->diameter = rt_init_value_size(split[2], "CY diameter");
	if (cylinder->diameter == -1)
		return (-1);
	cylinder->height = rt_init_value_size(split[3], "CY height");
	if (cylinder->height == -1)
		return (-1);
	if (rt_init_cylinder_rgb(cylinder, split[5]))
		return (-1);
	return (CY);
}
