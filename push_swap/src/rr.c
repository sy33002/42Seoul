/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:57:30 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/24 12:53:26 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info, char *str)
{
	int	a_num;

	if (info->a_size == 1)
		return ;
	if (info->a_size == 2)
		sa(info, "sa\n");
	else
	{
		a_num = info->a_top->num;
		list_add_back_a(info, &info->a_top, a_num);
		list_remove_front_a(info);
		ft_putstr(str);
	}
}

void	rb(t_info *info, char *str)
{
	int	b_num;

	if (info->b_size == 1)
		return ;
	if (info->b_size == 2)
		sb(info, "sb\n");
	else
	{
		b_num = info->b_top->num;
		list_add_back_b(info, &info->b_top, b_num);
		list_remove_front_b(info);
		ft_putstr(str);
	}
}

void	rr(t_info *info)
{
	ra(info, "");
	rb(info, "");
	ft_putstr("rr\n");
}
