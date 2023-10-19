/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   littleSort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:17:16 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/19 19:44:58 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	littleSort(t_info *info)
{
	int a_num;

    a_num = info->a_top->num;
	if (info->a_size == 2)
	{
		if (a_num > info->a_top->next->num)
			sa(info);
	}
	else if (info->a_size == 3)
		threeSort(info);
	else if (info->a_size == 4)
		fourSort(info);
	// else if (info->a_size == 5)
	// 	fiveSort(info);
	else
		bigSort(info);
}

void	threeSort(t_info *info)
{
	int	top;
	int	mid;
	int	bot;

	top = info->a_top->num;
	mid = info->a_top->next->num;
	while (info->a_top != NULL) 
	{
        info->a_bottom_num = info->a_top->num;
        info->a_top = info->a_top->next;
	}
	bot = info->a_bottom_num;
	if (top < mid && top > bot)
		rra(info);
	if (mid < top && top < bot)
		sa(info);
	if (mid < top && mid < bot && bot < top)
		ra(info);
	if (mid < top && bot < top && bot < mid)
	{
		sa(info);
		rra(info);
	}
}

int	findIndex(t_info *info, int find)
{
	int		i;

	i = 0;
	while (info->a_top != NULL)
	{
		if (info->a_top->num == find)
			return (i);
		info->a_top = info->a_top->next;
		i++;
	}
	return (i);
}

void	fourSort(t_info *info)
{
	int	i;

	i = 0;
	while (info->a_top != NULL)
	{
		if (info->a_top->num == 0)
			break ;
		info->a_top = info->a_top->next;
		i++;
	}
	if (i >= info->a_size)
		i = -1;
	if (i < info->a_size / 2)
	{
		while (info->a_top->num != 0)
			ra(info);
	}
	else
	{
		while (info->a_top->num != 0)
			rra(info);
	}
	pb(info);
	threeSort(info);
	pa(info);
}
