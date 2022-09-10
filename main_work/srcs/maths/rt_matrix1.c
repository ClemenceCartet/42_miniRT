/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:31:57 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/10 13:38:45 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Matrix initialization for object and camera (C / Pl / CY)
t_matrix	rt_init_matrix(void)
{
	t_matrix	matrix;

	matrix.x.x = 1.0;
	matrix.x.y = 0.0;
	matrix.x.z = 0.0;
	matrix.x.o = 0.0;
	matrix.y.x = 0.0;
	matrix.y.y = 0.0;
	matrix.y.z = 1.0;
	matrix.y.o = 0.0;
	matrix.z.x = 0.0;
	matrix.z.y = 0.0;
	matrix.z.z = 1.0;
	matrix.z.o = 0.0;
	matrix.o.x = 0.0;
	matrix.o.y = 0.0;
	matrix.o.z = 0.0;
	matrix.o.o = 1.0;
	return (matrix);
}
