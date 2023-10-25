/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listRemove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:50:18 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/24 12:51:02 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_remove_front_a(t_info *info)
{
	t_num	*tmp;

	if (info->a_size == 0)
		return ;
	tmp = info->a_top->next;
	info->a_head->next = tmp;
	free(info->a_top);
	info->a_top = tmp;
	info->a_size--;
}

void	list_remove_front_b(t_info *info)
{
	t_num	*tmp;

	if (info->b_size == 0)
		return ;
	tmp = info->b_top->next;
	info->b_head->next = tmp;
	free(info->b_top);
	info->b_top = tmp;
	info->b_size--;
}

void	list_remove_back_a(t_info *info)
{
	t_num	*current;

	if (info->a_head == NULL)
		return ;
	if (info->a_head->next == NULL)
	{
		info->a_head = NULL;
		info->a_top = NULL;
		free(info->a_head);
		info->a_size--;
		return ;
	}
	current = info->a_head;
	while (current->next->next)
		current = current->next;
	free(current->next);
	current->next = NULL;
	info->a_size--;
}

void	list_remove_back_b(t_info *info)
{
	t_num	*current;

	if (info->b_head == NULL)
		return ;
	if (info->b_head->next == NULL)
	{
		info->b_head = NULL;
		info->b_top = NULL;
		free(info->b_head);
		info->b_size--;
		return ;
	}
	current = info->b_head;
	while (current->next->next)
		current = current->next;
	free(current->next);
	current->next = NULL;
	info->b_size--;
}
