/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:45:26 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/25 22:34:14 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	bubble_sort(int *arr, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	stack_free(t_num **stack)
{
	t_num	*free_list;

	free_list = *stack;
	if (stack != NULL || *stack != NULL)
	{
		while (*stack)
		{
			*stack = free_list->next;
			free(free_list);
			free_list = *stack;
		}
	}
}

int	find_index(t_info *info, int find)
{
	int		i;

	i = 0;
	while (info->a_top != NULL)
	{
		if (info->a_top->num == find)
			return (i);
		info->a_top = info->a_top->next;
		i++;
	}
	return (i);
}
