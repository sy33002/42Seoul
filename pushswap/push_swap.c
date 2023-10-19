/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:37:14 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/19 21:37:32 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stackFree(t_num **stack)
{
	t_num	*freeList;

	freeList = *stack;
	if (stack != NULL || *stack != NULL)
	{
		while (*stack)
		{
			*stack = freeList->next;
			free(freeList);
			freeList = *stack;
		}
	}
}

int main(int ac, char **av)
{
	t_info  *info;
	int		arr_size;
	int		*nums;

	nums = NULL;
	if (ac < 2)
		errorMsg();
	info = newInfo();
	printf("---------1\n");
	nums = inputParsing(av, &arr_size, nums);
	makeInfoArray(info, nums, arr_size);
	printf("---------2\n");
	bubbleSort(nums, arr_size);
	printf("---------3\n");
	arrayTo_Index(info, nums, arr_size);
	printf("---------4\n");
	arrayTo_Astack(info, info->array, arr_size);
	printf("---------5\n");
	free(nums);
	free(info->array);
	littleSort(info);
	printf("---------6\n");
	stackFree(&info->a_top);
	stackFree(&info->b_top);
	free(info->a_head);
	free(info->b_head);
	free(info);
	return (0);
}
