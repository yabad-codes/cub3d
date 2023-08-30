/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:36:51 by ael-maar          #+#    #+#             */
/*   Updated: 2022/10/09 11:06:38 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_lst;

	temp_lst = (*lst);
	if (temp_lst)
	{
		while ((temp_lst)->next != 0)
			temp_lst = temp_lst->next;
		temp_lst->next = new;
		return ;
	}
	*lst = new;
}
