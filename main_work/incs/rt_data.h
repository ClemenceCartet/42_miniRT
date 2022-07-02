/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:21:19 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/02 10:44:54 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_H
# define RT_DATA_H

# include <mini_rt.h>

/*/////////////////////////////////////////////////////////////////////////////
		TYPEDEF
*//////////////////////////////////////////////////////////////////////////////

//RT_DATA_H
typedef struct s_master		t_master;
typedef struct s_mlx_data	t_mlx_data;

typedef struct s_obj_data	t_obj_data;
typedef struct s_object		t_object;

typedef struct s_colors		t_colors;
typedef struct s_coords		t_coords;

//RT_OBJECTS_H
typedef struct s_ambient	t_ambient;
typedef struct s_camera		t_camera;
typedef struct s_light		t_light;

/*/////////////////////////////////////////////////////////////////////////////
		MAIN STRUCTURES
*//////////////////////////////////////////////////////////////////////////////

/**Structure master, donnant accès à toute les données du programme
 * mlxdata	= structure contenant les données de la MLX
 * obj_data	= structure contenant les données des objets (sp, pl & cy)
 * ambient	= structure contenant les données de la lumière ambiante
 * camera	= structure contenant les données de la caméra
 * light	= structure contenant les données de la lumière
*/
struct	s_master
{
	t_mlx_data	*mlx_data;
	t_obj_data	*obj_data;

	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
};

/**Structure contenant les pointeurs et données nécessaires à la MLX
 * init		= pointeur donné par mlx_init();
 * window	= pointeur donné par mlx_new_window();
 * loop		= int donné par mlx_loop();
*/
struct s_mlx_data
{
	void	*init;
	void	*window;
	int		width;
	int		height;
	int		loop;
};

/**Structure contenant une liste chaînée des objets
 * lst		= libft linked list
 * lst_size	= nombre de maillon de la liste lst
 * start	= pointeur vers le début de lst
 * lst->content = t_object
*/
struct	s_obj_data
{
	t_list	*lst;
	size_t	lst_size;
	void	*start;
};

/**Structure contenant les données de couleur
 * r	= couleur rouge
 * g	= couleur verte
 * b	= couleur bleue
*/
struct	s_colors
{
	int	r;
	int	g;
	int	b;
};

/**Structure contenant les données de coordonnées, position ou direction
 * x	= axe X
 * y	= axe Y
 * Z	= axe Z
*/
struct	s_coords
{
	float	x;
	float	y;
	float	z;
};

#endif //RT_DATA_H