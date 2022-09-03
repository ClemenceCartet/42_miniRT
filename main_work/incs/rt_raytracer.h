/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:20:32 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/03 12:21:06 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RAYTRACER_H
# define RT_RAYTRACER_H

# include <mini_rt.h>

/*/////////////////////////////////////////////////////////////////////////////
		FUNCTION PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

/*-------------------- rt_ray_tracer.c --------------------*/

void		rt_ray_tracer(t_master *master);
void		rt_intersect(t_obj_data *obj_data, t_ray *ray);
t_ray		rt_create_ray(t_camera cam, float w, float h);
void		rt_put_pixel(float x, float y, t_color color, t_mlx_data *mlx);

/*-------------------- rt_hits1.c --------------------*/

bool		rt_inter_plane(t_ray *ray, t_object *pl, int crea);
void		rt_set_hit_pl(float t, t_ray *ray, t_object *pl);
bool		rt_inter_sphere(t_ray *ray, t_object *sp, int crea);
float		rt_calcul_sphere(t_ray *ray, t_object *sp, float *res);
bool		rt_set_hit_sp(float t, t_ray *ray, t_object *sp, int in_sphere);

/*-------------------- rt_hits2.c --------------------*/

void		rt_set_hit_point(t_ray *ray);
//bool		rt_inter_cylinder(t_ray *ray, t_object *cy);

/*-------------------- rt_light.c --------------------*/

t_color		rt_set_color(t_hit hit, t_master *master);
t_color		rt_set_point_light(t_hit hit, t_light *light, t_coord l_dir);
t_color		rt_set_ambient_light(t_color hit_color, t_ambient *ambient);
bool		rt_in_shadow(t_obj_data *obj_data, t_ray *l_ray, t_hit hit);

/*-------------------- rt_shadow.c --------------------*/

bool		rt_check_inter_sphere(t_ray *ray, t_object *sp, int crea);
bool		rt_check_inter_plane(t_ray *ray, t_object *pl, int crea);

#endif /* RT_RAYTRACER_H */