/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_item_cylinder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:42:59 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 14:26:10 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create Cylinder structure to put in the object list while checking errors
void	*rt_parse_cylinder(int *object_id, char **split)
{
	t_cylinder	*cylinder;

	cylinder = rt_init_object_ptr(split, 6, "Cylinder");
	if (!cylinder)
		return (NULL);
	*object_id = rt_init_item_cylinder(cylinder, split);
	if (*object_id == -1)
	{
		free(cylinder);
		return (NULL);
	}
	return (cylinder);
}
