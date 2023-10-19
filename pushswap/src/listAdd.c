/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listAdd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:14:15 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/19 19:46:06 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	listAddFrontA(t_info *info, int value)
{
	t_num	*new_node;

	new_node = newNode();
	if (info->a_size == 0)
	{
		info->a_top = newNode();
		info->a_head->next = info->a_top;
		info->a_top->num = value;
	}
	else
	{
		new_node->next = info->a_top;
		info->a_head->next = new_node;
		new_node->num = value;
		info->a_top = new_node;
	}
	info->a_size++;
}

void	listAddFrontB(t_info *info, int value)
{
	t_num *new_node;
	
	new_node = newNode();
	if (info->b_size == 0)
	{
		info->b_top = newNode();
		info->b_head->next = info->b_top;
		info->b_top->num = value;
	}
	else
	{
		new_node->next = info->b_top;
		info->b_head->next = new_node;
		new_node->num = value;
		info->b_top = new_node;
	}
	info->b_size++;
}

void	listAddBackA(t_info *info, t_num **head, int value)
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

void	listAddBackB(t_info *info, t_num **head, int value)
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

