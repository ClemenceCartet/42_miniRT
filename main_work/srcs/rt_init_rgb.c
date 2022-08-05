/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:24:43 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/05 14:31:32 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Check splitlen and syntax of each values for struct rgb
int	rt_check_rgb(char **split)
{
	int	a;

	a = 0;
	if (ft_splitlen(split) != 3)
	{
		ft_free_split(split);
		return (rt_write_int_error(E_SPLIT_SIZE, "rgb"));
	}
	while (split[a])
	{
		if (rt_check_rgb_syntax(split[a]))
		{
			ft_free_split(split);
			return (1);
		}
		a++;
	}
	return (0);
}

//Initialize rgb struct for Ambient Light, Light, Sphere, Plane and Cylinder
t_colors	*rt_init_rgb(char *values)
{
	t_colors	*rgb;
	char		**split;

	rgb = NULL;
	if (rt_check_values(values, VALRGB_CHARSET, "rgb"))
		return (NULL);
	split = ft_split(values, ',');
	if (!split)
		return (rt_write_ptr_error(E_MALLOC, NULL));
	if (rt_check_rgb(split))
		return (NULL);
	rgb = rt_calloc_struct(split, sizeof(t_colors));
	if (!rgb)
		return (NULL);
	rgb->r = ft_atoi(split[0]);
	rgb->g = ft_atoi(split[1]);
	rgb->b = ft_atoi(split[2]);
	ft_free_split(split);
	return (rgb);
}
