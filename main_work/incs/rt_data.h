/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:21:19 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/01 11:27:20 by ljohnson         ###   ########lyon.fr   */
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
typedef struct s_obj_link	t_obj_link;

typedef struct s_colors		t_colors;
typedef struct s_coords		t_coords;

//RT_OBJECTS_H
typedef struct s_ambient	t_ambient;
typedef struct s_camera		t_camera;
typedef struct s_light		t_light;

typedef struct s_object		t_object;
typedef struct s_obj_link	t_obj_link;

typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;

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
	t_mlxdata	*mlxdata;
	t_object	*object;
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
	int		loop;
};

/**Structure contenant une liste chaînée des objets
 * lst		= libft linked list
 * lst_size	= nombre de maillon de la liste lst
 * start	= pointeur vers le début de lst
*/
struct	s_obj_data
{
	t_list	*lst;
	size_t	lst_size;
	void	*start;
};

/**Structure lien de la liste chaînées des objets
 * id 		= identifiant de l'objet (SP / PL / CY)
 * sphere	= pointeur vers la structure sphere si id == SP else NULL
 * plane	= pointeur vers la structure plane si id == PL else NULL
 * cylinder	= pointeur vers la structure cylinder si id == CY else NULL
*/
struct	s_obj_link
{
	int			id;

	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
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
	float	p_xyz[3];
	float	ratio;
	int		rgb[3];
};

#endif //RT_DATA_H