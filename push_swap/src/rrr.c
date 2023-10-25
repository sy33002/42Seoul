/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:27:53 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/24 12:53:47 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_info *info, char *str)
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
		sa(info, "sa\n");
	else
	{
		list_add_front_a(info, info->a_bottom_num);
		list_remove_back_a(info);
		ft_putstr(str);
	}
}

void	rrb(t_info *info, char *str)
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
		sa(info, "sa\n");
	else
	{
		list_add_front_b(info, info->b_bottom_num);
		list_remove_back_b(info);
		ft_putstr(str);
	}
}

void	rrr(t_info *info)
{
	rra(info, NULL);
	rrb(info, NULL);
	ft_putstr("rrr\n");
}
