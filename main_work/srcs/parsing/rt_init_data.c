/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:17:51 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/24 15:28:35 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Check object ID to init correct object data
static t_object	*rt_obj_data_hub(char **split)
{
	if (!ft_strncmp(split[0], "sp", 3))
		return (rt_init_sphere(split));
	else if (!ft_strncmp(split[0], "pl", 3))
		return (rt_init_plane(split));
	else if (!ft_strncmp(split[0], "cy", 3))
		return (rt_init_cylinder(split));
	return (NULL);
}

//Object initialization (SP / PL / CY)
int	rt_init_obj_data(t_obj_data **obj_data, char **split)
{
	t_object	*object;

	object = NULL;
	if (!*obj_data)
	{
		*obj_data = rt_calloc_struct(sizeof(t_obj_data), split);
		if (!*obj_data)
			return (1);
		(*obj_data)->lst = NULL;
		(*obj_data)->lst_size = 0;
		(*obj_data)->objects = NULL;
	}
	object = rt_obj_data_hub(split);
	if (!object)
		return (1);
	ft_free_split(split);
	ft_lstadd_back(&(*obj_data)->lst, ft_lstnew(object));
	if (!(*obj_data)->lst_size)
		(*obj_data)->start = (*obj_data)->lst;
	(*obj_data)->lst_size++;
	return (0);
}

//Light initialization (L)
int	rt_init_light(t_light **light, char **split)
{
	if (rt_check_ptr(*light, split))
		return (1);
	if (ft_splitlen(split) != 3)
		return (rt_ret_int_error(split, NULL, E_SPLITLEN, "Light"));
	*light = rt_calloc_struct(sizeof(t_light), split);
	if (!*light)
		return (1);
	(*light)->pos = rt_init_coords(split, split[1], 0);
	if (!(*light)->pos)
		return (1);
	(*light)->ratio = rt_init_ratio(split, split[2]);
	if ((*light)->ratio == -1)
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
		return (rt_ret_int_error(split, NULL, E_SPLITLEN, "Camera"));
	*camera = rt_calloc_struct(sizeof(t_camera), split);
	if (!*camera)
		return (1);
	(*camera)->pos = rt_init_coords(split, split[1], 0);
	if (!(*camera)->pos)
		return (1);
	(*camera)->dir = rt_init_coords(split, split[2], 1);
	if (!(*camera)->dir)
		return (1);
	if (rt_vector_length(*(*camera)->dir) > 1.0)
		return (1);
	(*camera)->fov = rt_init_fov(split, split[3]);
	if ((*camera)->fov == -1)
		return (1);
	ft_free_split(split);
	return (0);
}

//Ambient Light initialization (A)
int	rt_init_ambient(t_ambient **ambient, char **split)
{
	if (rt_check_ptr(*ambient, split))
		return (1);
	if (ft_splitlen(split) != 3)
		return (rt_ret_int_error(split, NULL, E_SPLITLEN, "Ambient Light"));
	*ambient = rt_calloc_struct(sizeof(t_ambient), split);
	if (!*ambient)
		return (1);
	(*ambient)->ratio = rt_init_ratio(split, split[1]);
	if ((*ambient)->ratio == -1)
		return (1);
	(*ambient)->rgb = rt_init_rgb(split, split[2]);
	if (!(*ambient)->rgb)
		return (1);
	ft_free_split(split);
	return (0);
}
