/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:27:01 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:45:09 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	t_list	*last;

	last = NULL;
	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = newlst;
		}
		else
			*lst = newlst;
	}
}
