/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learnmaths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:56:13 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/09 12:14:40 by ljohnson         ###   ########lyon.fr   */
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
	mat->x.x = ((mat->x.x - mat->t.x) * scale) + mat->t.x;
	mat->x.y = ((mat->x.y - mat->t.x) * scale) + mat->t.x;
	mat->x.z = ((mat->x.z - mat->t.x) * scale) + mat->t.x;
	mat->y.x = ((mat->y.x - mat->t.y) * scale) + mat->t.y;
	mat->y.y = ((mat->y.y - mat->t.y) * scale) + mat->t.y;
	mat->y.z = ((mat->y.z - mat->t.y) * scale) + mat->t.y;
	mat->z.x = ((mat->z.x - mat->t.z) * scale) + mat->t.z;
	mat->z.y = ((mat->z.y - mat->t.z) * scale) + mat->t.z;
	mat->z.z = ((mat->z.z - mat->t.z) * scale) + mat->t.z;
}

void	translate(t_matrix *mat, float val)
{
	mat->t.x += val;
	mat->t.y += val;
	mat->t.z += val;
}
