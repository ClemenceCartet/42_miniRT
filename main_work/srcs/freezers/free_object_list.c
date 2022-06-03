/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_object_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:58:54 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 09:28:44 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Function to free every link of the object list and the object struct itself
void	rt_free_object_list(t_object *object)
{
	void		*tmp;
	t_obj_link	*obj_link;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	test_object_list_values(object);
	tmp = NULL;
	object->lst = object->start;
	while (object->lst)
	{
		obj_link = object->lst->content;
		free(obj_link->object_ptr);
		free(obj_link);
		tmp = object->lst;
		object->lst = object->lst->next;
		free(tmp);
	}
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}
