/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:20:58 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/19 19:49:08 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_info *info)
{
	int tmp;

	tmp = info->a_top->num;
	info->a_top->num = info->a_top->next->num;
	info->a_top->next->num = tmp;
	ft_putstr("sa\n");
}

void	sb(t_info *info)
{
	int tmp;

	tmp = info->b_top->num;
	info->b_top->num = info->b_top->next->num;
	info->b_top->next->num = tmp;
	ft_putstr("sb\n");
}

void	ss(t_info *info)
{
	sa(info);
	sb(info);
	ft_putstr("ss\n");
}

void	pa(t_info *info)
{
	int	i;

	if (info->b_size == 0)
		return ;
	i = info->b_top->num;
	listAddFrontA(info, i);
	listRemoveFrontB(info);
	ft_putstr("pb\n");
}

void	pb(t_info *info)
{
	int	i;

	if (info->a_size == 0)
		return ;
	i = info->a_top->num;
	listAddFrontB(info, i);
	listRemoveFrontA(info);
	ft_putstr("pb\n");
}