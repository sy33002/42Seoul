/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listAdd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:14:15 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/15 21:52:23 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	listAddBack(t_info *info, t_num **head, int AB, int value)
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
		while(current->next)
			current = current->next;
		current->next = new_node;
	}
	if (AB == 1)
		info->a_size++;
	else
		info->b_size++;
}

void listAddFrontA(t_info *info, t_num **a_head, int value)
{
	t_num	*new_node;

	new_node = (t_num *)malloc(sizeof(t_num));
	if (!new_node)
		return ;
	new_node->num = value;
	new_node->next = *a_head;
	*a_head = new_node;
	if (info->a_size == 0)
		info->a_top = new_node;
	info->a_size++;
}

void listAddFrontB(t_info *info, t_num *b_head, int value)
{
	t_num	*new_node;

	new_node = (t_num *)malloc(sizeof(t_num));
	if (!new_node)
		return ;
	new_node->num = value;
	new_node->next = *b_head;
	*b_head = new_node;
	if (info->b_size == 0)
		info->b_top = new_node;
	info->b_size++;
}