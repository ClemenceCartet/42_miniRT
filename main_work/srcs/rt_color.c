/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:12:21 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/03 09:12:22 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

t_color	rt_color_bkg(void)
{
	t_color	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	return (color);
}

t_color	rt_add_color(t_color c1, t_color c2)
{
	t_color	new;

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

	new.r = light.r * obj.r;
	new.g = light.g * obj.g;
	new.b = light.b * obj.b;
	return (new);
}
