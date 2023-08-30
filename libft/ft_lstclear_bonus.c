/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:55:54 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/09 11:11:28 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_node;

	if (lst && del)
	{
		while (*lst)
		{
			temp_node = *lst;
			*lst = (*lst)->next;
			ft_lstdelone(temp_node, del);
		}
		*lst = 0;
	}
}
