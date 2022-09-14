/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_op_vector1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42ly   		    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:15:27 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/07 17:21:59 by ccartet	      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

float	rt_vector_length(t_coord v)
{
	return (sqrt(rt_vec_length_sqr(v)));
}

float	rt_vec_length_sqr(t_coord v)
{
	float	x;
	float	y;
	float	z;

	x = v.x * v.x;
	y = v.y * v.y;
	z = v.z * v.z;
	return (x + y + z);
}

void	rt_norm_vector(t_coord *v)
{
	float	length;

	length = rt_vector_length(*v);
	v->x = v->x / length;
	v->y = v->y / length;
	v->z = v->z / length;
}
// normaliser un vecteur, c'est lui donner une magnitude de 1
// attention à la division par 0

t_coord	rt_create_vector(float x, float y, float z)
{
	t_coord	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}
