/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:48:20 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/18 09:57:17 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Initialize a structure using calloc with a given size
void	*rt_calloc_struct(size_t size, char **split)
{
	void	*ptr;

	ptr = ft_calloc(1, size);
	if (!ptr)
		return (rt_ret_ptr_error(split, NULL, E_MALLOC, NULL));
	return (ptr);
}

//Check overflow, float syntax and range to initialize diameter and height
float	rt_init_obj_size(char **data, char *value)
{
	float	obj_size;

	if (rt_check_overflow(value, data))
		return (-1);
	if (rt_check_float_syntax(value))
		return (rt_ret_int_error(data, NULL, NULL, NULL) * -1);
	obj_size = ft_atof(value);
	if (rt_check_float_range(obj_size, 0, 0, "Positive"))
		return (rt_ret_int_error(data, NULL, NULL, NULL) * -1);
	return (obj_size);
}

//Check overflow, float syntax and range to initalize ratio value
float	rt_init_ratio(char **data, char *value)
{
	float	ratio;

	if (rt_check_overflow(value, data))
		return (-1);
	if (rt_check_float_syntax(value))
		return (rt_ret_int_error(data, NULL, NULL, NULL) * -1);
	ratio = ft_atof(value);
	if (rt_check_float_range(ratio, 0, 1, "0 / 1"))
		return (rt_ret_int_error(data, NULL, NULL, NULL) * -1);
	return (ratio);
}

//CHeck overflow, int syntax and range to initialize FOV value
int	rt_init_fov(char **data, char *value)
{
	int	fov;

	if (rt_check_overflow(value, data))
		return (-1);
	if (rt_check_charset(value, INT_CHARSET))
		return (rt_ret_int_error(data, NULL, NULL, NULL) * -1);
	fov = ft_atoi(value);
	if (rt_check_int_range(fov, 0, 180, "0 / 180"))
		return (rt_ret_int_error(data, NULL, NULL, NULL) * -1);
	return (fov);
}
