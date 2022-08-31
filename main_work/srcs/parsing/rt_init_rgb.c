/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:19:42 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/30 14:14:23 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Check splitlen, existence, rgb syntax, overflow, isnan, isinf, range
static int	rt_check_rgb_data(char **data, char **split)
{
	int	a;
	int	tmp;

	if (ft_splitlen(split) != 3)
		return (rt_ret_int_error(data, split, E_SPLITLEN, "rgb"));
	a = 0;
	while (split[a])
	{
		if (!split[a] || !split[a][0])
			return (rt_ret_int_error(data, split, E_NO_VALUE, NULL));
		if (rt_check_charset(split[a], INT_CHARSET))
			return (rt_ret_int_error(data, split, NULL, NULL));
		if (rt_check_overflow(split[a], split))
			return (rt_ret_int_error(data, NULL, NULL, NULL));
		tmp = ft_atoi(split[a]);
		if (rt_check_int_range(tmp, 0, 255, "0 / 255"))
			return (rt_ret_int_error(data, split, NULL, NULL));
		a++;
	}
	return (0);
}

//Initialize color module for rgb (A, L, SP, PL, CY)
t_color	*rt_init_rgb(char **data, char *values)
{
	t_color	*color;
	char	**split;

	if (rt_check_comma(values))
		return (rt_ret_ptr_error(data, NULL, NULL, NULL));
	split = ft_split(values, ',');
	if (!split)
		return (rt_ret_ptr_error(data, split, E_MALLOC, NULL));
	if (rt_check_rgb_data(data, split))
		return (NULL);
	color = rt_calloc_struct(sizeof(t_color), split);
	if (!color)
		return (rt_ret_ptr_error(data, split, NULL, NULL));
	color->r = ft_atof(split[0])/ 255;
	color->g = ft_atof(split[1])/ 255;
	color->b = ft_atof(split[2])/ 255;
	ft_free_split(split);
	return (color);
}
