/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:38:48 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/13 16:17:09 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Rotation Up / Down
t_matrix	rt_matrix_rot_x(float rad)
{
	t_matrix	matrix;

	matrix = rt_init_matrix();
	matrix.y.y = cos(rad);
	matrix.y.z = sin(rad);
	matrix.z.y = -sin(rad);
	matrix.z.z = cos(rad);
	return (matrix);
}

//Rotation Left / Right
t_matrix	rt_matrix_rot_y(float rad)
{
	t_matrix	matrix;

	matrix = rt_init_matrix();
	matrix.x.x = cos(rad);
	matrix.x.z = -sin(rad);
	matrix.z.x = sin(rad);
	matrix.z.z = cos(rad);
	return (matrix);
}

//Tilt Left / Right
t_matrix	rt_matrix_rot_z(float rad)
{
	t_matrix	matrix;

	matrix = rt_init_matrix();
	matrix.x.x = cos(rad);
	matrix.x.y = sin(rad);
	matrix.y.x = -sin(rad);
	matrix.y.y = cos(rad);
	return (matrix);
}
