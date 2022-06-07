/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ratio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:51:37 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:43:56 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	rt_set_ratio(float *ratio, char *value, char *name)
{
	if (rt_check_float_syntax(value, name))
		return (1);
	*ratio = ft_atof(value);
	return (0);
}
