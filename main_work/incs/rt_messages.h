/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_messages.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:01:20 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/01 10:42:12 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MESSAGES_H
# define RT_MESSAGES_H

# include <mini_rt.h>

# define DFI		__FILE__
# define DLI		__LINE__
# define DFU		(char *)__FUNCTION__

/*/////////////////////////////////////////////////////////////////////////////
		MESSAGES
*//////////////////////////////////////////////////////////////////////////////

# define E_MALLOC		"RT CODE ERROR: Malloc error"

# define E_USAGE		"RT PROGRAM ERROR: Usage is ./MiniRT scene.rt"
# define E_NO_FILENAME	"RT FILE ERROR: Filename does not exist"
# define E_NO_EXT		"RT FILE ERROR: No file extension"
# define E_WRONG_EXT	"RT FILE ERROR: Wrong file extension"

# define E_OPEN			"RT FILE ERROR: There was an error while opening file "
# define E_READ			"RT FILE ERROR: There was an error while reading file "
# define E_CLOSE		"RT FILE ERROR: There was an error while closing file "

# define E_EMPTY		"RT FILE ERROR: File content is empty"
# define E_UNKNOWN		"RT FILE ERROR: Unknown character found in file content"

# define E_ID			"RT ID ERROR: Invalid ID found in content"
# define E_EXISTING_ID	"RT ID ERROR: There is already one "
# define E_SPLIT_SIZE	"RT PARSING ERROR: Wrong number of value for "
# define E_RANGE		"RT RANGE ERROR: Value must be in range "
# define E_MISSING		"RT VALUE ERROR: Missing value for "

#endif // RT_MESSAGES_H