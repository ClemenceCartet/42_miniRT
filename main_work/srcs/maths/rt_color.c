/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:12:21 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/14 13:07:32 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

t_color	rt_color_bkg(void)
{
	t_color	color;

	ft_memset(&color, 0, sizeof(t_color));
	return (color);
}

t_color	rt_add_color(t_color c1, t_color c2)
{
	t_color	new;

	ft_memset(&new, 0, sizeof(t_color));
	new.r = c1.r + c2.r;
	if (new.r > 1.0)
		new.r = 1.0;
	new.g = c1.g + c2.g;
	if (new.g > 1.0)
		new.g = 1.0;
	new.b = c1.b + c2.b;
	if (new.b > 1.0)
		new.b = 1.0;
	return (new);
}

t_color	rt_scale_color(t_color c1, float ratio)
{
	t_color	new;

	ft_memset(&new, 0, sizeof(t_color));
	new.r = c1.r * ratio;
	if (new.r > 1.0)
		new.r = 1.0;
	new.g = c1.g * ratio;
	if (new.g > 1.0)
		new.g = 1.0;
	new.b = c1.b * ratio;
	if (new.b > 1.0)
		new.b = 1.0;
	return (new);
}

t_color	rt_reflt_color(t_color light, t_color obj)
{
	t_color	new;

	ft_memset(&new, 0, sizeof(t_color));
	new.r = light.r * obj.r;
	new.g = light.g * obj.g;
	new.b = light.b * obj.b;
	return (new);
}

t_color	rt_create_color(float r, float g, float b)
{
	t_color	new;

	ft_memset(&new, 0, sizeof(t_color));
	new.r = r;
	new.g = g;
	new.b = b;
	return (new);
}