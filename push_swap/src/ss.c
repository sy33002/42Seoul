/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:20:58 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/24 12:54:00 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info, char *str)
{
	int	tmp;

	tmp = info->a_top->num;
	info->a_top->num = info->a_top->next->num;
	info->a_top->next->num = tmp;
	ft_putstr(str);
}

void	sb(t_info *info, char *str)
{
	int	tmp;

	tmp = info->b_top->num;
	info->b_top->num = info->b_top->next->num;
	info->b_top->next->num = tmp;
	ft_putstr(str);
}

void	ss(t_info *info)
{
	sa(info, NULL);
	sb(info, NULL);
	ft_putstr("ss\n");
}

void	pa(t_info *info, char *str)
{
	int	i;

	if (info->b_size == 0)
		return ;
	i = info->b_top->num;
	list_add_front_a(info, i);
	list_remove_front_b(info);
	ft_putstr(str);
}

void	pb(t_info *info, char *str)
{
	int	i;

	if (info->a_size == 0)
		return ;
	i = info->a_top->num;
	list_add_front_b(info, i);
	list_remove_front_a(info);
	ft_putstr(str);
}
