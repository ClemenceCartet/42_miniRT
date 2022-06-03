/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_object_list_values.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:02:58 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 09:03:03 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	display_object_list(t_object *object)
{
	t_obj_link	*obj_link;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	object->lst = object->start;
	dprintf(STDOUT_FILENO, "lst_size : %zu\n", object->lst_size);
	while (object->lst)
	{
		obj_link = object->lst->content;
		dprintf(STDOUT_FILENO, "object id : %d\n", obj_link->id);
		dprintf(STDOUT_FILENO, "(SP = 1 | PL = 2 | CY = 3)\n");
		if (obj_link->id == SP)
			display_sphere(obj_link->object_ptr);
		else if (obj_link->id == PL)
			display_plane(obj_link->object_ptr);
		else if (obj_link->id == CY)
			display_cylinder(obj_link->object_ptr);
		object->lst = object->lst->next;
	}
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}
