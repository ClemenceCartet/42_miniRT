/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_master.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:40:09 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:43:28 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Main function for the initialization and parsing of the program
int	rt_parse_master(t_master *master, char *filename)
{
	char	*content;

	if (rt_init_master(master))
		return (1);
	content = rt_get_file_content(filename);
	if (rt_check_file_content(content))
		return (1);
	if (rt_parse_file_content(master, content))
		return (1);
	return (0);
}
