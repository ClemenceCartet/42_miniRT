/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:05:08 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/17 08:47:52 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Initialization of object data (SP / PL / CY)
void	*rt_init_object(char **split, size_t splitsize, char *name)
{
	t_object	*object;

	object = NULL;
	if (ft_splitlen(split) != splitsize)
		return (rt_return_ptr_error(split, NULL, E_SPLITLEN, name));
	object = rt_calloc_struct(sizeof(t_object), split);
	if (!object)
		return (NULL);
	if (!ft_strncmp(split[0], "sp", 3))
		object->id = SP;
	else if (!ft_strncmp(split[0], "pl", 3))
		object->id = PL;
	else if (!ft_strncmp(split[0], "cy", 3))
		object->id = CY;
	object->pos = NULL;
	object->dir = NULL;
	object->rgb = NULL;
	object->diameter = 0.0;
	object->radius = 0.0;
	object->height = 0.0;
	return (object);
}

//Sphere initialization (SP)
void	*rt_init_sphere(char **split)
{
	t_object	*object;

	object = rt_init_object(split, 4, "sphere");
	if (!object)
		return (NULL);
	object->pos = rt_init_coords(split, split[1], 0);
	if (!object->pos)
		return (rt_free_object(object));
	object->diameter = rt_init_obj_size(split, split[2]);
	if (object->diameter == -1)
		return (rt_free_object(object));
	object->radius = object->diameter * 0.5; //will be moved in init_additional_data
	object->rgb = rt_init_rgb(split, split[3]);
	if (!object->rgb)
		return (rt_free_object(object));
	return (object);
}

//Plane initialization (PL)
void	*rt_init_plane(char **split)
{
	t_object	*object;

	object = rt_init_object(split, 4, "plane");
	if (!object)
		return (NULL);
	object->pos = rt_init_coords(split, split[1], 0);
	if (!object->pos)
		return (rt_free_object(object));
	object->dir = rt_init_coords(split, split[2], 1);
	if (!object->dir)
		return (rt_free_object(object));
	object->rgb = rt_init_rgb(split, split[3]);
	if (!object->rgb)
		return (rt_free_object(object));
	return (object);
}

//Cylinder initialization (CY)
void	*rt_init_cylinder(char **split)
{
	t_object	*object;

	object = rt_init_object(split, 6, "cylinder");
	if (!object)
		return (NULL);
	object->pos = rt_init_coords(split, split[1], 0);
	if (!object->pos)
		return (rt_free_object(object));
	object->dir = rt_init_coords(split, split[2], 1);
	if (!object->dir)
		return (rt_free_object(object));
	object->diameter = rt_init_obj_size(split, split[3]);
	if (object->diameter == -1)
		return (rt_free_object(object));
	object->height = rt_init_obj_size(split, split[4]);
	if (object->height == -1)
		return (rt_free_object(object));
	object->rgb = rt_init_rgb(split, split[5]);
	if (!object->rgb)
		return (rt_free_object(object));
	return (object);
}
