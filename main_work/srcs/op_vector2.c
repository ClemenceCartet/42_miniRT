/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_vector2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:15:56 by ccartet           #+#    #+#             */
/*   Updated: 2022/08/25 10:45:06 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

t_coord	add_vectors(t_coord v, t_coord u)
{
	return (create_vector(v.x + u.x, v.y + u.y, v.z + u.z));
}

t_coord	sub_vectors(t_coord v, t_coord u)
{
	return (create_vector(v.x - u.x, v.y - u.y, v.z - u.z));
}

t_coord	scale_vectors(t_coord v, t_coord u) // ou scale par un float ?
{
	return (create_vector(v.x * u.x, v.y * u.y, v.z * u.z)); // ou (v.x * u.x + v.y * u.y + v.z * u.z) pour obtenir un float
	// voir plus tard ce qui est le plus pratique
}
// ici, on ne modifie pas la direction du vecteur, seulement sa magnitude / longueur

t_coord	scale_vectors_bis(t_coord v, float f)
{
	return (create_vector(v.x * f, v.y * f, v.z * f));
}

t_coord	find_vector(t_coord a, t_coord b)
{
	return (create_vector(b.x - a.x, b.y - a.y, b.z - a.z));
}
// pour calculer un vecteur pointant de a vers b

t_coord	cross_vectors(t_coord v, t_coord u)
{
	return (create_vector(v.y * u.z - v.z * u.y,
		v.z * u.x - v.x * u.z, v.x * u.y - v.y * u.x));
}
// le résultat est un vecteur perpendiculaire aux deux vecteurs de base
// sert à trouver la normale d'une surface

float	dot_product(t_coord v, t_coord p)
{
	return (v.x * p.x + v.y * p.y + v.z * p.z);
}
// renvoie seulement la magnitude, peut servir à trouver des distances