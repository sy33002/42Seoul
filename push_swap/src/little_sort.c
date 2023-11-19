/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:17:16 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/26 16:54:14 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	little_sort(t_info *info)
{
	int	a_num;

	a_num = info->a_top->num;
	if (info->a_size == 2)
	{
		if (a_num > info->a_top->next->num)
			sa(info, "sa\n");
	}
	else if (info->a_size == 3)
		three_sort(info);
	else if (info->a_size == 4)
		four_sort(info);
	else if (info->a_size == 5)
		five_sort(info);
	else
		bigger_sort(info);
}

void	three_sort(t_info *info)
{
	int	t;
	int	m;
	int	b;

	t = info->a_top->num;
	m = info->a_top->next->num;
	b = info->a_top->next->next->num;
	if (t < m && t < b && m > b && m > t && b > t && b < m)
	{
		sa(info, "sa\n");
		ra(info, "ra\n");
	}
	if (t > m && t < b && m < t && m < b && b > t && b > m)
		sa(info, "sa\n");
	if (t < m && t > b && m > t && m > b && b < m && b < t)
		rra(info, "rra\n");
	if (t > m && t > b && m < t && m < b && b > m && b < t)
		ra(info, "ra\n");
	if (t > m && t > b && m < t && m > b && b < t && b < m)
	{
		sa(info, "sa\n");
		rra(info, "rra\n");
	}
}

void	four_sort(t_info *info)
{
	int		i;
	t_num	*tmp;

	i = 0;
	tmp = info->a_top;
	while (tmp != NULL)
	{
		if (tmp->num == 0)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i < info->a_size / 2)
	{
		while (info->a_top->num != 0)
			ra(info, "ra\n");
	}
	else
	{
		while (info->a_top->num != 0)
			rra(info, "rra\n");
	}
	pb(info, "pb\n");
	three_sort(info);
	pa(info, "pa\n");
}

void	if_case_two(t_info *info, int ab, int sort)
{
	if (sort == 1)
	{
		if (info->b_top->num > info->b_top->next->num)
		{
			if (ab == 0)
				sa(info, "sa\n");
			else if (ab == 1)
				sb(info, "sb\n");
		}
	}
	else
	{
		if (info->b_top->num < info->b_top->next->num)
		{
			if (ab == 0)
				sa(info, "sa\n");
			else if (ab == 1)
				sb(info, "sb\n");
		}
	}
}

void	five_sort(t_info *info)
{
	while (info->a_size > 3)
	{
		if (info->a_top->num == 0)
			pb(info, "pb\n");
		else if (info->a_top->num == 1)
			pb(info, "pb\n");
		else
			ra(info, "ra\n");
	}
	sb(info, "sb\n");
	if (info->a_top->num > info->a_top->next->num)
	{
		if (info->b_top->num > info->b_top->next->num)
		{
			sa(info, "sa\n");
		}
		else
		{
			sb(info, "sb\n");
		}
	}
	three_sort(info);
	pa(info, "pa\n");
	pa(info, "pa\n");
}
