/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 07:56:17 by ljohnson          #+#    #+#             */
/*   Updated: 2022/05/31 12:54:18 by ljohnson         ###   ########lyon.fr   */
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
# include <rt_messages.h>

/*/////////////////////////////////////////////////////////////////////////////
		FUNCTION PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

/*-------------------- file2.c --------------------*/

int		rt_parse_object(t_object *object, char **split);
int		rt_parse_light(t_light *light, char **split);
int		rt_parse_camera(t_camera *camera, char **split);
int		rt_parse_ambient(t_ambient *ambient, char **split);
int		rt_get_line_content(t_master *master, char *line);

/*-------------------- file1.c --------------------*/

int		rt_parse_content(t_master *master, char *content);
int		rt_check_content(char *content);
char	*rt_get_content(char *filename);
int		rt_set_master(t_master *master);
int		rt_init_master(t_master *master, char *filename);

/*-------------------- main.c --------------------*/

void	rt_free_object_list(t_object *object);
int		rt_free_master(t_master *master);
char	*rt_write_char_error(char *str, char *str2);
int		rt_write_int_error(char *str, char *str2);
// int	main(int ac, char **av);

/*/////////////////////////////////////////////////////////////////////////////
		TEST FUNCTION PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

void	display_split(char **split);

#endif //MINI_RT_H