/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigSort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:10:21 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/26 16:36:03 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bigger_sort(t_info *info)
{
	double	chunk;

	chunk = 0.00000053 * info->a_size
		* info->a_size + 0.03 * info->a_size + 14.5;
	move_a_to_b(info, chunk);
	while (info->b_size != 0)
	{
		find_max_top(info);
		pa(info, "pa\n");
	}
}

void	find_max_top(t_info *info)
{
	t_num	*node;
	int		max;
	int		c;

	c = 0;
	max = info->b_size - 1;
	node = info->b_top;
	while (node != NULL)
	{
		if (node->num == max)
			rotate_to_max(info, &c);
		c++;
		node = node->next;
	}
}

void	rotate_to_max(t_info *info, int *c)
{
	if ((int)(info->b_size / 2) < *c)
	{
		while (*c < info->b_size)
		{
			rrb(info, "rrb\n");
			(*c)++;
		}
		return ;
	}
	else
	{
		while (*c > 0)
		{
			rb(info, "rb\n");
			(*c)--;
		}
		return ;
	}
}

void	move_a_to_b(t_info *info, int chunk)
{
	int	i;

	i = 0;
	while (info->a_size != 0)
	{
		if (info->a_top->num <= i)
		{
			pb(info, "pb\n");
			i++;
		}
		else if (info->a_top->num > i && info->a_top->num <= i + chunk)
		{
			pb(info, "pb\n");
			rb(info, "rb\n");
			i++;
		}
		else if (info->a_top->num > (i + chunk))
		{
			if (i < info->a_size / 2 && i >= 0)
				rra(info, "rra\n");
			else
				ra(info, "ra\n");
		}
	}
}
