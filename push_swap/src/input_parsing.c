/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputParsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:27:18 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/24 12:55:38 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_int(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				j++;
			else if (av[i][j] == ' ' || av[i][j] == '-')
				j++;
			else
				error();
		}
		i++;
	}
}

void	is_sorted(int *nums, int size)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < size - 1)
	{
		if (nums[i] < nums[i + 1])
			cnt++;
		i++;
	}
	if (cnt + 1 == size)
	{
		free(nums);
		exit(1);
	}
}

void	has_duplicates(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	if (size == 2 && nums[0] == nums[1])
	{
		free(nums);
		error();
	}
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] == nums[j])
			{
				free(nums);
				error();
			}
			j++;
		}
		i++;
	}
}

int	*input_parsing(char **av, int *arr_size, int *nums)
{
	int	size;

	size = 0;
	validate_int(av);
	*arr_size = array_size(av);
	size = *arr_size;
	nums = av_to_nums(av, size);
	is_sorted(nums, size);
	has_duplicates(nums, size);
	return (nums);
}
