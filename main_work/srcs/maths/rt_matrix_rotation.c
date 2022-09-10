/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:38:48 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/10 14:28:53 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Rotation Up / Down
t_matrix	rt_matrix_rot_x(int degree)
{
	t_matrix	matrix;
	float		radians;

	if (degree == 360 || degree == -360)
		degree = 0;
	radians = degree * M_PI / 180;
	matrix = rt_init_matrix();
	matrix.y.y = cos(radians);
	matrix.y.z = sin(radians);
	matrix.z.y = -sin(radians);
	matrix.z.z = cos(radians);
	return (matrix);
}

//Rotation Left / Right
t_matrix	rt_matrix_rot_y(int degree)
{
	t_matrix	matrix;
	float		radians;

	if (degree == 360 || degree == -360)
		degree = 0;
	radians = degree * M_PI / 180;
	matrix = rt_init_matrix();
	matrix.x.x = cos(radians);
	matrix.x.z = -sin(radians);
	matrix.z.x = sin(radians);
	matrix.z.z = cos(radians);
	return (matrix);
}

//Tilt Left / Right
t_matrix	rt_matrix_rot_z(int degree)
{
	t_matrix	matrix;
	float		radians;

	if (degree == 360 || degree == -360)
		degree = 0;
	radians = degree * M_PI / 180;
	matrix = rt_init_matrix();
	matrix.x.x = cos(radians);
	matrix.x.y = sin(radians);
	matrix.y.x = -sin(radians);
	matrix.y.y = cos(radians);
	return (matrix);
}
