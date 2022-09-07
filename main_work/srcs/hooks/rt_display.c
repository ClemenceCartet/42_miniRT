/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:25:54 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/07 13:49:34 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Display camera  commands on mlx screen
static void	rt_display_camera_commands(t_master *master)
{
	mlx_string_put(master->init, master->wdw, 0, 10, 0xFFFFFF, STR1);
	mlx_string_put(master->init, master->wdw, 0, 20, 0xFFDAB9, STR2);
	mlx_string_put(master->init, master->wdw, 0, 30, 0xFFDAB9, STR3);
	mlx_string_put(master->init, master->wdw, 0, 40, 0xFFDAB9, STR4);
	mlx_string_put(master->init, master->wdw, 0, 50, 0xFFDAB9, STR5);
	mlx_string_put(master->init, master->wdw, 0, 60, 0xFF0000, STR6);
	mlx_string_put(master->init, master->wdw, 0, 70, 0xFF0000, STR7);
	mlx_string_put(master->init, master->wdw, 120, 10, 0xFFFFFF, STR8);
	mlx_string_put(master->init, master->wdw, 120, 20, 0xFF0000, STR9);
	mlx_string_put(master->init, master->wdw, 120, 30, 0xFF0000, STR10);
	mlx_string_put(master->init, master->wdw, 120, 40, 0xFF0000, STR11);
	mlx_string_put(master->init, master->wdw, 120, 50, 0xFF0000, STR12);
}

//Display selection commands on mlx screen
static void	rt_display_select_commands(t_master *master)
{
	mlx_string_put(master->init, master->wdw, 250, 10, 0xFFFFFF, STR13);
	mlx_string_put(master->init, master->wdw, 250, 20, 0xFFDAB9, STR14);
	mlx_string_put(master->init, master->wdw, 250, 30, 0xFFDAB9, STR15);
	mlx_string_put(master->init, master->wdw, 250, 40, 0xFFDAB9, STR16);
	mlx_string_put(master->init, master->wdw, 360, 10, 0xFFFFFF, STR17);
	mlx_string_put(master->init, master->wdw, 360, 20, 0xFFDAB9, STR18);
	mlx_string_put(master->init, master->wdw, 360, 30, 0xFFDAB9, STR19);
	mlx_string_put(master->init, master->wdw, 360, 40, 0xFFDAB9, STR20);
}

//Display modification commands on mlx screen
static void	rt_display_modif_commands(t_master *master)
{
	mlx_string_put(master->init, master->wdw, 550, 10, 0xFFFFFF, STR21);
	mlx_string_put(master->init, master->wdw, 550, 20, 0xFFDAB9, STR22);
	mlx_string_put(master->init, master->wdw, 550, 30, 0xFFDAB9, STR23);
	mlx_string_put(master->init, master->wdw, 800, 10, 0xFFFFFF, STR24);
	mlx_string_put(master->init, master->wdw, 800, 20, 0xFFDAB9, STR25);
	mlx_string_put(master->init, master->wdw, 800, 30, 0xFFDAB9, STR26);
	mlx_string_put(master->init, master->wdw, 1030, 10, 0xFFFFFF, STR27);
	mlx_string_put(master->init, master->wdw, 1030, 20, 0xFFDAB9, STR28);
	mlx_string_put(master->init, master->wdw, 1030, 30, 0xFFDAB9, STR29);
}

//Call all UI display functions for UX purpose
void	rt_display_info(t_master *master)
{
	rt_display_camera_commands(master);
	rt_display_select_commands(master);
	rt_display_modif_commands(master);
}
