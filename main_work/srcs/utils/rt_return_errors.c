/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_return_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:02:00 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/18 09:58:23 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Free splits used
static void	ft_free_split_error(char **split1, char **split2)
{
	if (split1)
	{
		ft_free_split(split1);
		split1 = NULL;
	}
	if (split2)
	{
		ft_free_split(split2);
		split2 = NULL;
	}
}

//Free splits used, call write error if needed and return int error
int	rt_ret_int_error(char **s1, char **s2, char *str, char *str2)
{
	ft_free_split_error(s1, s2);
	if (str)
		return (rt_write_int_error(str, str2, DFI, DLI));
	return (1);
}

//Free splits used, call write error if needed and return void* error
void	*rt_ret_ptr_error(char **s1, char **s2, char *str, char *str2)
{
	ft_free_split_error(s1, s2);
	if (str)
		return (rt_write_ptr_error(str, str2, DFI, DLI));
	return (NULL);
}

//Free splits used, call write error if needed and return char error
char	*rt_ret_char_error(char **s1, char **s2, char *str, char *str2)
{
	ft_free_split_error(s1, s2);
	if (str)
		return (rt_write_char_error(str, str2, DFI, DLI));
	return (NULL);
}

//Free splits used, call write error if needed and return split error
char	**rt_ret_split_error(char **s1, char **s2, char *str, char *str2)
{
	ft_free_split_error(s1, s2);
	if (str)
		return (rt_write_split_error(str, str2, DFI, DLI));
	return (NULL);
}
