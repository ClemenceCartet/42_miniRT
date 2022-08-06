/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:23:22 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/06 13:32:51 by ljohnson         ###   ########lyon.fr   */
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

# define PARSING_CHARSET "ACLsplcy0123456789-+., \n"
# define INT_CHARSET "0123456789"
# define FLOAT_CHARSET "0123456789-+."

# define VALRGB_CHARSET "0123456789,"
# define COORD_CHARSET "0123456789,+-"

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

# define E_ID			"RT ID ERROR: Invalid ID:"
# define E_EXISTING_ID	"RT ID ERROR: There is already one:"
# define E_SPLIT_SIZE	"RT PARSING ERROR: Wrong number of value for:"
# define E_RANGE		"RT RANGE ERROR: Value must be in range:"
# define E_SYNTAX		"RT VALUE ERROR: Invalid syntax:"
# define E_NUMBER		"RT VALUE ERROR: Invalid number:"
# define E_NO_VALUE		"RT VALUE ERROR: No value found:"

#endif //RT_DEFINES_H