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

#include "push_swap.h"

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
	printf("cnt : %d\n", cnt);
	printf("size : %d\n", size);
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
	while  (i < size)
	{
		j = i + 1;
		while (j < size - 1)
		{
			if (nums[i] == nums[j])
			{
				free(nums);
				errorMsg();
				return ;
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
	printf("1-0\n");
	*arr_size = arraySize(av);
	printf("arrsize: %d\n", *arr_size);
	printf("1-1\n");
	nums = numArray(av, size);
	for (int i = 0; i < size; i++){
		printf("nums[i] : %d\n", nums[i]);
	}
	printf("1-2\n");
	isSorted(nums, size);
	printf("1-3\n");
	hasDuplicates(nums, size);
	printf("1-4\n");
	return (nums);
}
