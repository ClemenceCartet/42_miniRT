/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:20:32 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/03 15:19:33 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RAYTRACER_H
# define RT_RAYTRACER_H

# include <mini_rt.h>

/*/////////////////////////////////////////////////////////////////////////////
		FUNCTION PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

/*-------------------- rt_hits.c --------------------*/

void	rt_set_hit_point(t_ray *ray);
void	rt_set_hit(t_ray *ray, t_object *obj, float time);

/*-------------------- rt_intersection.c --------------------*/

float	rt_inter_plane(t_ray *ray, t_object *pl);
// float	rt_calcul_sphere(t_ray *ray, t_object *sp, float *tmp_time);
float	rt_inter_sphere(t_ray *ray, t_object *sp);
void	rt_intersect(t_obj_data *obj_data, t_ray *ray);

/*-------------------- rt_light.c --------------------*/

t_color	rt_set_color(t_hit hit, t_master *master);
t_color	rt_set_point_light(t_hit hit, t_light *light, t_coord l_dir);
t_color	rt_set_ambient_light(t_color hit_color, t_ambient *ambient);
bool	rt_in_shadow(t_obj_data *obj_data, t_ray *l_ray, t_hit hit);

/*-------------------- rt_ray_tracer.c --------------------*/

void	rt_put_pixel(float x, float y, t_color color, t_mlx_data *mlx);
t_ray	rt_create_ray(t_camera cam, float w, float h);
void	rt_ray_tracer(t_master *master);

#endif /* RT_RAYTRACER_H */