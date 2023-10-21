/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputParsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:27:18 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/19 21:51:33 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	isInteger(char **av)
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
				errorMsg();
		}
		i++;
	}
}

void	isSorted(int *nums, int size)
{
	int i;
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

void	hasDuplicates(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	if (size == 2 && nums[0] == nums[1])
	{
		free(nums);
		errorMsg();
	}
	while  (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] == nums[j])
			{
				free(nums);
				errorMsg();
			}
			j++;
		}
		i++;
	}
}

int	*	inputParsing(char **av, int *arr_size, int *nums)
{
	int size;

	size = 0;
	isInteger(av);
	*arr_size = arraySize(av);
	size = *arr_size;
	nums = numArray(av, size);
	isSorted(nums, size);
	hasDuplicates(nums, size);
	return (nums);
}
