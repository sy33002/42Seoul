/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputParsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:27:18 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/15 20:46:58 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    isInteger(char **av)
{
    int i;
    int j;

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

void    isSorted(int *nums, int size)
{
	int check;
	int i;

	check = 0;
	i = 0;
	while(i < size - 1)
	{
		if (nums[i] < nums[i + 1])
			check++;
		i++;
	}
	if (check == size - 1)
	{
		free(nums);
		exit(0);
	}
}

void	hasDuplicates(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while(i < size)
	{
		j = i + 1;
		while(i < size - 1)
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

int *inputParsing(char **av, int *arr_size, int *nums)
{
    int size;

	arr_size = NULL;
	size = arraySize(av); 
	printf("size : %d\n", size);
	nums = numArray(av, size);
	printf("nums : %d\n", nums[0]);
    isInteger(av);
	isSorted(nums, size);
	hasDuplicates(nums, size);
	return (nums);
}