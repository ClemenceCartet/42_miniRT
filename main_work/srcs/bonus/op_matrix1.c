/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_matrix1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:15:16 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/03 12:09:37 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// rotation up-down
t_matrix	mat_rot_x(float rad)
{	
	t_matrix	new;

	new.x.x = 1;
	new.x.y = 0;
	new.x.z = 0;
	new.y.x = 0;
	new.y.y = cos(rad);
	new.y.z = -sin(rad);
	new.z.x = 0;
	new.z.y = sin(rad);
	new.z.z = cos(rad);
	return (new);
}

// rotation left-right
t_matrix	mat_rot_z(float rad)
{	
	t_matrix	new;

	new.x.x = cos(rad);
	new.x.y = -sin(rad);
	new.x.z = 0;
	new.y.x = sin(rad);
	new.y.y = cos(rad);
	new.y.z = 0;
	new.z.x = 0;
	new.z.y = 0;
	new.z.z = 1;
	return (new);
}

t_coord	mat_x_vector(t_matrix m, t_coord v)
{	
	t_coord	new;

	new.x = m.x.x * v.x + m.x.y * v.y + m.x.z * v.z;
	new.y = m.y.x * v.x + m.y.y * v.y + m.y.z * v.z;
	new.z = m.z.x * v.x + m.z.y * v.y + m.z.z * v.z;
	return (new);
}

// matrice de translation ??

// rotation haut/bas
void	rotate_y(t_coord *xyz, float rad)
{
	float	prev_y;

	prev_y = xyz->y;
	xyz->y = prev_y * cos(rad) - xyz->z * sin(rad);
	xyz->z = prev_y * sin(rad) + xyz->z * cos(rad);
}

// rotation droite/gauche
void	rotate_x(t_coord *xyz, float rad)
{
	float	prev_x;

	prev_x = xyz->x;
	xyz->x = prev_x * cos(rad) + xyz->z * sin(rad);
	xyz->z = -prev_x * sin(rad) + xyz->z * cos(rad);
}

// tanguage droite/gauche
void	rotate_z(t_coord *xyz, float rad)
{
	float	prev_x;
	float	prev_y;

	prev_x = xyz->x;
	prev_y = xyz->y;
	xyz->x = prev_x * cos(rad) - prev_y * sin(rad);
	xyz->y = prev_x * sin(rad) + prev_y * cos(rad);
}
