/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_item_cylinder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:42:59 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:42:49 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create Cylinder structure to put in the object list while checking errors
void	*rt_parse_cylinder(int *object_id, char **split)
{
	t_cylinder	*cylinder;

	cylinder = rt_init_object_ptr(split, 6, "Cylinder");
	*object_id = rt_init_cylinder_values(cylinder, split);
	return (cylinder);
}
