/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:51:56 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/05/02 23:07:20 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lstend;

	lstend = *lst;
	if (lst || *lst)
	{
		while (*lst)
		{
			*lst = lstend->next;
			del(lstend->content);
			free(lstend);
			lstend = *lst;
		}
	}
}
