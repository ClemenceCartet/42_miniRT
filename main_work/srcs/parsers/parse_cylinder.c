/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:42:59 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 11:44:52 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Create Cylinder structure to put in the object list while checking errors
void	*rt_parse_cylinder(int *object_id, char **split)
{
	t_cylinder	*cylinder;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// test_split_values(split);
	cylinder = rt_init_object_ptr(split, 6, "Cylinder");
	*object_id = rt_init_cylinder_values(cylinder, split);
	dprintf(STDOUT_FILENO, "object_id: %d\n", *object_id);
	// test_cylinder_values(cylinder);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (cylinder);
}
