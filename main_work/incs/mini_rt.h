/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 07:56:17 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/08 09:59:16 by ljohnson         ###   ########lyon.fr   */
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

/*-------------------- CHECKERS --------------------*/

int		rt_check_file_content(char *content);
int		rt_check_float_syntax(char *str, char *name);
int		rt_check_value_format(char *value, char *charset);

/*-------------------- FREEZERS --------------------*/

int		rt_free_master(t_master *master);
void	rt_free_object_list(t_object *object);

/*-------------------- GETTERS --------------------*/

char	*rt_get_file_content(char *filename);
char	**rt_get_split_from_raw(char *value, char c, int splitlen, char *name);

/*-------------------- INIT_ITEM --------------------*/

int		rt_init_item_ambient(t_ambient *ambient, char **split);
int		rt_init_item_camera(t_camera *camera, char **split);
int		rt_init_item_cylinder(t_cylinder *cylinder, char **split);
int		rt_init_item_light(t_light *light, char **split);
int		rt_init_item_plane(t_plane *plane, char **split);
int		rt_init_item_sphere(t_sphere *sphere, char **split);

/*-------------------- INIT_VALUES --------------------*/

int		rt_init_value_fov(char *value, char *name);
int		rt_init_value_rgb(char *value, int index, char *name);

/*-------------------- INITIERS --------------------*/

int		rt_init_master(t_master *master);
void	*rt_init_object_ptr(char **split, int valid_splitlen, char *name);

/*-------------------- PARSERS --------------------*/

int		rt_parse_ambient(t_master *master, char **split);
int		rt_parse_camera(t_master *master, char **split);
void	*rt_parse_cylinder(int *object_id, char **split);
int		rt_parse_file_content(t_master *master, char *content);
int		rt_parse_light(t_master *master, char **split);
int		rt_parse_line(t_master *master, char *line);
int		rt_parse_master(t_master *master, char *filename);
int		rt_parse_object(t_master *master, char **split);
void	*rt_parse_plane(int *object_id, char **split);
void	*rt_parse_sphere(int *object_id, char **split);

/*-------------------- SETTERS --------------------*/

int		rt_set_coordinates(float p_xyz[3], char *value, char *name);
int		rt_set_diameter(float diameter, char *value, char *name);
int		rt_set_fov(int fov, char *value, char *name);
int		rt_set_orientation(float o_xyz[3], char *value, char *name);
int		rt_set_ratio(float ratio, char *value, char *name);
int		rt_set_rgb(int rgb[3], char *value, char *name);

/*-------------------- WRITERS --------------------*/

char	*rt_write_char_error(char *str, char *str2);
int		rt_write_int_error(char *str, char *str2);
char	**rt_write_split_error(char *str, char *str2);

/*-------------------- main.c --------------------*/

// int	main(int ac, char **av);

/*/////////////////////////////////////////////////////////////////////////////
		TEST FUNCTION PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

void	test_split_values(char **split);
void	test_ambient_values(t_ambient *ambient);
void	test_camera_values(t_camera *camera);
void	test_light_values(t_light *light);
void	test_sphere_values(t_sphere *sphere);
void	test_plane_values(t_plane *plane);
void	test_cylinder_values(t_cylinder *cylinder);
void	test_object_list_values(t_object *object);

// dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
// dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);

#endif //MINI_RT_H