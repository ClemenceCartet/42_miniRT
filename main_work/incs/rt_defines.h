/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:23:22 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/15 14:13:33 by ljohnson         ###   ########lyon.fr   */
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

# define STR4			"Camera View"
# define STR7			"Look Left : A"
# define STR8			"Look Right : D"

# define STR9			"Axis selection"
# define STR10			"X Axis : X"
# define STR11			"Y Axis : Y"
# define STR12			"Z Axis : Z"

# define STR13			"Object Selection"
# define STR14			"Prev Object : Left Arrow"
# define STR15			"Next Object : Right Arrow"
# define STR16			"Switch size parameter : T"

# define STR17			"Object movement on selected axis"
# define STR18			"Increase value : Up Arrow"
# define STR19			"Decrease value : Down Arrow"

# define STR20			"Light movement on selected axis"
# define STR21			"Increase value : EQUAL / PLUS"
# define STR22			"Decrease value : MINUS"

# define STR23			"Object size modification"
# define STR24			"Increase size : Numpad +"
# define STR25			"Decrease size : Numpad -"

# define STR26			"Currently selected Object"
# define STR27			"Object Type = "
# define STR28			"Sphere"
# define STR29			"Plane"
# define STR30			"Cylinder"
# define STR31			"Index = "

# define STR32			"Object Orientation"
# define STR33			"Y Axis Up : Numpad 8"
# define STR34			"Y Axis Down : Numpad 2"
# define STR35			"X Axis Up : Numpad 4"
# define STR36			"X Axis Down : Numpad 6"

# define STR37			"Selected Axis = "
# define STR38			"Selected Size = "
# define STR39			"Diameter"
# define STR40			"Height"

#endif //RT_DEFINES_H