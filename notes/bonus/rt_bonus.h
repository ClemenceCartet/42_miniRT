/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:10:40 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/03 12:12:47 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_BONUS_H
# define RT_BONUS_H

# include <mini_rt.h>

/*/////////////////////////////////////////////////////////////////////////////
		BONUS PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

/*-------------------- op_matrix1.c --------------------*/

t_matrix	mat_rot_x(float rad);
t_matrix	mat_rot_z(float rad);
t_coord		mat_x_vector(t_matrix m, t_coord v);

void		rotate_x(t_coord *xyz, float rad);
void		rotate_y(t_coord *xyz, float rad);
void		rotate_z(t_coord *xyz, float rad);

/*-------------------- rt_bn_hit_square.c --------------------*/

void		rt_init_square(t_object *sq);
bool		rt_inter_square(t_ray *ray, t_object *sq);
bool		rt_in_square(t_coord p, t_object *sq);

#endif /* RT_BONUS_H */