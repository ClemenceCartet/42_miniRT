/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hooks.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:12:56 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/04 18:02:42 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_HOOKS_H
# define RT_HOOKS_H

# include <mini_rt.h>

/*/////////////////////////////////////////////////////////////////////////////
		HOOKS PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

/*-------------------- rt_hook_objects.c --------------------*/

int		rt_update_selected_object(int key, t_master *master, int object);
int		rt_update_selected_axis(int key);
void	rt_update_obj_pos(int key, t_master *master, int object, int axis);
void	rt_update_object_size(int key, t_master *master, int object);

/*-------------------- rt_hook_camera.c --------------------*/

void	rt_update_camera_pos(int key, t_master *master);
void	rt_update_camera_dir(int key, t_master *master);

/*-------------------- rt_manage_hooks.c --------------------*/

int		rt_exit_program(t_master *master);
// void	rt_object_hook_hub(int key, t_master *master);
// void	rt_camera_hook_hub(int key, t_master *master);
int		rt_key_hook_hub(int key, t_master *master);

#endif /* RT_HOOKS_H */