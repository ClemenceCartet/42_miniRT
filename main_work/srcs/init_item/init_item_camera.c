/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_item_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:55:55 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:41:39 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


// Initialize every values of structure camera to 0
void	rt_init_item_camera(t_camera *camera, char **split)
{
	camera->p_xyz[0] = 0;
	camera->p_xyz[1] = 0;
	camera->p_xyz[2] = 0;
	camera->o_xyz[0] = 0;
	camera->o_xyz[1] = 0;
	camera->o_xyz[2] = 0;
	camera->fov = 0;
}
