/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:48:12 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 09:01:10 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRINGS_H
# define FT_STRINGS_H

# include <libft.h>

/*/////////////////////////////////////////////////////////////////////////////
		STR FUNCTIONS
*//////////////////////////////////////////////////////////////////////////////

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);

int		ft_int_strchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnjoin(const char *s1, const char *s2, ssize_t index);
char	*ft_unsplit(char **split, char c);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strncat(char *dst, const char *src, size_t len);
char	*ft_strfreejoin(const char *s1, const char *s2);

#endif //FT_STRINGS_H