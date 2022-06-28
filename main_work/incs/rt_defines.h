/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:23:22 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/28 15:29:56 by ljohnson         ###   ########lyon.fr   */
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

#endif //RT_DEFINES_H