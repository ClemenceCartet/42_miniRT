/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_messages.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:01:20 by ljohnson          #+#    #+#             */
/*   Updated: 2022/05/30 09:24:26 by ljohnson         ###   ########lyon.fr   */
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

# define E_USAGE	"RT ERROR: Usage is ./MiniRT scene.rt"
# define E_OPEN		"RT ERROR: Can't open file "
# define E_READ		"RT ERROR: There was an error while reading file "
# define E_CLOSE	"RT ERROR: There was an error while closing file "

#endif // RT_MESSAGES_H