/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_item_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:43:29 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:43:07 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create Sphere structure to put in the object list while checking errors
void	*rt_parse_sphere(int *object_id, char **split)
{
	t_sphere	*sphere;

	sphere = rt_init_object_ptr(split, 4, "Sphere");
	if (!sphere)
		return (NULL);
	*object_id = rt_init_sphere_values(sphere, split);
	return (sphere);
}
