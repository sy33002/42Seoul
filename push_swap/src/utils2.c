/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:45:26 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/11/03 21:21:03 by jihyuki2         ###   ########.fr       */
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

int	ft_atoi2(const char *str)
{
	int				i;
	long long		res;
	int				minor;

	i = 0;
	res = 0;
	minor = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minor *= -1;
			i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (checkss(minor, res, str, i) == 1)
			error();
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (minor * res);
}
