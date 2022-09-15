/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:25:54 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/15 14:13:06 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	rt_display_selection(t_master *m, int axis_val, int size_val)
{
	static int	axis = -1;
	static int	size = -1;

	if (axis_val != -1)
		axis = axis_val;
	if (size_val != -1)
		size = size_val;
	if (axis != -1)
	{
		mlx_string_put(m->init, m->wdw, 0, 680, 0xFFDAB9, STR37);
		if (axis == AXIS_X)
			mlx_string_put(m->init, m->wdw, 120, 680, 0x00FF00, "X");
		else if (axis == AXIS_Y)
			mlx_string_put(m->init, m->wdw, 120, 680, 0x00FF00, "Y");
		else if (axis == AXIS_Z)
			mlx_string_put(m->init, m->wdw, 120, 680, 0x00FF00, "Z");
	}
	if (size != -1)
	{
		mlx_string_put(m->init, m->wdw, 0, 690, 0xFFDAB9, STR38);
		if (size == SIZE_D)
			mlx_string_put(m->init, m->wdw, 120, 690, 0x00FF00, STR39);
		else if (size == SIZE_H)
			mlx_string_put(m->init, m->wdw, 120, 690, 0x00FF00, STR40);
	}
}

//Display camera  commands on mlx window
static void	rt_display_camera_commands(t_master *master)
{
	mlx_string_put(master->init, master->wdw, 0, 10, 0xFFFFFF, STR1);
	mlx_string_put(master->init, master->wdw, 0, 20, 0xFFDAB9, STR2);
	mlx_string_put(master->init, master->wdw, 0, 30, 0xFFDAB9, STR3);
	mlx_string_put(master->init, master->wdw, 120, 10, 0xFFFFFF, STR4);
	mlx_string_put(master->init, master->wdw, 120, 20, 0xFFDAB9, STR7);
	mlx_string_put(master->init, master->wdw, 120, 30, 0xFFDAB9, STR8);
}

//Display selection commands on mlx window
static void	rt_display_select_commands(t_master *master)
{
	mlx_string_put(master->init, master->wdw, 250, 10, 0xFFFFFF, STR9);
	mlx_string_put(master->init, master->wdw, 250, 20, 0xFFDAB9, STR10);
	mlx_string_put(master->init, master->wdw, 250, 30, 0xFFDAB9, STR11);
	mlx_string_put(master->init, master->wdw, 250, 40, 0xFFDAB9, STR12);
	mlx_string_put(master->init, master->wdw, 360, 10, 0xFFFFFF, STR13);
	mlx_string_put(master->init, master->wdw, 360, 20, 0xFFDAB9, STR14);
	mlx_string_put(master->init, master->wdw, 360, 30, 0xFFDAB9, STR15);
	mlx_string_put(master->init, master->wdw, 360, 40, 0xFFDAB9, STR16);
	mlx_string_put(master->init, master->wdw, 550, 10, 0xFFFFFF, STR17);
	mlx_string_put(master->init, master->wdw, 550, 20, 0xFFDAB9, STR18);
	mlx_string_put(master->init, master->wdw, 550, 30, 0xFFDAB9, STR19);
	mlx_string_put(master->init, master->wdw, 800, 10, 0xFFFFFF, STR20);
	mlx_string_put(master->init, master->wdw, 800, 20, 0xFFDAB9, STR21);
	mlx_string_put(master->init, master->wdw, 800, 30, 0xFFDAB9, STR22);
	mlx_string_put(master->init, master->wdw, 1030, 10, 0xFFFFFF, STR23);
	mlx_string_put(master->init, master->wdw, 1030, 20, 0xFFDAB9, STR24);
	mlx_string_put(master->init, master->wdw, 1030, 30, 0xFFDAB9, STR25);
}

//Call all UI display functions for UX purpose on mlx window
void	rt_display_info(t_master *master)
{
	rt_display_camera_commands(master);
	rt_display_select_commands(master);
	rt_display_selected_object(master);
	rt_display_selection(master, -1, -1);
}
