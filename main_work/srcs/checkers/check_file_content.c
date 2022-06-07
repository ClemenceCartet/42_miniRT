/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:48:55 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:40:18 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Check content to see if the file content is valid
int	rt_check_file_content(char *content)
{
	int	a;

	a = 0;
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
	return (0);
}
