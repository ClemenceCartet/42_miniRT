/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_matrix1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:15:16 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/03 09:38:25 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// rotation up-down
t_matrix	mat_rot_x(float rad)
{	
	t_matrix	new;

	new.x_x = 1;
	new.x_y = 0;
	new.x_z = 0;
	new.y_x = 0;
	new.y_y = cos(rad);
	new.y_z = -sin(rad);
	new.z_x = 0;
	new.z_y = sin(rad);
	new.z_z = cos(rad);
	return (new);
}

// rotation left-right
t_matrix	mat_rot_z(float rad)
{	
	t_matrix	new;

	new.x_x = cos(rad);
	new.x_y = -sin(rad);
	new.x_z = 0;
	new.y_x = sin(rad);
	new.y_y = cos(rad);
	new.y_z = 0;
	new.z_x = 0;
	new.z_y = 0;
	new.z_z = 1;
	return (new);
}

t_coord	mat_x_vector(t_matrix m, t_coord v)
{	
	t_coord	new;

	new.x = m.x_x * v.x + m.x_y * v.y + m.x_z * v.z;
	new.y = m.y_x * v.x + m.y_y * v.y + m.y_z * v.z;
	new.z = m.z_x * v.x + m.z_y * v.y + m.z_z * v.z;
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
