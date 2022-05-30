/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_messages.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:01:20 by ljohnson          #+#    #+#             */
/*   Updated: 2022/05/30 11:29:22 by ljohnson         ###   ########lyon.fr   */
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

# define E_MALLOC		"RT ERROR: Malloc error"

# define E_USAGE		"RT ERROR: Usage is ./MiniRT scene.rt"
# define E_NO_FILENAME	"RT ERROR: Filename does not exist"
# define E_NO_EXT		"RT ERROR: No file extension"
# define E_WRONG_EXT	"RT ERROR: Wrong file extension"

# define E_OPEN			"RT ERROR: There was an error while opening file "
# define E_READ			"RT ERROR: There was an error while reading file "
# define E_CLOSE		"RT ERROR: There was an error while closing file "

# define E_EMPTY		"RT ERROR: File content is empty"
# define E_UNKNOWN		"RT ERROR: Unknown character found in file content"

#endif // RT_MESSAGES_H