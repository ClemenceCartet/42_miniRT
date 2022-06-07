/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_item_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:57:00 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:41:55 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Initialize every values of structure plane to 0
int	rt_init_item_plane(t_plane *plane, char **split)
{
	plane->p_xyz[0] = 0;
	plane->p_xyz[1] = 0;
	plane->p_xyz[2] = 0;
	plane->o_xyz[0] = 0;
	plane->o_xyz[1] = 0;
	plane->o_xyz[2] = 0;
	plane->rgb[0] = 0;
	plane->rgb[1] = 0;
	plane->rgb[2] = 0;
	return (PL);
}
