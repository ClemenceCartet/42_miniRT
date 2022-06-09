/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:53:04 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/09 13:04:25 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	rt_init_value_rgb(char *value, int index, char *name)
{
	char	**split;
	int		rgb;

	rgb = -1;
	split = rt_get_split_from_raw(value, ',', 3, name);
	if (!split)
		return (-1);
	if (rt_check_value_format(split[index], RGB_CHARSET))
		return (-1);
	rgb = ft_atoi(split[index]);
	if (rgb > 255 || rgb < 0)
		return (rt_write_int_error(E_RANGE, "0/255") * -1);
	ft_free_split(split);
	return (rgb);
}
