/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:43:29 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 11:45:32 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create Sphere structure to put in the object list while checking errors
void	*rt_parse_sphere(int *object_id, char **split)
{
	t_sphere	*sphere;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// test_split_values(split);
	sphere = rt_init_object_ptr(split, 4, "Sphere");
	if (!sphere)
		return (NULL);
	*object_id = rt_init_sphere_values(sphere, split);
	dprintf(STDOUT_FILENO, "object_id: %d\n", *object_id);
	// test_sphere_values(sphere);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (sphere);
}
