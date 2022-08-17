/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:21:19 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/17 11:38:50 by ljohnson         ###   ########lyon.fr   */
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

typedef struct s_color		t_color;
typedef struct s_coord		t_coord;

//RT_MATHS_H
typedef struct s_ray		t_ray;
typedef struct s_matrix		t_matrix;

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
	void		*init;
	void		*wdw;
	t_mlx_data	*mlx;

	t_obj_data	*obj_data;

	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
};

struct s_mlx_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
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
	t_list	*current;
	size_t	lst_size;
	void	*start;
};

/**Structure contenant les données de couleur
 * r	= couleur rouge
 * g	= couleur verte
 * b	= couleur bleue
*/
struct	s_color
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
struct	s_coord
{
	float	x;
	float	y;
	float	z;
};

#endif //RT_DATA_H