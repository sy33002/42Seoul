/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:08:38 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/11/03 21:25:03 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_all_space(char **av)
{
	int	i;
	int	cnt;
	int	cnt2;

	i = 0;
	cnt = 0;
	cnt2 = 0;
	while (av[1][i])
	{
		i++;
		cnt++;
	}
	i = 0;
	while (av[1][i])
	{
		if ((av[1][i] >= 9 && av[1][i] <= 13) || av[1][i] == 32)
			cnt2++;
		i++;
	}
	if (cnt == cnt2)
		error();
}

int	checkss(int minor, long long res, const char *str, int i)
{
	int	chk;

	chk = 214748364;
	if (minor == 1 && (res > chk || (res == chk && (str[i] - '0') > 7)))
		return (1);
	else if (minor == -1 && (res > chk || (res == chk && (str[i] - '0') > 8)))
		return (1);
	return (0);
}
