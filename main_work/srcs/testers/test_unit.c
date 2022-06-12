/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:37:55 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/12 09:47:24 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	test_unit(void)
{
	dprintf(STDOUT_FILENO, "\033[33m\033[1mexpected | given | value\033[0m\n");
	// test_fov();
	test_rgb();
	// test_ratio();
	// test_size();
}
