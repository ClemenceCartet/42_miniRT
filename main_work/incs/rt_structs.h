/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:49:59 by ljohnson          #+#    #+#             */
/*   Updated: 2022/05/30 09:09:09 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCTS_H
# define RT_STRUCTS_H

# include <mini_rt.h>

/*/////////////////////////////////////////////////////////////////////////////
		OBJECTS STRUCTURES
*//////////////////////////////////////////////////////////////////////////////

/**Structure contenant une liste chaînée des objets
 * lst		= libft linked list
 * lst_size	= nombre de maillon de la liste lst
 * start	= pointeur vers le début de lst
*/
struct	s_object
{
	t_list	*lst;
	size_t	lst_size;
	void	*start;
};

/**Structure pour l'objet sphère
 * id		= identifiant de l'objet (define SP)
 * p_xyz	= coordonnées XYZ du centre de la sphère
 * diameter	= diamètre de la sphère
 * rgb		= couleurs RGB de la sphère | range [ 0 / 255 ]
*/
struct	s_sphere
{
	int		id;
	float	p_xyz[3];
	float	diameter;
	int		rgb[3];
};

/**Structure pour l'objet plan
 * id		= identifiant de l'objet (define PL)
 * p_xyz	= coordonnées XYZ du plan
 * o_xyz	= Vecteur d'orientation 3d sur l'axe XYZ | range [ -1 / 1 ]
 * rgb		= couleurs RGB du plan | range [ 0 / 255 ]
*/
struct	s_plane
{
	int		id;
	float	p_xyz[3];
	float	o_xyz[3];
	int		rgb[3];
};

/**Structure pour l'objet cylindre
 * id		= identifiant de l'objet (define CY)
 * p_xyz	= coordonnées XYZ du cylindre
 * o_xyz	= Vecteur d'orientation 3D sur l'axe XYZ | range [ -1 / 1 ]
 * diameter	= diamètre du cylindre
 * height	= hauteur du cylindre
 * rgb		= couleurs RGB du cylindre | range [ 0 / 255 ]
*/
struct	s_cylinder
{
	int		id;
	float	p_xyz[3];
	float	o_xyz[3];
	float	diameter;
	float	height;
	int		rgb[3];
};

#endif //RT_STRUCTS_H