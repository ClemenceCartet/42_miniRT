/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:32:55 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/07 14:00:35 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Initialization of object (SP / PL / CY)
void	*rt_init_object(char **split, size_t splitlen, char *name)
{
	t_object	*object;

	object = NULL;
	if (rt_check_struct(object, split, splitlen, name))
		return (NULL);
	object = rt_calloc_struct(split, sizeof(t_object));
	if (!object)
		return (NULL);
	if (!ft_strncmp(name, "sphere", 7))
		object->id = SP;
	else if (!ft_strncmp(name, "plane", 6))
		object->id = PL;
	else if (!ft_strncmp(name, "cylinder", 9))
		object->id = CY;
	object->pos = NULL;
	object->dir = NULL;
	object->rgb = NULL;
	object->diameter = 0;
	object->height = 0;
	return (object);
}

//Initialization of sphere SP data
void	*rt_init_sphere(char **split)
{
	t_object	*object;

	object = rt_init_object(split, 4, "sphere");
	if (!object)
		return (NULL);
	object->pos = rt_init_coords(split[1], 0);
	if (!object->pos)
		return (rt_free_object(object));
	object->diameter = ft_atof(split[2]);
	if (rt_check_float(object->diameter, split, 0))
		return (rt_free_object(object));
	object->rgb = rt_init_rgb(split[3]);
	if (!object->rgb)
		return (rt_free_object(object));
	return (object);
}

//Initialization of plane PL data
void	*rt_init_plane(char **split)
{
	t_object	*object;

	object = rt_init_object(split, 4, "plane");
	if (!object)
		return (NULL);
	object->pos = rt_init_coords(split[1], 0);
	if (!object->pos)
		return (rt_free_object(object));
	object->dir = rt_init_coords(split[2], 1);
	if (!object->dir)
		return (rt_free_object(object));
	object->rgb = rt_init_rgb(split[3]);
	if (!object->rgb)
		return (rt_free_object(object));
	return (object);
}

//Initialization of cylinder CY data
void	*rt_init_cylinder(char **split)
{
	t_object	*object;

	object = rt_init_object(split, 6, "cylinder");
	if (!object)
		return (NULL);
	object->pos = rt_init_coords(split[1], 0);
	if (!object->pos)
		return (rt_free_object(object));
	object->dir = rt_init_coords(split[2], 1);
	if (!object->dir)
		return (rt_free_object(object));
	object->diameter = ft_atof(split[3]);
	object->height = ft_atof(split[4]);
	if (rt_check_float(object->diameter, split, 0))
		return (rt_free_object(object));
	if (rt_check_float(object->height, split, 0))
		return (rt_free_object(object));
	object->rgb = rt_init_rgb(split[5]);
	if (!object->rgb)
		return (rt_free_object(object));
	return (object);
}
