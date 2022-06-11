/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counters.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:49:16 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/11 09:26:31 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COUNTERS_H
# define FT_COUNTERS_H

# include <libft.h>

/*/////////////////////////////////////////////////////////////////////////////
		COUNT FUNCTIONS
*//////////////////////////////////////////////////////////////////////////////

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);

size_t	ft_count_word(const char *str, const char c);
size_t	ft_count_char(long nb);
size_t	ft_splitlen(char **split);
size_t	ft_atoi_check(const char *str, int *negative);
size_t	ft_count_specific_char(char *str, int c);

#endif //FT_COUNTERS_H