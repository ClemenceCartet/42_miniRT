/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:57:19 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 13:50:25 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSIONS_H
# define FT_CONVERSIONS_H

# include <libft.h>

/*/////////////////////////////////////////////////////////////////////////////
		CONVERSION FUNCTIONS
*//////////////////////////////////////////////////////////////////////////////

int		ft_atoi(const char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_itoa(int n);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

long	ft_atol(const char *str);
int		ft_big_atoi(const char *str);
long	ft_big_atol(const char *str);
void	ft_swap(int *a, int *b);
char	*ft_str_toupper(const char *str);
char	*ft_str_tolower(const char *str);
int		ft_add_str_to_int(const char *str, int *a);
float	ft_atof(const char *str);

#endif //FT_CONVERSIONS_H