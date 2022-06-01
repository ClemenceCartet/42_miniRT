/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 07:56:17 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/01 13:50:57 by ljohnson         ###   ########lyon.fr   */
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

# include <math.h>

/*/////////////////////////////////////////////////////////////////////////////
		MINI RT HEADER FILES
*//////////////////////////////////////////////////////////////////////////////

# include <rt_keys.h>
# include <rt_data.h>
# include <rt_structs.h>
# include <rt_defines.h>

/*/////////////////////////////////////////////////////////////////////////////
		FUNCTION PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

/*-------------------- file6.c --------------------*/ // 2

char	**rt_check_value(char *value, char c, int splitlen, char *name);
void	*rt_init_object_ptr(char **split, int valid_splitlen, char *name);

/*-------------------- file5.c --------------------*/ // 6

int		rt_set_coordinates(float p_xyz[3], char *value, char *name);
int		rt_set_orientation(float o_xyz[3], char *value, char *name);
int		rt_set_rgb(int rgb[3], char *value, char *name);
int		rt_set_fov(int fov, char *value, char *name);
int		rt_set_ratio(float ratio, char *value, char *name);
int		rt_set_diameter(float diameter, char *value, char *name);

/*-------------------- file4.c --------------------*/ // 6

void	rt_init_plane_values(t_plane *plane);
void	rt_init_sphere_values(t_sphere *sphere);
void	rt_init_cylinder_values(t_cylinder *cylinder);
void	rt_init_ambient_values(t_ambient *ambient);
void	rt_init_camera_values(t_camera *camera);
void	rt_init_light_values(t_light *light);

/*-------------------- file3.c --------------------*/ // 3

int		rt_parse_sphere(void **object_ptr, char **split);
int		rt_parse_plane(void **object_ptr, char **split);
int		rt_parse_cylinder(void **object_ptr, char **split);

/*-------------------- file2.c --------------------*/ // 5

int		rt_parse_object(t_object *object, char **split);
int		rt_parse_light(t_light *light, char **split);
int		rt_parse_camera(t_camera *camera, char **split);
int		rt_parse_ambient(t_ambient *ambient, char **split);
int		rt_get_line_content(t_master *master, char *line);

/*-------------------- file1.c --------------------*/ // 5

int		rt_parse_content(t_master *master, char *content);
int		rt_check_content(char *content);
char	*rt_get_content(char *filename);
int		rt_set_master(t_master *master);
int		rt_init_master(t_master *master, char *filename);

/*-------------------- main.c --------------------*/ // 5

void	rt_free_object_list(t_object *object);
int		rt_free_master(t_master *master);
char	*rt_write_char_error(char *str, char *str2);
int		rt_write_int_error(char *str, char *str2);
// int	main(int ac, char **av);

/*/////////////////////////////////////////////////////////////////////////////
		TEST FUNCTION PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

void	display_split(char **split);
void	display_ambient(t_ambient *ambient);
void	display_camera(t_camera *camera);
void	display_light(t_light *light);
void	display_sphere(t_sphere *sphere);
void	display_plane(t_plane *plane);
void	display_cylinder(t_cylinder *cylinder);
void	display_object_list(t_object *object);

#endif //MINI_RT_H