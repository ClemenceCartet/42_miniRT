/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:23:22 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/13 18:24:26 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DEFINES_H
# define RT_DEFINES_H

# include <mini_rt.h>

/*/////////////////////////////////////////////////////////////////////////////
		DEFINES
*//////////////////////////////////////////////////////////////////////////////

# define W 1280
# define H 720

# define SP 1
# define PL 2
# define CY 3

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

#endif //RT_DEFINES_H