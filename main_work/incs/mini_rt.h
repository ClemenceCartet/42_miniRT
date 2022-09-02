/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 07:56:17 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/28 14:53:26 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

/* LIBFT.H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <sys/wait.h>
# include <stdio.h>
# include <math.h>
# include <sys/time.h>
# include <pthread.h>

# define UPPERHEX "0123456789ABCDEF"
# define LOWERHEX "0123456789abcdef"
# define BASEDEC "0123456789"
# define PRINTFCSET "scdiuxXp"
# define OPEN_MAX 10
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define TRUE 1
# define FALSE 0
# define NEGATIVE -1
# define POSITIVE 1
# define BUFFER_SIZE 1

typedef struct s_list	t_list;

struct s_list
{
	void			*content;
	struct s_list	*next;
};
*/
# include <stdbool.h>
# include <libft.h>
# include <mlx.h>

/*/////////////////////////////////////////////////////////////////////////////
		MINI RT HEADER FILES
*//////////////////////////////////////////////////////////////////////////////

# include <rt_keys.h>
# include <rt_data.h>
# include <rt_defines.h>
# include <rt_objects.h>
# include <rt_maths.h>

/*/////////////////////////////////////////////////////////////////////////////
		FUNCTION PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

/*-------------------- main.c --------------------*/

// int		main(int ac, char **av);
void		rt_display_scene(t_master *master);
int			exit_x(t_master *master);
int			key_hook(int key, t_master *master);

/*-------------------- rt_check_utils.c --------------------*/

int			rt_check_ptr(void *ptr, char **split);
int			rt_check_comma(char *values);
int			rt_check_charset(char *value, char *charset);
int			rt_check_float_syntax(char *value);

/*-------------------- rt_check_utils2.c --------------------*/

// int		rt_full_strcmp(char *s1, char *s2);
int			rt_check_overflow(char *value, char **split);
int			rt_check_float_range(float val, float min, float max, char *range);
int			rt_check_int_range(int value, int min, int max, char *range);

/*-------------------- rt_data_utils.c --------------------*/

void		*rt_calloc_struct(size_t size, char **split);
float		rt_init_obj_size(char **data, char *value);
float		rt_init_ratio(char **data, char *value);
int			rt_init_fov(char **data, char *value);

/*-------------------- rt_init_coords.c --------------------*/

// int		rt_check_coords_data(char **data, char **split, int isdir);
t_coord		*rt_init_coords(char **data, char *values, int isdir);

/*-------------------- rt_init_colors.c --------------------*/

// int		rt_check_rgb_data(char **data, char **split);
t_color		*rt_init_rgb(char **data, char *values);

/*-------------------- rt_init_objects.c --------------------*/

void		*rt_init_object(char **split, size_t splitsize, char *name);
void		*rt_init_sphere(char **split);
void		*rt_init_plane(char **split);
void		*rt_init_cylinder(char **split);

/*-------------------- rt_init_data.c --------------------*/

// t_object	*rt_obj_data_hub(char **split);
int			rt_init_obj_data(t_obj_data **obj_data, char **split);
int			rt_init_light(t_light **light, char **split);
int			rt_init_camera(t_camera **camera, char **split);
int			rt_init_ambient(t_ambient **ambient, char **split);

/*-------------------- rt_init_additional_data.c --------------------*/

// t_object	**rt_init_object_tab(t_obj_data *obj_data);
// void		rt_init_add_camera(t_camera **camera);
// void		rt_init_add_object(t_object **object);
int			rt_init_additional_data(t_master *master);

/*-------------------- rt_init_master.c --------------------*/

// int		rt_parse_line(t_master *master, char *line);
// int		rt_get_file_content(t_master *master, char *filename);
// int		rt_check_filename(char *filename);
// int		rt_check_init_master(t_master *master);
int			rt_init_master(t_master *master, char *filename);

/*-------------------- rt_free_data.c --------------------*/

void		rt_free_obj_data(t_obj_data *obj_data);
int			rt_free_master(t_master *master);

/*-------------------- rt_free_objects.c --------------------*/

void		rt_free_ambient(t_ambient *ambient);
void		rt_free_camera(t_camera *camera);
void		rt_free_light(t_light *light);
void		*rt_free_object(t_object *object);

/*-------------------- rt_ret_errors.c --------------------*/

// void		ft_free_split_error(char **split1, char **split2);
int			rt_ret_int_error(char **s1, char **s2, char *str, char *str2);
void		*rt_ret_ptr_error(char **s1, char **s2, char *str, char *str2);
char		*rt_ret_char_error(char **s1, char **s2, char *str, char *str2);
char		**rt_ret_split_error(char **s1, char **s2, char *str, char *str2);

/*-------------------- rt_write_errors.c --------------------*/

//	 void	rt_display_error(char *str, char *str2);
int			rt_write_int_error(char *str, char *str2, char *dfi, int dli);
void		*rt_write_ptr_error(char *str, char *str2, char *dfi, int dli);
char		*rt_write_char_error(char *str, char *str2, char *dfi, int dli);
char		**rt_write_split_error(char *str, char *str2, char *dfi, int dli);

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
void		rt_set_hit_sp(float t, t_ray *ray, t_object *sp, int in_sphere);

/*-------------------- rt_hits2.c --------------------*/

void		rt_set_hit_point(t_ray *ray);
//bool		rt_inter_cylinder(t_ray *ray, t_object *cy);

/*-------------------- rt_light.c --------------------*/

t_color		rt_set_color(t_hit hit, t_master *master);
t_color		rt_set_point_light(t_hit hit, t_light *light, t_coord l_dir);
t_color		rt_set_ambient_light(t_color hit_color, t_ambient *ambient);
bool		rt_in_shadow(t_obj_data *obj_data, t_ray l_ray, t_hit hit);

/*-------------------- rt_color.c --------------------*/

t_color		rt_color_bkg(void);
t_color		rt_add_color(t_color c1, t_color c2);
t_color		rt_scale_color(t_color c1, float ratio);
t_color		rt_reflt_color(t_color light, t_color obj);

/*-------------------- rt_shadow.c --------------------*/

bool	rt_check_inter_sphere(t_ray *ray, t_object *sp, int crea);
bool		rt_check_inter_plane(t_ray *ray, t_object *pl, int crea);

/*-------------------- rt_op_vector1.c --------------------*/

float		rt_vector_length(t_coord v);
float		rt_vec_length_sqr(t_coord v);
void		rt_norm_vector(t_coord *v);
t_coord		rt_create_vector(float x, float y, float z);

/*-------------------- rt_op_vector1.c --------------------*/

t_coord		rt_add_vec(t_coord v1, t_coord v2);
t_coord		rt_sub_vec(t_coord v1, t_coord v2);
t_coord		rt_scale_vec(t_coord v, float m);
float		rt_dot_prod(t_coord v1, t_coord v2);
t_coord		rt_cross_vec(t_coord v1, t_coord v2);

/*-------------------- op_matrix1.c --------------------*/

t_matrix	mat_rot_x(float rad);
t_matrix	mat_rot_z(float rad);
t_coord		mat_x_vector(t_matrix m, t_coord v);

void		rotate_x(t_coord *xyz, float rad);
void		rotate_y(t_coord *xyz, float rad);
void		rotate_z(t_coord *xyz, float rad);

/*-------------------- utils.c --------------------*/

void		rt_min_first(float *t1, float *t2);






/*-------------------- rt_bn_hit_square.c --------------------*/

void		rt_init_square(t_object *sq);
bool		rt_inter_square(t_ray *ray, t_object *sq);
bool		rt_in_square(t_coord p, t_object *sq);

#endif //MINI_RT_H