/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_maths.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:19:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/13 11:10:37 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATHS_H
# define RT_MATHS_H

# include <mini_rt.h>

/*/////////////////////////////////////////////////////////////////////////////
		MATHS PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

/*-------------------- rt_matrix_rotation.c --------------------*/

t_matrix	rt_matrix_rot_x(float rad);
t_matrix	rt_matrix_rot_y(float rad);
t_matrix	rt_matrix_rot_z(float rad);
t_matrix	rt_matrix_rotate(t_coord vec);
// t_coord		rt_rotate_test(t_matrix m, t_coord baseray, t_camera cam);

/*-------------------- rt_matrix.c --------------------*/

t_coord		rt_multiply_matrix_vector(t_matrix m, t_coord v);
t_matrix	rt_multiply_matrix(t_matrix s, t_matrix r);
t_coord		rt_set_vector_identity(int id);
t_matrix	rt_init_matrix(void);

/*-------------------- rt_color.c --------------------*/

t_color		rt_color_bkg(void);
t_color		rt_add_color(t_color c1, t_color c2);
t_color		rt_scale_color(t_color c1, float ratio);
t_color		rt_reflt_color(t_color light, t_color obj);

/*-------------------- rt_op_vector1.c --------------------*/

float		rt_vector_length(t_coord v);
float		rt_vec_length_sqr(t_coord v);
void		rt_norm_vector(t_coord *v);
t_coord		rt_create_vector(float x, float y, float z);

/*-------------------- rt_op_vector2.c --------------------*/

t_coord		rt_add_vec(t_coord v1, t_coord v2);
t_coord		rt_sub_vec(t_coord v1, t_coord v2);
t_coord		rt_scale_vec(t_coord v, float m);
float		rt_dot_prod(t_coord v1, t_coord v2);
t_coord		rt_cross_vec(t_coord v1, t_coord v2);

/*-------------------- rt_rotation.c --------------------*/

void		x_axis_rotation(t_coord *xyz, float degree);
void		y_axis_rotation(t_coord *xyz, float degree);
void		z_axis_rotation(t_coord *xyz, float degree);

#endif /* RT_MATHS */