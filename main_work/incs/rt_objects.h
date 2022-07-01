/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:18:11 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/28 15:27:24 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_OBJECTS_H
# define RT_OBJECTS_H

/*/////////////////////////////////////////////////////////////////////////////
		MANDATORY OBJECTS STRUCTURES
*//////////////////////////////////////////////////////////////////////////////

/**Structure pour la lumière ambiante
 * ratio	= luminosité de la lumière ambiante | range [ 0.0 / 1.0 ]
 * rgb		= couleurs RGB de la lumière ambiante | range [ 0 / 255 ]
*/
struct	s_ambient
{
	float		ratio;
	t_colors	*rgb;
};

/**Structure pour la caméra
 * pos		= coordonnées XYZ de la caméra
 * dir		= Vecteur d'orientation 3D sur l'axe XYZ | range [ -1 / 1 ]
 * fov		= Champ de vision horizontal en degré | range [ 0 / 180 ]
*/
struct	s_camera
{
	t_coords	*pos;
	t_coords	*dir;
	int			fov;
};

/**Structure pour la lumière
 * pos		= coordonnées XYZ de la lumière
 * ratio	= luminosité de la lumière | range [ 0.0 / 1.0 ]
 * rgb		= BONUS : couleurs RGB de la lumière | range [ 0 / 255 ]
*/
struct	s_light
{
	t_coords	*pos;
	float		ratio;
	t_colors	*rgb;
};

/*/////////////////////////////////////////////////////////////////////////////
		SECONDARY OBJECTS STRUCTURES
*//////////////////////////////////////////////////////////////////////////////

/**Structure pour l'objet sphère
 * pos		= coordonnées XYZ du centre de la sphère
 * diameter	= diamètre de la sphère
 * rgb		= couleurs RGB de la sphère | range [ 0 / 255 ]
*/
struct	s_sphere
{
	t_coords	pos;
	float		diameter;
	t_colors	rgb;
};

/**Structure pour l'objet plan
 * pos		= coordonnées XYZ du plan
 * dir		= Vecteur d'orientation 3d sur l'axe XYZ | range [ -1 / 1 ]
 * rgb		= couleurs RGB du plan | range [ 0 / 255 ]
*/
struct	s_plane
{
	t_coords	pos;
	t_coords	dir;
	t_colors	rgb;
};

/**Structure pour l'objet cylindre
 * pos		= coordonnées XYZ du cylindre
 * dir		= Vecteur d'orientation 3D sur l'axe XYZ | range [ -1 / 1 ]
 * diameter	= diamètre du cylindre
 * height	= hauteur du cylindre
 * rgb		= couleurs RGB du cylindre | range [ 0 / 255 ]
*/
struct	s_cylinder
{
	t_coords	pos;
	t_coords	dir;
	float		diameter;
	float		height;
	t_colors	rgb;
};

#endif //RT_OBJECTS_H