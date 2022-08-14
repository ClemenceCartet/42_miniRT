/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:17:51 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/13 17:47:15 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

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
	}
	if (!ft_strncmp(split[0], "sp", 3))
		object = rt_init_sphere(split);
	else if (!ft_strncmp(split[0], "pl", 3))
		object = rt_init_plane(split);
	else if (!ft_strncmp(split[0], "cy", 3))
		object = rt_init_cylinder(split);
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
	(*camera)->radian = (*camera)->fov * M_PI / 180;
	rt_init_ratios(*camera);
	(*camera)->rot_x = 0.0;
	(*camera)->rot_z = 0.0;
	ft_free_split(split);
	return (0);
}

void	rt_init_ratios(t_camera *cam)
{	
	cam->ratio_H = (2 * tan(cam->radian * 0.5)) / W;
	cam->ratio_V = (2 * tan(cam->radian * H / (W * 2))) / H;
}

//Ambient Light initialization (A)
int	rt_init_ambient(t_ambient **ambient, char **split)
{
	if (rt_check_ptr(*ambient, split))
		return (1);
	if (ft_splitlen(split) != 3)
		return (rt_return_int_error(split, NULL, E_SPLITLEN, "Ambient Light"));
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
