/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:18:29 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/14 15:53:06 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILS_H
# define RT_UTILS_H

# include <mini_rt.h>

/*/////////////////////////////////////////////////////////////////////////////
		UTILS PROTOTYPES
*//////////////////////////////////////////////////////////////////////////////

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
int			rt_write_int_error(char *str, char *str2);
void		*rt_write_ptr_error(char *str, char *str2);
char		*rt_write_char_error(char *str, char *str2);
char		**rt_write_split_error(char *str, char *str2);

#endif /* RT_UTILS_H */