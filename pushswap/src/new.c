/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:50:08 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/17 16:54:13 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*newStack(void)
{
	t_num	*new_stack;

	new_stack = NULL;
	new_stack = (t_num *)malloc(sizeof(t_num));
	if (!new_stack)
		return (NULL);
	new_stack->next = NULL;
	new_stack->num = 0;
	return (new_stack);
}

t_num	*newNode(void)
{
    t_num	*new;

    new = (t_num *)malloc(sizeof(t_num));
	if (!new)
		return (NULL);
    new->next = NULL;
    new->num = 0;
	return (new);
}

t_info	*newInfo(void)
{
	t_info *new_info;

    new_info = (t_info *)malloc(sizeof(t_info));
	if (!new_info)
		return (NULL);
    new_info->a_head = NULL;
    new_info->a_top = NULL;
    new_info->a_bottom_num = 0;
    new_info->a_size = 0;
    new_info->b_head = NULL;
    new_info->b_top = NULL;
    new_info->b_bottom_num = 0;
    new_info->b_size = 0;
    new_info->array = NULL;
	return (new_info);
}
