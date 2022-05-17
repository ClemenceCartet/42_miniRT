/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:27:03 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:45:10 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_front(t_list **lst, t_list *newlst)
{
	if (lst)
	{
		newlst->next = *lst;
		*lst = newlst;
	}
}
