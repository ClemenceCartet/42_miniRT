/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:23:22 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/10 14:25:22 by ljohnson         ###   ########lyon.fr   */
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

# define ID_X 0
# define ID_Y 1
# define ID_Z 2
# define ID_O 3

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

/*/////////////////////////////////////////////////////////////////////////////
		WINDOW COMMAND & INFO DISPLAY
*//////////////////////////////////////////////////////////////////////////////

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
# define STR13			"Tilt Left: U"
# define STR14			"Tilt Right : O"

# define STR15			"Axis selection"
# define STR16			"X Axis : X"
# define STR17			"Y Axis : Y"
# define STR18			"Z Axis : Z"

# define STR19			"Object Selection"
# define STR20			"Prev Object : Left Arrow"
# define STR21			"Next Object : Right Arrow"
# define STR22			"Switch size parameter : T"

# define STR23			"Object movement on selected axis"
# define STR24			"Increase value : Up Arrow"
# define STR25			"Decrease value : Down Arrow"

# define STR26			"Light movement on selected axis"
# define STR27			"Increase value : Numpad 8"
# define STR28			"Decrease value : Numpad 2"

# define STR29			"Object size modification"
# define STR30			"Increase size : Numpad +"
# define STR31			"Decrease size : Numpad -"

# define STR32			"Currently selected Object"
# define STR33			"Object Type = "
# define STR34			"Sphere"
# define STR35			"Plane"
# define STR36			"Cylinder"
# define STR37			"Index = "

# define STR38			"Selected Axis = "
# define STR39			"Selected Size = "
# define STR40			"Diameter"
# define STR41			"Height"

#endif //RT_DEFINES_H