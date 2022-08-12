/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:17:51 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/12 14:48:35 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Light initialization (L)
int	rt_init_light(t_light **light, char **split)
{
	if (rt_check_ptr(*light, split))
		return (1);
	if (ft_splitlen(split) != 4)
		return (rt_return_int_error(split, NULL, E_SPLITLEN, "Light"));
	*light = rt_calloc_struct(sizeof(t_light), split);
	if (!*light)
		return (1);
	(*light)->pos = rt_init_coords(split, split[1], 0);
	if (!(*light)->pos)
		return (1);
	(*light)->ratio = rt_init_ratio(split, split[2]);
	if ((*light)->ratio == -1)
		return (1);
	(*light)->rgb = rt_init_rgb(split, split[3]);
	if (!(*light)->rgb)
		return (1);
	ft_free_split(split);
	return (0);
}

//Camera initialization (C)
int	rt_init_camera(t_camera **camera, char **split)
{
	if (rt_check_ptr(*camera, split))
		return (1);
	if (ft_splitlen(split) != 4)
		return (rt_return_int_error(split, NULL, E_SPLITLEN, "Camera"));
	*camera = rt_calloc_struct(sizeof(t_camera), split);
	if (!*camera)
		return (1);
	(*camera)->pos = rt_init_coords(split, split[1], 0);
	if (!(*camera)->pos)
		return (1);
	(*camera)->dir = rt_init_coords(split, split[2], 1);
	if (!(*camera)->dir)
		return (1);
	(*camera)->fov = rt_init_fov(split, split[3]);
	if ((*camera)->fov == -1)
		return (1);
	(*camera)->radian = rt_init_radian((*camera)->fov); //function needed
	ft_free_split(split);
	return (0);
}
