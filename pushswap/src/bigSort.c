/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigSort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:10:21 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/19 19:27:01 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bigSort(t_info *info)
{
	int chunk;

	chunk = 0.00000053 * info->a_size
		* info->a_size + 0.03 * info->a_size + 14.5;
	a_to_b(info,chunk);
	b_to_a(info);
}

void	max_top_utils(t_info *info, int *i)
{
	if ((int)(info->b_size / 2) < *i)
	{
		while (*i < info->b_size)
		{
			rrb(info);
			(*i)++;
		}
		return ;
	}
	else
	{
		while (*i > 0)
		{
			rb(info);
			(*i)--;
		}
		return ;
	}
}

void	max_top(t_info *info)
{
	t_num	*node;
	int		max;
	int		i;

	i = 0;
	max = info->b_size - 1;
	node = info->b_top;
	while (node != NULL)
	{
		if (node->num == max)
		{
			max_top_utils(info, &i);
		}
		node = node->next;
		i++;
	}
}

void	a_to_b(t_info *info, int chunk)
{
	int	i;

	i = 0;
	while (info->a_size != 0)
	{
		if (info->a_top->num <= i)
		{
			pb(info);
			i++;
		}
		else if (info->a_top->num > i && info->a_top->num <= i + chunk)
		{
			pb(info);
			rb(info);
			i++;
		}
		else if (info->a_top->num > (i + chunk))
		{
			if (i < info->a_size / 2 && i >= 0)
				rra(info);
			else
				ra(info);
		}
	}
}

void	b_to_a(t_info *info)
{
	while (info->b_size != 0)
	{
		max_top(info);
		pa(info);
	}
}
