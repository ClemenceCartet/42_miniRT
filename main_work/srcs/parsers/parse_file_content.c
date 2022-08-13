/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:40:51 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:43:12 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Split content with \n and iterates through that split to init values
int	rt_parse_file_content(t_master *master, char *content)
{
	char	**split;
	int		a;

	a = 0;
	split = ft_split(content, '\n');
	if (!split)
	{
		ft_free(&content);
		return (rt_write_int_error(E_MALLOC, NULL));
	}
	ft_free(&content);
	while (split[a])
	{
		if (rt_parse_line(master, split[a]))
		{
			ft_free_split(split);
			return (1);
		}
		a++;
	}
	ft_free_split(split);
	master->object->start = master->object->lst;
	return (0);
}
