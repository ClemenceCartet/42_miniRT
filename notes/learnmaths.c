/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learnmaths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:56:13 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/09 08:17:51 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// degree = radian * 180 / PI = rot
// radian = degree * PI / 180

//rotation haut/bas
void	rot_x(t_matrix *mat, float rot, int isradian)
{
	if (isradian)
		rot = rot * 180 / M_PI;
	mat->x.x = 1;
	mat->x.y = 0;
	mat->x.z = 0;
	mat->y.x = 0;
	mat->y.y = cos(rot);
	mat->y.z = sin(rot);
	mat->z.x = 0;
	mat->z.y = asin(rot);
	mat->z.z = cos(rot);
}

//rotation gauche/droite
void	rot_y(t_matrix *mat, float rot, int isradian)
{
	if (isradian)
		rot = rot * 180 / M_PI;
	mat->x.x = cos(rot);
	mat->x.y = 0;
	mat->x.z = asin(rot);
	mat->y.x = 0;
	mat->y.y = 1;
	mat->y.z = 0;
	mat->z.x = sin(rot);
	mat->z.y = 0;
	mat->z.z = cos(rot);
}

//tangage gauche/droite
void	rot_z(t_matrix *mat, float rot, int isradian)
{
	if (isradian)
		rot = rot * 180 / M_PI;
	mat->x.x = cos(rot);
	mat->x.y = sin(rot);
	mat->x.z = 0;
	mat->y.x = asin(rot);
	mat->y.y = cos(rot);
	mat->y.z = 0;
	mat->z.x = 0;
	mat->z.y = 0;
	mat->z.z = 1;
}

void	scale(t_matrix *mat, float scale)
{
	mat->x.x *= scale;
	mat->x.y *= scale;
	mat->x.z *= scale;
	mat->y.x *= scale;
	mat->y.y *= scale;
	mat->y.z *= scale;
	mat->z.x *= scale;
	mat->z.y *= scale;
	mat->z.z *= scale;
}
