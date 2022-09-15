/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:20:32 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/15 13:51:54 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RAYTRACER_H
# define RT_RAYTRACER_H

# include <mini_rt.h>

/*/////////////////////////////////////////////////////////////////////////////
		FUNCTION PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

/*-------------------- rt_ray_tracer.c --------------------*/

void	rt_ray_tracer(t_master *master);
void	rt_set_new_rotate(t_master *master);
t_ray	rt_create_ray(t_camera cam, float w, float h);
void	rt_put_pixel(int x, int y, t_color color, t_mlx_data *mlx);

/*-------------------- rt_intersection.c --------------------*/

void	rt_intersect(t_obj_data *obj_data, t_ray *ray);
float	rt_inter_plane(t_ray *ray, t_object *pl);
float	rt_calcul_plane(t_ray *ray, t_coord pl_pos, t_coord pl_dir);
float	rt_inter_sphere(t_ray *ray, t_object *sp);
// float	rt_calcul_sphere(t_ray *ray, t_object *sp, float *tmp_time);

/*-------------------- rt_inters_cylinder.c --------------------*/

float	rt_inter_cylinder(t_ray *ray, t_object *cy);
float	rt_body_cy_inter(t_ray *ray, t_object *cy);
void	rt_calcul_cy(t_ray *ray, t_object *cy, float *tmp_time, float *delta);
float	rt_end_cy_inter(t_ray *ray, t_object *cy);

/*-------------------- rt_inters_cy_utils.c --------------------*/

float	rt_check_body_cy(t_ray *ray, t_object *cy, float *tmp_time);
float	rt_set_time(t_ray *ray, float tmp_time, float dist, int ok);
float	rt_check_plane_cy(t_ray *ray, t_coord cy_pos, t_object *cy);

/*-------------------- rt_hits.c --------------------*/

void	rt_set_hit(t_ray *ray, t_object *obj, float time);
void	rt_find_normal_sphere(t_ray *ray, t_object *sp);
void	rt_find_normal_plane(t_ray *ray, t_coord pl_dir);
void	rt_find_normal_cy(t_hit *hit, t_object *cy, int in_obj);
void	rt_set_hit_point(t_ray *ray);

/*-------------------- rt_light.c --------------------*/

t_color	rt_set_color(t_hit hit, t_master *master);
t_color	rt_set_point_light(t_hit hit, t_light *light, t_coord l_dir);
t_color	rt_set_ambient_light(t_color hit_color, t_ambient *ambient);
bool	rt_in_shadow(t_obj_data *obj_data, t_ray *l_ray, t_hit hit);

/*-------------------- rt_ray_tracer.c --------------------*/

void	rt_put_pixel(int x, int y, t_color color, t_mlx_data *mlx);
t_ray	rt_create_ray(t_camera cam, float w, float h);
void	rt_ray_tracer(t_master *master);

#endif /* RT_RAYTRACER_H */