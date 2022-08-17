/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_maths.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:19:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/17 08:51:13 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATHS_H
# define RT_MATHS_H

# include <mini_rt.h>

/*/////////////////////////////////////////////////////////////////////////////
		MAIN STRUCTURES
*//////////////////////////////////////////////////////////////////////////////

struct	s_ray
{
	t_coord	origin;
	t_coord	dir;
	float	time;
	t_coord	hit;
	t_coord	normal;
	t_color	color;
	int		object_id;
};

struct	s_matrix
{
	float	x_x;
	float	x_y;
	float	x_z;

	float	y_x;
	float	y_y;
	float	y_z;

	float	z_x;
	float	z_y;
	float	z_z;
};

#endif /* RT_MATHS */