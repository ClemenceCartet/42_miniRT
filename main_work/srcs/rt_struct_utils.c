/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:25:52 by ljohnson          #+#    #+#             */
/*   Updated: 2022/07/06 09:26:08 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Check if ACL ptr is already present and number of value given is correct
int	rt_check_struct(void *ptr, char **split, size_t splitlen, char *name)
{
	if (ptr && (ft_strncmp(name, "ambient light", 14)
			|| ft_strncmp(name, "camera", 7) || ft_strncmp(name, "light", 6)))
	{
		ft_free_split(split);
		return (rt_write_int_error(E_EXISTING_ID, name));
	}
	if (ft_splitlen(split) != splitlen)
	{
		ft_free_split(split);
		return (rt_write_int_error(E_SPLIT_SIZE, name));
	}
	return (0);
}

//Initialize a structure using calloc with a given size
void	*rt_calloc_struct(char **split, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(1, size);
	if (!ptr)
	{
		ft_free_split(split);
		return (rt_write_ptr_error(E_MALLOC, NULL));
	}
	return (ptr);
}
