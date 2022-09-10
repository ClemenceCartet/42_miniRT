/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:23:22 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/10 13:11:39 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DEFINES_H
# define RT_DEFINES_H

# include <mini_rt.h>

/*/////////////////////////////////////////////////////////////////////////////
		DEFINES
*//////////////////////////////////////////////////////////////////////////////

# define WIDTH 1280
# define HEIGHT 720

# define SP 1
# define PL 2
# define CY 3
# define SQ 4

# define AXIS_X 5
# define AXIS_Y 6
# define AXIS_Z 7

# define SIZE_D 8
# define SIZE_H	9

# define PARSING_CHARSET "ACLsplcy0123456789-+., \n"
# define INT_CHARSET "0123456789"
# define FLOAT_CHARSET "0123456789-+."

# define VALRGB_CHARSET "0123456789,"
# define COORD_CHARSET "0123456789,+-."

# define CHARINT_MAX "2147483647"
# define CHARINT_MIN "-2147483648"

# define DFI	__FILE__
# define DLI	__LINE__
# define DFU	(char *)__FUNCTION__

/*/////////////////////////////////////////////////////////////////////////////
		MESSAGES
*//////////////////////////////////////////////////////////////////////////////

# define E_MALLOC		"RT CODE ERROR: Malloc error"

# define E_USAGE		"RT PROGRAM ERROR: Usage is ./MiniRT scene.rt"
# define E_NO_FILENAME	"RT FILE ERROR: Filename does not exist"
# define E_NO_EXT		"RT FILE ERROR: No file extension in filename:"
# define E_NO_NAME		"RT FILE ERROR: No filename found before extension"
# define E_WRONG_EXT	"RT FILE ERROR: Wrong file extension:"

# define E_OPEN			"RT FILE ERROR: Error while opening file:"
# define E_READ			"RT FILE ERROR: Error while reading file:"
# define E_CLOSE		"RT FILE ERROR: Error while closing file:"

# define E_MISSING		"RT INIT ERROR: Missing data:"

# define E_ID			"RT ID ERROR: Invalid ID"
# define E_EXISTING_ID	"RT ID ERROR: There is already one:"
# define E_SPLITLEN		"RT PARSING ERROR: Wrong number of value for:"
# define E_RANGE		"RT RANGE ERROR: Value must be in range:"
# define E_SYNTAX		"RT VALUE ERROR: Invalid syntax found"
# define E_NUMBER		"RT VALUE ERROR: Invalid number found"
# define E_NO_VALUE		"RT VALUE ERROR: No value found"

# define STR1			"Camera Movements"
# define STR2			"Forward : W"
# define STR3			"Backward : S"
# define STR4			"Left : A"
# define STR5			"Right : D"
# define STR6			"Up : Q"
# define STR7			"Down : E"

# define STR8			"Camera View"
# define STR9			"Look Up : I"
# define STR10			"Look Down : K"
# define STR11			"Look Left : J"
# define STR12			"Look Right : L"

# define STR13			"Axis selection"
# define STR14			"X Axis : X"
# define STR15			"Y Axis : Y"
# define STR16			"Z Axis : Z"

# define STR17			"Object Selection"
# define STR18			"Prev Object : Left Arrow"
# define STR19			"Next Object : Right Arrow"
# define STR20			"Switch size parameter : T"

# define STR21			"Object movement on selected axis"
# define STR22			"Increase value : Up Arrow"
# define STR23			"Decrease value : Down Arrow"

# define STR24			"Light movement on selected axis"
# define STR25			"Increase value : Numpad 8"
# define STR26			"Decrease value : Numpad 2"

# define STR27			"Object size modification"
# define STR28			"Increase size : Numpad +"
# define STR29			"Decrease size : Numpad -"

# define STR30			"Sphere"
# define STR31			"Plane"
# define STR32			"Cylinder"
# define STR33			"Index = "
# define STR34			"Currently selected Object"

# define STR35			"Selected Axis = "
# define STR36			"Selected Size = "
# define STR37			"Diameter"			
# define STR38			"Height"
# define STR39			"Object Type = "			

#endif //RT_DEFINES_H