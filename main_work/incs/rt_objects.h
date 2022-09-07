/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:18:11 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/07 14:13:29 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_OBJECTS_H
# define RT_OBJECTS_H

# include <mini_rt.h>

/*/////////////////////////////////////////////////////////////////////////////
		MANDATORY OBJECTS STRUCTURES
*//////////////////////////////////////////////////////////////////////////////

/**Structure pour la lumière ambiante
 * ratio	= luminosité de la lumière ambiante | range [ 0.0 / 1.0 ]
 * rgb		= couleurs RGB de la lumière ambiante | range [ 0 / 255 ]
*/
struct	s_ambient
{
	float	ratio;
	t_color	*rgb;
};

/**Structure pour la caméra
 * pos		= coordonnées XYZ de la caméra
 * dir		= Vecteur d'orientation 3D sur l'axe XYZ | range [ -1 / 1 ]
 * fov		= Champ de vision horizontal en degré | range [ 0 / 180 ]
*/
struct	s_camera
{
	t_coord	*pos;
	t_coord	*dir;
	int		fov;

	float	radian;
	float	focal;
};

/**Structure pour la lumière
 * pos		= coordonnées XYZ de la lumière
 * ratio	= luminosité de la lumière | range [ 0.0 / 1.0 ]
 * rgb		= BONUS : couleurs RGB de la lumière | range [ 0 / 255 ]
*/
struct	s_light
{
	t_coord	*pos;
	float	ratio;
	t_color	*rgb;
};

/*/////////////////////////////////////////////////////////////////////////////
		SECONDARY OBJECTS STRUCTURE
*//////////////////////////////////////////////////////////////////////////////

/**Structure lien de la liste chaînées des objets
 * id 		= identifiant de l'objet (SP / PL / CY)
 * 
 * pos		= coordonnées XYZ de l'objet
 * dir		= Vecteur d'orientation 3D sur l'axe XYZ | range [ -1 / 1 ] (PL / CY)
 * rgb		= couleur RGB de l'objet | range [ 0 / 255 ]
 * diameter	= diamètre de l'objet (SP / CY)
 * height	= hauteur de l'objet (CY)
*/
struct	s_object
{
	int		id;

	t_coord	*pos;
	t_coord	*dir;
	t_color	*rgb;
	float	diameter;
	float	height;

	float	radius;
	t_coord	c[4];
	t_coord	gap[4];
	int		selected;
};
/**Structure pour l'objet sphère
 * pos		= coordonnées XYZ du centre de la sphère
 * diameter	= diamètre de la sphère
 * rgb		= couleurs RGB de la sphère | range [ 0 / 255 ]
*/
/**Structure pour l'objet plan
 * pos		= coordonnées XYZ du plan
 * dir		= Vecteur d'orientation 3d sur l'axe XYZ | range [ -1 / 1 ]
 * rgb		= couleurs RGB du plan | range [ 0 / 255 ]
*/
/**Structure pour l'objet cylindre
 * pos		= coordonnées XYZ du cylindre
 * dir		= Vecteur d'orientation 3D sur l'axe XYZ | range [ -1 / 1 ]
 * diameter	= diamètre du cylindre
 * height	= hauteur du cylindre
 * rgb		= couleurs RGB du cylindre | range [ 0 / 255 ]
*/

#endif //RT_OBJECTS_H