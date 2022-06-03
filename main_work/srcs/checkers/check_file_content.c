/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:48:55 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/03 09:19:56 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Check content to see if the file content is valid
int	rt_check_file_content(char *content)
{
	int	a;

	a = 0;
	dprintf(STDOUT_FILENO, "\n\033[35m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	// dprintf(STDOUT_FILENO, "char *content :\n%s\n\n", content);
	if (!content || !content[0])
	{
		if (!content[0])
			ft_free(&content);
		return (rt_write_int_error(E_EMPTY, NULL));
	}
	while (content[a])
	{
		if (!ft_ischarset(content[a], PARSING_CHARSET))
		{
			ft_free(&content);
			return (rt_write_int_error(E_UNKNOWN, NULL));
		}
		a++;
	}
	dprintf(STDOUT_FILENO, "\n\033[36m\033[1m%s | %d | %s\033[0m\n", DFI, DLI, DFU);
	return (0);
}
