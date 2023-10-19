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

#include "push_swap.h"

void	rra(t_info *info)
{
	while (info->a_top)
	{
		info->a_bottom_num = info->a_top->num;
		info->a_top = info->a_top->next;
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
	while (info->b_top)
	{
		info->b_bottom_num = info->b_top->num;
		info->b_top = info->b_top->next;
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
