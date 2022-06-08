/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value_fov.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:51:40 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/08 09:58:57 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	rt_init_value_fov(char *value, char *name)
{
	int	fov;

	fov = -1;
	if (rt_check_value_format(value, INT_CHARSET))
		return (-1);
	fov = ft_atoi(value);
	if (fov < 0 || fov > 180)
		return (rt_write_int_error(E_RANGE, name) * -1);
	return (fov);
}
