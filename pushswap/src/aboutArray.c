/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aboutArray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:16:35 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/19 21:53:03 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isSpace(char *str)
{
	// int	i;

	// i = 0;
	// while (str[i])
	// {
	// 	if (str[i] == ' ')
	// 		return (1);
	// 	i++;
	// }
	// return (0);
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

unsigned int	splitSize(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	arraySize(char **av)
{
	char	**str;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (av[i])
	{
		if (isSpace(av[i]) == 1)
		{
			str = ft_split(av[i], ' ');
			len += splitSize(str);
			freeStr(str);
		}
		else{
			len++;
		}
		i++;
	}
	return (len - 1);
}

int *numArray(char **av, int size)
{
	char	**str;
	int		*nums;
	int		ac_len;
	int		i;
	int		j;

	i = 1;
	ac_len = 0;
	nums = (int *)malloc(sizeof(int) * size);
	if (!nums)
		return (NULL);
	while (av[i])
	{
		j = 0;
		str = ft_split(av[i], ' ');
		while (str[j])
		{
			nums[ac_len] = ft_atoi(str[j]);
			ac_len++;
			j++;
		}
		freeStr(str);
		i++;
	}
	return (nums);
}
