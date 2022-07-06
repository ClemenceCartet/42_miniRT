/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:23:22 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/06 11:23:34 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DEFINES_H
# define RT_DEFINES_H

# include <mini_rt.h>

/*/////////////////////////////////////////////////////////////////////////////
		DEFINES
*//////////////////////////////////////////////////////////////////////////////

# define SP 1
# define PL 2
# define CY 3

# define PARSING_CHARSET "ACLsplcy1234567890-+., \n"
# define RGB_CHARSET "1234567890"
# define FLOAT_CHARSET "1234567890-+."
# define INT_CHARSET "1234567890-+"

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
# define E_WRONG_EXT	"RT FILE ERROR: Wrong file extension:"

# define E_OPEN			"RT FILE ERROR: Error while opening file:"
# define E_READ			"RT FILE ERROR: Error while reading file:"
# define E_CLOSE		"RT FILE ERROR: Error while closing file:"

# define E_MISSING		"RT INIT ERROR: Missing data:"

// # define E_UNKNOWN		"RT FILE ERROR: Unknown character found in file content"

# define E_ID			"RT ID ERROR: Invalid ID:"
# define E_EXISTING_ID	"RT ID ERROR: There is already one:"
# define E_SPLIT_SIZE	"RT PARSING ERROR: Wrong number of value for:"
// # define E_RANGE		"RT RANGE ERROR: Value must be in range "
// # define E_MISSING		"RT VALUE ERROR: Missing value for "
// # define E_FORMAT		"RT VALUE ERROR: Invalid format for "
// # define E_SYNTAX		"RT VALUE ERROR: Invalid syntax for "
// # define E_CONTENT		"RT VALUE ERROR: Invalid content for "
// # define E_NUMBER		"RT VALUE ERROR: Invalid number for "
// # define E_NO_VALUE		"RT VALUE ERROR: No value found"

#endif //RT_DEFINES_H