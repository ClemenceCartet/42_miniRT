/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:44:04 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/02 11:14:36 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	display_split(char **split)
{
	int	a;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	a = 0;
	while (split[a])
	{
		dprintf(1, "%d | %s\n", a, split[a]);
		a++;
	}
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}

void	display_ambient(t_ambient *ambient)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "ambient->ratio : %f\n", ambient->ratio);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "ambient->rgb[0] : %d\n", ambient->rgb[0]);
	dprintf(STDOUT_FILENO, "ambient->rgb[1] : %d\n", ambient->rgb[1]);
	dprintf(STDOUT_FILENO, "ambient->rgb[2] : %d\n", ambient->rgb[2]);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}

void	display_camera(t_camera *camera)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "camera->p_xyz[0] : %f\n", camera->p_xyz[0]);
	dprintf(STDOUT_FILENO, "camera->p_xyz[1] : %f\n", camera->p_xyz[1]);
	dprintf(STDOUT_FILENO, "camera->p_xyz[2] : %f\n", camera->p_xyz[2]);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "camera->o_xyz[0] : %f\n", camera->o_xyz[0]);
	dprintf(STDOUT_FILENO, "camera->o_xyz[1] : %f\n", camera->o_xyz[1]);
	dprintf(STDOUT_FILENO, "camera->o_xyz[2] : %f\n", camera->o_xyz[2]);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "camera->fov : %d\n", camera->fov);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}

void	display_light(t_light *light)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "light->p_xyz[0] : %f\n", light->p_xyz[0]);
	dprintf(STDOUT_FILENO, "light->p_xyz[1] : %f\n", light->p_xyz[1]);
	dprintf(STDOUT_FILENO, "light->p_xyz[2] : %f\n", light->p_xyz[2]);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "light->ratio : %f\n", light->ratio);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "light->rgb[0] : %d\n", light->rgb[0]);
	dprintf(STDOUT_FILENO, "light->rgb[1] : %d\n", light->rgb[1]);
	dprintf(STDOUT_FILENO, "light->rgb[2] : %d\n", light->rgb[2]);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}

void	display_sphere(t_sphere *sphere)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "sphere->p_xyz[0] : %f\n", sphere->p_xyz[0]);
	dprintf(STDOUT_FILENO, "sphere->p_xyz[1] : %f\n", sphere->p_xyz[1]);
	dprintf(STDOUT_FILENO, "sphere->p_xyz[2] : %f\n", sphere->p_xyz[2]);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "sphere->diameter : %f\n", sphere->diameter);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "sphere->rgb[0] : %d\n", sphere->rgb[0]);
	dprintf(STDOUT_FILENO, "sphere->rgb[1] : %d\n", sphere->rgb[1]);
	dprintf(STDOUT_FILENO, "sphere->rgb[2] : %d\n", sphere->rgb[2]);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}

void	display_plane(t_plane *plane)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "plane->p_xyz[0] : %f\n", plane->p_xyz[0]);
	dprintf(STDOUT_FILENO, "plane->p_xyz[1] : %f\n", plane->p_xyz[1]);
	dprintf(STDOUT_FILENO, "plane->p_xyz[2] : %f\n", plane->p_xyz[2]);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "plane->o_xyz[0] : %f\n", plane->o_xyz[0]);
	dprintf(STDOUT_FILENO, "plane->o_xyz[1] : %f\n", plane->o_xyz[1]);
	dprintf(STDOUT_FILENO, "plane->o_xyz[2] : %f\n", plane->o_xyz[2]);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "plane->rgb[0] : %d\n", plane->rgb[0]);
	dprintf(STDOUT_FILENO, "plane->rgb[1] : %d\n", plane->rgb[1]);
	dprintf(STDOUT_FILENO, "plane->rgb[2] : %d\n", plane->rgb[2]);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}

void	display_cylinder(t_cylinder *cylinder)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "cylinder->p_xyz[0] : %f\n", cylinder->p_xyz[0]);
	dprintf(STDOUT_FILENO, "cylinder->p_xyz[1] : %f\n", cylinder->p_xyz[1]);
	dprintf(STDOUT_FILENO, "cylinder->p_xyz[2] : %f\n", cylinder->p_xyz[2]);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "cylinder->o_xyz[0] : %f\n", cylinder->o_xyz[0]);
	dprintf(STDOUT_FILENO, "cylinder->o_xyz[1] : %f\n", cylinder->o_xyz[1]);
	dprintf(STDOUT_FILENO, "cylinder->o_xyz[2] : %f\n", cylinder->o_xyz[2]);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "cylinder->diameter : %f\n", cylinder->diameter);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "cylinder->height : %f\n", cylinder->height);
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "cylinder->rgb[0] : %d\n", cylinder->rgb[0]);
	dprintf(STDOUT_FILENO, "cylinder->rgb[1] : %d\n", cylinder->rgb[1]);
	dprintf(STDOUT_FILENO, "cylinder->rgb[2] : %d\n", cylinder->rgb[2]);
	dprintf(STDOUT_FILENO, "\n---\n");
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
}

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
