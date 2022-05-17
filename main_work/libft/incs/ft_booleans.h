/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_booleans.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:40:47 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 09:00:29 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEANS_H
# define FT_BOOLEANS_H

# include <libft.h>

/*/////////////////////////////////////////////////////////////////////////////
		BOOLEAN FUNCTIONS
*//////////////////////////////////////////////////////////////////////////////

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

int		ft_ischarset(char c, char *set);
int		ft_isnotcharset(char c, char *set);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isspace(int c);
int		ft_isprime(int nb);

#endif //FT_BOOLEANS_H