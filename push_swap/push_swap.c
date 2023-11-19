/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:37:14 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/11/03 21:05:54 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_info	*info;
	int		arr_size;
	int		*nums;

	nums = NULL;
	if (ac < 2)
		exit(1);
	check_all_space(av);
	info = new_info();
	nums = input_parsing(av, &arr_size, nums);
	make_info_array(info, nums, arr_size);
	bubble_sort(nums, arr_size);
	array_to_index(info, nums, arr_size);
	array_to_astack(info, info->array, arr_size);
	free(nums);
	free(info->array);
	little_sort(info);
	stack_free(&info->a_top);
	stack_free(&info->b_top);
	free(info->a_head);
	free(info->b_head);
	free(info);
	return (0);
}
