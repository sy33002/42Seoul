/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:27:53 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/19 19:33:29 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_info *info)
{
	t_num	*tmp;

	tmp = info->a_top;
	while (tmp != NULL)
	{
		info->a_bottom_num = tmp->num;
		tmp = tmp->next;
	}
	if (info->a_size == 1)
		return ;
	if (info->a_size == 2)
		sa(info);
	else 
	{
		listAddFrontA(info, info->a_bottom_num);
		listRemoveBackA(info);
		ft_putstr("rra\n");
	}
}


void	rrb(t_info *info)
{
	t_num	*tmp;

	tmp = info->b_top;
	while (tmp != NULL)
	{
		info->b_bottom_num = tmp->num;
		tmp = tmp->next;
	}
	if (info->b_size == 1)
		return ;
	if (info->b_size == 2)
		sa(info);
	else 
	{
		listAddFrontB(info, info->b_bottom_num);
		listRemoveBackB(info);
		ft_putstr("rra\n");
	}
}


// void	rrr(t_info *info)
// {
// 	rra(info);
// 	rrb(info);
// 	ft_putstr("rrr\n");
// }
