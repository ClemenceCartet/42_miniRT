/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:39:06 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/02 10:39:06 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Iterate on t_list to free all object structures
void	rt_free_obj_data(t_obj_data *obj_data)
{
	void	*tmp;

	tmp = NULL;
	if (obj_data)
	{
		obj_data->lst = obj_data->start;
		while (obj_data->lst)
		{
			tmp = obj_data->lst;
			if (obj_data->lst->content)
				rt_free_object(obj_data->lst->content);
			obj_data->lst = obj_data->lst->next;
			free (tmp);
			tmp = NULL;
		}
		if (obj_data->objects)
			free (obj_data->objects);
		free (obj_data);
		obj_data = NULL;
	}
}

//Function hub to free every structures of the program
int	rt_free_master(t_master *master)
{
	if (master)
	{
		if (master->mlx)
			free (master->mlx);
		if (master->obj_data)
			rt_free_obj_data(master->obj_data);
		if (master->ambient)
			rt_free_ambient(master->ambient);
		if (master->camera)
			rt_free_camera(master->camera);
		if (master->light)
			rt_free_light(master->light);
	}
	return (0);
}
