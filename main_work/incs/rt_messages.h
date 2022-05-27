/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_messages.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:01:20 by ljohnson          #+#    #+#             */
/*   Updated: 2022/05/27 10:07:28 by ljohnson         ###   ########lyon.fr   */
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

#endif // RT_MESSAGES_H