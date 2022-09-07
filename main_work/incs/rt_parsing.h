/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:16:30 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/07 11:56:07 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSING_H
# define RT_PARSING_H

# include <mini_rt.h>

/*/////////////////////////////////////////////////////////////////////////////
		PARSING PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

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
void		rt_init_add_object(t_object **object);
int			rt_init_additional_data(t_master *master);

/*-------------------- rt_init_master.c --------------------*/

// int		rt_parse_line(t_master *master, char *line);
// int		rt_get_file_content(t_master *master, char *filename);
// int		rt_check_filename(char *filename);
// int		rt_check_init_master(t_master *master);
int			rt_init_master(t_master *master, char *filename);

#endif /* RT_PARSING_H */