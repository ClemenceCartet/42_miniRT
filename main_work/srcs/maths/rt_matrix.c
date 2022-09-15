/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:31:57 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/15 11:25:36 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Multiplication of a matrix with a vector to get a new vector out of it
t_coord	rt_multiply_matrix_vector(t_matrix m, t_coord v)
{
	t_coord	newvec;

	newvec.x = m.x.x * v.x + m.y.x * v.y + m.z.x * v.z;
	newvec.y = m.x.y * v.x + m.y.y * v.y + m.z.y * v.z;
	newvec.z = m.x.z * v.x + m.y.z * v.y + m.z.z * v.z;
	return (newvec);
}

//Multiplication of source matrix and rotation matrix to set a new matrix
t_matrix	rt_multiply_matrix(t_matrix s, t_matrix r)
{
	t_matrix	newm;

	newm.x.x = s.x.x * r.x.x + s.x.y * r.y.x + s.x.z * r.z.x;
	newm.x.y = s.x.x * r.x.y + s.x.y * r.y.y + s.x.z * r.z.y;
	newm.x.z = s.x.x * r.x.z + s.x.y * r.y.z + s.x.z * r.z.z;
	newm.y.x = s.y.x * r.x.x + s.y.y * r.y.x + s.y.z * r.z.x;
	newm.y.y = s.y.x * r.x.y + s.y.y * r.y.y + s.y.z * r.z.y;
	newm.y.z = s.y.x * r.x.z + s.y.y * r.y.z + s.y.z * r.z.z;
	newm.z.x = s.z.x * r.x.x + s.z.y * r.y.x + s.z.z * r.z.x;
	newm.z.y = s.z.x * r.x.y + s.z.y * r.y.y + s.z.z * r.z.y;
	newm.z.z = s.z.x * r.x.z + s.z.y * r.y.z + s.z.z * r.z.z;
	return (newm);
}

//Set a particular vector to a given identity for matrix purposes
t_coord	rt_set_vector_identity(int id)
{
	t_coord	identity;

	identity.x = 0.0;
	identity.y = 0.0;
	identity.z = 0.0;
	if (id == ID_X)
		identity.x = 1.0;
	else if (id == ID_Y)
		identity.y = 1.0;
	else if (id == ID_Z)
		identity.z = 1.0;
	return (identity);
}

//Matrix initialization for object and camera (C / Pl / CY)
t_matrix	rt_init_matrix(void)
{
	t_matrix	matrix;

	matrix.x = rt_set_vector_identity(ID_X);
	matrix.y = rt_set_vector_identity(ID_Y);
	matrix.z = rt_set_vector_identity(ID_Z);
	return (matrix);
}
