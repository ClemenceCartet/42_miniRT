/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 07:56:17 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/13 10:39:03 by ljohnson         ###   ########lyon.fr   */
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
# include <libft.h>
# include <mlx.h>

/*/////////////////////////////////////////////////////////////////////////////
		MINI RT HEADER FILES
*//////////////////////////////////////////////////////////////////////////////

# include <rt_keys.h>
# include <rt_data.h>
# include <rt_defines.h>
# include <rt_objects.h>

/*/////////////////////////////////////////////////////////////////////////////
		FUNCTION PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

void	*rt_calloc_struct(size_t size, char **split);

/*-------------------- rt_free_data.c --------------------*/

void	rt_free_mlx_data(t_mlx_data	*mlx_data);
void	rt_free_obj_data(t_obj_data *obj_data);
int		rt_free_master(t_master *master);

/*-------------------- rt_free_objects.c --------------------*/

void	rt_free_ambient(t_ambient *ambient);
void	rt_free_camera(t_camera *camera);
void	rt_free_light(t_light *light);
void	*rt_free_object(t_object *object);

/*-------------------- rt_check_utils.c --------------------*/

int		rt_check_ptr(void *ptr, char **split);
int		rt_check_comma(char *values);
int		rt_check_charset(char *value, char *charset);
int		rt_check_float_syntax(char *value);

/*-------------------- rt_check_utils2.c --------------------*/

int		rt_check_overflow(char *value, char **split);
int		rt_check_float_range(float value, float min, float max, char *range);
int		rt_check_int_range(int value, int min, int max, char *range);

/*-------------------- rt_data_utils.c --------------------*/

void	*rt_calloc_struct(size_t size, char **split);
float	rt_init_obj_size(char **data, char *value);
float	rt_init_ratio(char **data, char *value);
int		rt_init_fov(char **data, char *value);

/*-------------------- rt_init_colors.c --------------------*/

// int	rt_check_rgb_data(char **data, char **split);
t_color	*rt_init_rgb(char **data, char *values);

/*-------------------- rt_init_coords.c --------------------*/

// int	rt_check_coords_data(char **data, char **split, int isdir);
t_coord	*rt_init_coords(char **data, char *values, int isdir);

/*-------------------- rt_init_data.c --------------------*/

int		rt_init_obj_data(t_obj_data **obj_data, char **split);
int		rt_init_light(t_light **light, char **split);
int		rt_init_camera(t_camera **camera, char **split);
int		rt_init_ambient(t_ambient **ambient, char **split);

/*-------------------- rt_init_master.c --------------------*/

// int	rt_parse_line(t_master *master, char *line);
// int	rt_get_file_content(t_master *master, char *filename);
// int	rt_check_filename(char *filename);
// int	rt_check_init_master(t_master *master);
int		rt_init_master(t_master *master, char *filename);

/*-------------------- rt_return_errors.c --------------------*/

// void	ft_free_split_error(char **split1, char **split2);
int		rt_return_int_error(char **s1, char **s2, char *str, char *str2);
void	*rt_return_ptr_error(char **s1, char **s2, char *str, char *str2);
char	*rt_return_char_error(char **s1, char **s2, char *str, char *str2);
char	**rt_return_split_error(char **s1, char **s2, char *str, char *str2);

/*-------------------- rt_write_errors.c --------------------*/

// void	rt_display_error(char *str, char *str2);
int		rt_write_int_error(char *str, char *str2, char *dfi, int dli);
void	*rt_write_ptr_error(char *str, char *str2, char *dfi, int dli);
char	*rt_write_char_error(char *str, char *str2, char *dfi, int dli);
char	**rt_write_split_error(char *str, char *str2, char *dfi, int dli);

/*-------------------- main.c --------------------*/

// int	main(int ac, char **av);

/*-------------------- test_battery.c --------------------*/

void	error_messages_int(void);
void	error_messages_char(void);
void	error_messages_ptr(void);
void	error_messages_split(void);
void	display_mlx_data(t_mlx_data *mlx_data);
void	display_ambient(t_ambient *ambient);
void	display_camera(t_camera *camera);
void	display_light(t_light *light);
void	display_object(t_object *object);
void	display_obj_data(t_obj_data *obj_data);
void	display_master(t_master *master);
void	display_file_content(char *file);
void	test_battery(t_master *master, int ac, char **av);

#endif //MINI_RT_H