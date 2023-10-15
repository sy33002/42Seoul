/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listRemove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:50:18 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/15 22:09:54 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void listRemoveFrontA(t_info *info, t_num **a_head)
{
    t_num *removed_node;

    if (info->a_size == 0)
        return ;
    removed_node = *a_head;
    *a_head = (*a_head)->next;
    free(removed_node);

    if (*a_head == NULL)
    {
        info->a_top = NULL;
    }
    info->a_size--;
}

void listRemoveFrontB(t_info *info, t_num **b_head)
{
    t_num *removed_node;

    if (info->b_size == 0)
        return ;
    removed_node = *b_head;
    *b_head = (*b_head)->next;
    free(removed_node);

    if (*b_head == NULL)
        info->b_top = NULL;
    info->b_size--;
}

void listRemoveBackA(t_info *info, t_num **a_head)
{
    t_num   *current;

    if(*a_head == NULL)
        return ;
    if ((*a_head)->next == NULL)
    {
        free(*a_head);
        *a_head = NULL;
        info->a_top = NULL;
        info->a_size--;
        return ;
    }
    current = *a_head;
    while(current->next->next != NULL)
        current = current->next;
    free(current->next);
    current->next = NULL;
    info->a_size--;
}

void listRemoveBackB(t_info *info, t_num **b_head)
{
    t_num   *current;

    if(*b_head == NULL)
        return ;
    if ((*b_head)->next == NULL)
    {
        free(*b_head);
        *b_head = NULL;
        info->b_top = NULL;
        info->b_size--;
        return ;
    }
    current = *b_head;
    while(current->next->next != NULL)
        current = current->next;
    free(current->next);
    current->next = NULL;
    info->b_size--;
}
