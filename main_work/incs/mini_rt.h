/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 07:56:17 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/03 12:19:27 by ljohnson         ###   ########lyon.fr   */
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

/*-------------------- rt_free_data.c --------------------*/

void	rt_free_mlx_data(t_mlx_data	*mlx_data);
void	rt_free_obj_data(t_obj_data *obj_data);
int		rt_free_master(t_master *master);

/*-------------------- rt_free_objects.c --------------------*/

void	rt_free_ambient(t_ambient *ambient);
void	rt_free_camera(t_camera *camera);
void	rt_free_light(t_light *light);
void	rt_free_object(t_object *object);

/*-------------------- rt_init_data.c --------------------*/

int		rt_parse_line(t_master *master, char *line);
int		rt_check_init_master(t_master *master);
int		rt_get_file_content(t_master *master, char *filename);
int		rt_check_filename(char *filename);
int		rt_init_master(t_master *master, char *filename);

/*-------------------- rt_write_errors.c --------------------*/

void	rt_display_error(char *str, char *str2);
char	**rt_write_split_error(char *str, char *str2);
int		rt_write_int_error(char *str, char *str2);
char	*rt_write_char_error(char *str, char *str2);

/*-------------------- main.c --------------------*/

// int	main(int ac, char **av);

#endif //MINI_RT_H