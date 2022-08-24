/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_vector1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:15:27 by ccartet           #+#    #+#             */
/*   Updated: 2022/08/24 11:15:28 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

float	vector_length(t_coord v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

float	vector_length_squared(t_coord v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

void	norm_vector(t_coord *v)
{
	float	length;

	length = vector_length(*v);
	v->x = v->x / length;
	v->y = v->y / length;
	v->z = v->z / length;
}
// normaliser un vecteur, c'est lui donner une magnitude de 1
// attention à la division par 0

t_coord	create_vector(float x, float y, float z)
{
	t_coord	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}
