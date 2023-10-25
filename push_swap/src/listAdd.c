/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listAdd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:14:15 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/24 12:50:51 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_add_front_a(t_info *info, int value)
{
	t_num	*node;

	node = new_node();
	if (info->a_size == 0)
	{
		info->a_top = node;
		info->a_head->next = info->a_top;
		info->a_top->num = value;
	}
	else
	{
		node->next = info->a_top;
		info->a_head->next = node;
		node->num = value;
		info->a_top = node;
	}
	info->a_size++;
}

void	list_add_front_b(t_info *info, int value)
{
	t_num	*node;

	node = new_node();
	if (info->b_size == 0)
	{
		info->b_top = node;
		info->b_head->next = info->b_top;
		info->b_top->num = value;
	}
	else
	{
		node->next = info->b_top;
		info->b_head->next = node;
		node->num = value;
		info->b_top = node;
	}
	info->b_size++;
}

void	list_add_back_a(t_info *info, t_num **head, int value)
{
	t_num	*new_node;
	t_num	*current;

	new_node = (t_num *)malloc(sizeof(t_num));
	if (!new_node)
		return ;
	new_node->num = value;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
		info->a_size++;
}

void	list_add_back_b(t_info *info, t_num **head, int value)
{
	t_num	*new_node;
	t_num	*current;

	new_node = (t_num *)malloc(sizeof(t_num));
	if (!new_node)
		return ;
	new_node->num = value;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
		info->b_size++;
}
