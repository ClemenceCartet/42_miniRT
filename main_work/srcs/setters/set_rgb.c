/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:52:21 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 11:02:53 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	rt_set_rgb(int rgb[3], char *value, char *name)
{
	char	**split;
	int		a;

	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	dprintf(STDOUT_FILENO, "char *value : %s\n", value);
	dprintf(STDOUT_FILENO, "char *name : %s\n", name);
	dprintf(STDOUT_FILENO, "int rgb[0]: %d\n", rgb[0]);
	dprintf(STDOUT_FILENO, "int rgb[1]: %d\n", rgb[1]);
	dprintf(STDOUT_FILENO, "int rgb[2]: %d\n", rgb[2]);
	a = 0;
	split = rt_get_split_from_raw(value, ',', 3, name);
	if (!split)
		return (1);
	test_split_values(split);
	while (split[a])
	{
		if (rt_check_value_format(split[a], RGB_CHARSET))
			return (rt_write_int_error(E_FORMAT, split[a]));
		rgb[a] = ft_atoi(split[a]);
		if (rgb[a] > 255 || rgb[a] < 0)
			return (rt_write_int_error(E_RANGE, "0/255"));
		a++;
	}
	dprintf(STDOUT_FILENO, "int rgb[0]: %d\n", rgb[0]);
	dprintf(STDOUT_FILENO, "int rgb[1]: %d\n", rgb[1]);
	dprintf(STDOUT_FILENO, "int rgb[2]: %d\n", rgb[2]);
	ft_free_split(split);
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (0);
}
