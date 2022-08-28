/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_vector2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:15:56 by ccartet           #+#    #+#             */
/*   Updated: 2022/08/28 14:53:20 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

t_coord	rt_add_vec(t_coord v1, t_coord v2)
{
	float	x;
	float	y;
	float	z;

	x = v1.x + v2.x;
	y = v1.y + v2.y;
	z = v1.z + v2.z;
	return (create_vector(x, y, z));
}

t_coord	rt_sub_vec(t_coord v1, t_coord v2)
{
	float	x;
	float	y;
	float	z;

	x = v1.x - v2.x;
	y = v1.y - v2.y;
	z = v1.z - v2.z;
	return (create_vector(x, y, z));
}
// find vector : de v2 à v1 !!!

t_coord	rt_scale_vec(t_coord v, float m)
{
	float	x;
	float	y;
	float	z;

	x = v.x * m;
	y = v.y * m;
	z = v.z * m;
	return (create_vector(x, y, z));
}
// ici, on ne modifie pas la direction du vecteur, seulement sa magnitude / longueur

float	rt_dot_prod(t_coord v1, t_coord v2)
{
	t_coord	vector;
	float	x;
	float	y;
	float	z;

	x = v1.x * v2.x;
	y = v1.y * v2.y;
	z = v1.z * v2.z;
	vector = create_vector(x, y, z);
	return (vector.x + vector.y + vector.z);
}
// renvoie seulement la magnitude, peut servir à trouver des distances

t_coord	rt_cross_vec(t_coord v1, t_coord v2)
{
	float	x;
	float	y;
	float	z;

	x = v1.y * v2.z - v1.z * v2.y;
	y = v1.z * v2.x - v1.x * v2.z;
	z = v1.x * v2.y - v1.y * v2.z;
	return (create_vector(x, y, z));
}
// le résultat est un vecteur perpendiculaire aux deux vecteurs de base
// sert à trouver la normale d'une surface
