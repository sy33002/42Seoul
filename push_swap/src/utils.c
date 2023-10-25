/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:31:45 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/24 12:58:03 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	string_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	array_to_astack(t_info *info, int *array, int size)
{
	t_num	*n_node;

	while (0 < size)
	{
		if (info->a_size == 0)
			info->a_head = new_node();
		info->a_size++;
		n_node = new_node();
		n_node->num = array[size - 1];
		n_node->next = info->a_head->next;
		info->a_head->next = n_node;
		info->a_top = n_node;
		size--;
	}
	info->b_head = new_node();
}

void	make_info_array(t_info *info, int *nums, int size)
{
	int	i;

	i = 0;
	info->array = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		info->array[i] = nums[i];
		i++;
	}
}

void	array_to_index(t_info *info, int *nums, int arr_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr_size)
	{
		j = 0;
		while (j < arr_size)
		{
			if (info->array[i] == nums[j])
			{
				info->array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}
