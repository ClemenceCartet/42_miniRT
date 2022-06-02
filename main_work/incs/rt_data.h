/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:21:19 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/02 10:58:05 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_H
# define RT_DATA_H

# include <mini_rt.h>

/*/////////////////////////////////////////////////////////////////////////////
		TYPEDEF
*//////////////////////////////////////////////////////////////////////////////

typedef struct s_master		t_master;
typedef struct s_mlxdata	t_mlxdata;

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
 * object	= structure contenant les données des objets (sp, pl & cy)
 * ambient	= structure contenant les données de la lumière ambiante
 * camera	= structure contenant les données de la caméra
 * light	= structure contenant les données de la lumière
*/
struct s_master
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
struct s_mlxdata
{
	void	*init;
	void	*window;
	int		loop;
};

/**Structure pour la lumière ambiante
 * ratio	= luminosité de la lumière ambiante | range [ 0.0 / 1.0 ]
 * rgb		= couleurs RGB de la lumière ambiante | range [ 0 / 255 ]
*/
struct	s_ambient
{
	float	ratio;
	int		rgb[3];
};

/**Structure pour la caméra
 * p_xyz	= coordonnées XYZ de la caméra
 * o_xyz	= Vecteur d'orientation 3D sur l'axe XYZ | range [ -1 / 1 ]
 * fov		= Champ de vision horizontal en degré | range [ 0 / 180 ]
*/
struct	s_camera
{
	float	p_xyz[3];
	float	o_xyz[3];
	int		fov;
};

/**Structure pour la lumière
 * p_xyz	= coordonnées XYZ de la lumière
 * ratio	= luminosité de la lumière | range [ 0.0 / 1.0 ]
 * rgb		= BONUS : couleurs RGB de la lumière | range [ 0 / 255 ]
*/
struct	s_light
{
	float	p_xyz[3];
	float	ratio;
	int		rgb[3];
};

#endif //RT_DATA_H