/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:17:51 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/12 13:22:35 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Initialize a structure using calloc with a given size
void	*rt_calloc_struct(size_t size, char **split)
{
	void	*ptr;

	ptr = ft_calloc(1, size);
	if (!ptr)
		return (rt_return_ptr_error(split, NULL, E_MALLOC, NULL));
	return (ptr);
}

//Check overflow, float syntax and range to initalize ratio value
float	rt_init_ratio(char **data, char *value)
{
	float	ratio;

	if (rt_check_overflow(value, data))
		return (-1);
	if (rt_check_float_syntax(value))
		return (rt_return_int_error(data, NULL, NULL, NULL) * -1);
	ratio = ft_atof(value);
	if (rt_check_float_range(ratio, 0, 1, "0 / 1"))
		return (rt_return_int_error(data, NULL, NULL, NULL) * -1);
	return (ratio);
}

//Light initialization (L)
int	rt_init_light(t_light **light, char **split)
{
	if (rt_check_ptr(*light, split))
		return (1);
	if (rt_check_splitlen(split, 4, "light"))
		return (1);
	*light = rt_calloc_struct(sizeof(t_light), split);
	if (!*light)
		return (1);
	(*light)->pos = rt_init_coords(split, split[1], 0);
	if (!(*light)->pos)
		return (1);
	(*light)->ratio = rt_init_ratio(split, split[2]);
	if ((*light)->ratio == -1)
		return (1);
	(*light)->rgb = rt_init_rgb(split, split[3]);
	if (!(*light)->rgb)
		return (1);
	ft_free_split(split);
	return (0);
}