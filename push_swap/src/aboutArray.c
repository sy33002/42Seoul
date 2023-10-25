/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aboutArray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:16:35 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/10/24 12:49:40 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	contain_space(char *str)
{
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

int	count_size(char **str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

int	array_size(char **av)
{
	char	**str;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (av[i])
	{
		if (contain_space(av[i]) == 1)
		{
			str = ft_split(av[i], ' ');
			len += count_size(str);
			string_free(str);
		}
		else
			len++;
		i++;
	}
	return (len - 1);
}

int	*av_to_nums(char **av, int size)
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
		string_free(str);
		i++;
	}
	return (nums);
}
