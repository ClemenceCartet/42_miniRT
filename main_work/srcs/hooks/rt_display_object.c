/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_display_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:20:09 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/14 15:29:29 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

static void	rt_display_object_orientation(t_master *m)
{
	mlx_string_put(m->init, m->wdw, 200, 680, 0xFFFFFF, STR32);
	mlx_string_put(m->init, m->wdw, 200, 690, 0xFFDAB9, STR33);
	mlx_string_put(m->init, m->wdw, 200, 700, 0xFFDAB9, STR34);
	mlx_string_put(m->init, m->wdw, 200, 710, 0xFFDAB9, STR35);
	mlx_string_put(m->init, m->wdw, 200, 720, 0xFFDAB9, STR36);
}

static void	rt_display_object_info(t_master *m, int a)
{
	char	*str;

	mlx_string_put(m->init, m->wdw, 0, 700, 0xFFFFFF, STR26);
	mlx_string_put(m->init, m->wdw, 0, 710, 0xFFDAB9, STR27);
	if (m->obj_data->objects[a]->id == SP)
		mlx_string_put(m->init, m->wdw, 100, 710, 0x00FF00, STR28);
	else if (m->obj_data->objects[a]->id == PL)
		mlx_string_put(m->init, m->wdw, 100, 710, 0x00FF00, STR29);
	else if (m->obj_data->objects[a]->id == CY)
		mlx_string_put(m->init, m->wdw, 100, 710, 0x00FF00, STR30);
	str = ft_itoa(a);
	mlx_string_put(m->init, m->wdw, 0, 720, 0xFFDAB9, STR31);
	mlx_string_put(m->init, m->wdw, 60, 720, 0x00FF00, str);
	free (str);
}

//display the type and index of current selected object on mlx window
void	rt_display_selected_object(t_master *m)
{
	int		a;
	char	*str;

	a = 0;
	str = NULL;
	while (m->obj_data->objects[a])
	{
		if (m->obj_data->objects[a]->selected)
		{
			rt_display_object_info(m, a);
			if (m->obj_data->objects[a]->id == PL
				|| m->obj_data->objects[a]->id == CY)
				rt_display_object_orientation(m);
		}
		a++;
	}
}
