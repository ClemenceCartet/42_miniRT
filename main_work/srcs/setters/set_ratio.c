/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ratio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:51:37 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 10:19:59 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	rt_set_ratio(float *ratio, char *value, char *name)
{
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	dprintf(STDOUT_FILENO, "float ratio : %f\n", *ratio);
	dprintf(STDOUT_FILENO, "char *value : %s\n", value);
	dprintf(STDOUT_FILENO, "char *name : %s\n", name);
	if (rt_check_float_syntax(value, name))
		return (1);
	*ratio = ft_atof(value);
	dprintf(STDOUT_FILENO, "float ratio : %f\n", *ratio);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (0);
}
