/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_free_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:40:06 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/02 10:40:06 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Free ambient light structure
void	rt_free_ambient(t_ambient *ambient)
{
	if (ambient)
	{
		if (ambient->rgb)
		{
			free (ambient->rgb);
			ambient->rgb = NULL;
		}
		free (ambient);
		ambient = NULL;
	}
}

//Free camera structure
void	rt_free_camera(t_camera *camera)
{
	if (camera)
	{
		if (camera->pos)
		{
			free (camera->pos);
			camera->pos = NULL;
		}
		if (camera->dir)
		{
			free (camera->dir);
			camera->dir = NULL;
		}
		free (camera);
		camera = NULL;
	}
}

//Free Light structure
void	rt_free_light(t_light *light)
{
	if (light)
	{
		if (light->pos)
		{
			free (light->pos);
			light->pos = NULL;
		}
		if (light->rgb)
		{
			free (light->rgb);
			light->rgb = NULL;
		}
		free (light);
		light = NULL;
	}
}

//Free data of an object from obj_data->lst
void	rt_free_object(t_object *object)
{
	if (object)
	{
		if (object->pos)
		{
			free (object->pos);
			object->pos = NULL;
		}
		if (object->dir)
		{
			free (object->dir);
			object->dir = NULL;
		}
		if (object->rgb)
		{
			free (object->rgb);
			object->rgb = NULL;
		}
		free (object);
		object = NULL;
	}
}
