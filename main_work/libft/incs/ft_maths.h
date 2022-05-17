/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:51:35 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:45:01 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATHS_H
# define FT_MATHS_H

# include <libft.h>

/*/////////////////////////////////////////////////////////////////////////////
		MATHS FUNCTIONS
*//////////////////////////////////////////////////////////////////////////////

int		ft_approx_sqrt(int nb);
int		ft_sqrt(int nb);
int		ft_factorial(int nb);
int		ft_power(int nb, int power);
int		ft_get_highest(int nb1, int nb2);
int		ft_get_lowest(int nb1, int nb2);
int		ft_find_next_prime(int nb);

#endif //FT_MATHS_H