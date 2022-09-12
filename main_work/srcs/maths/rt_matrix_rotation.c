/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:38:48 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/12 11:21:19 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Rotation Up / Down
t_matrix	rt_matrix_rot_x(float degree)
{
	t_matrix	matrix;
	float		radians;

	radians = degree * M_PI / 180;
	matrix = rt_init_matrix();
	matrix.y.y = cos(radians);
	matrix.y.z = sin(radians);
	matrix.z.y = -sin(radians);
	matrix.z.z = cos(radians);
	//dprintf(2, "new_z:%.2f, %.2f, %.2f, %.2f\n", matrix.y.y, matrix.y.z, matrix.z.y, matrix.z.z);
	return (matrix);
}

//Rotation Left / Right
t_matrix	rt_matrix_rot_y(float degree)
{
	t_matrix	matrix;
	float		radians;

	radians = degree * M_PI / 180;
	matrix = rt_init_matrix();
	matrix.x.x = cos(radians);
	matrix.x.z = -sin(radians);
	matrix.z.x = sin(radians);
	matrix.z.z = cos(radians);
	return (matrix);
}

//Tilt Left / Right
t_matrix	rt_matrix_rot_z(float degree)
{
	t_matrix	matrix;
	float		radians;

	radians = degree * M_PI / 180;
	matrix = rt_init_matrix();
	matrix.x.x = cos(radians);
	matrix.x.y = sin(radians);
	matrix.y.x = -sin(radians);
	matrix.y.y = cos(radians);
	return (matrix);
}

//Call every rotations and then multiply the three matrix given
t_matrix	rt_matrix_rotate(t_coord vec)
{
	t_matrix	m_src;
	t_matrix	m_x;
	t_matrix	m_y;
	t_matrix	m_z;

	m_x = rt_matrix_rot_x(vec.x);
	m_y = rt_matrix_rot_y(vec.y);
	m_z = rt_matrix_rot_z(vec.z); // m_z = rt_matrix_rot_z(acos(vec.z) * 180 / M_PI);
	m_src = rt_multiply_matrix(m_z, m_y);
	m_src = rt_multiply_matrix(m_src, m_x);
	return (m_src);
}

// t_coord	rt_rotate_test(t_matrix m, t_coord baseray, t_camera cam)
// {
// 	t_coord	tmpvec;
// 	t_coord	rotate;

// 	tmpvec = rt_set_vector_identity(ID_X);
// 	m.y = *cam.dir;
// 	m.x = rt_cross_vec(tmpvec, m.y);
// 	m.z = rt_cross_vec(m.y, m.x);
// 	rotate = rt_multiply_matrix_vector(m, baseray);
// 	return (rotate);
// }
