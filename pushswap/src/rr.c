/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:57:30 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/19 19:48:37 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info)
{
	int a_num;

	if (info->a_size == 1)
		return ;
	if (info->a_size == 2)
		sa(info);
	else
	{
		a_num = info->a_top->num;
		listAddBackA(info, &info->a_top, a_num);
		listRemoveFrontA(info);
		ft_putstr("ra\n");
	}
}

void	rb(t_info *info)
{
	int b_num;

	if (info->b_size == 1)
		return ;
	if (info->b_size == 2)
		sa(info);
	else
	{
		b_num = info->b_top->num;
		listAddBackA(info, &info->b_top, b_num);
		listRemoveFrontA(info);
		ft_putstr("ra\n");
	}
}

void rr(t_info *info)
{
	ra(info);
	rb(info);
	ft_putstr("rr\n");
}