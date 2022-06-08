/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_float_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:20:29 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:46:20 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Check str to see if it can be converted to float correctly
int	rt_check_float_syntax(char *str, char *name)
{
	int	a;
	int	point;

	a = 0;
	point = 0;
	while (str[a])
	{
		if (!ft_isdigit(str[a]))
		{
			if ((point && str[a] == '.'))
				return (rt_write_int_error(E_SYNTAX, name));
			else if (a > 0 && (str[a] == '-' || str[a] == '+'))
				return (rt_write_int_error(E_SYNTAX, name));
			else if (!point && str[a] == '.')
				point = 1;
			else if (!ft_ischarset(str[a], FLOAT_CHARSET))
				return (rt_write_int_error(E_CONTENT, name));
		}
		a++;
	}
	return (0);
}
