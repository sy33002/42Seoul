/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:24:24 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/09/23 14:44:30 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_bit(int bit, int pid)
{
	if ((1 & bit) == 1)
	{
		if (kill(pid, SIGUSR1) == 1)
		{
			ft_putstr("sig1 kill error");
			exit(1);
		}
	}
	else if ((1 & bit) == 0)
	{
		if (kill(pid, SIGUSR2) == 1)
		{
			ft_putstr("sig2 kill error");
			exit(1);
		}
	}
}

void	post_bit(char ori_c, int pid)
{
	int		cnt;
	char	bit;

	cnt = 8;
	while (cnt--)
	{
		bit = ori_c >> cnt;
		check_bit(bit, pid);
		usleep(80);
	}
}

void	post_msg(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		post_bit(str[i], pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3 && is_number(av[1]) == 1)
		post_msg(av[2], ft_atoi(av[1]));
	else
		post_error_msg("argc Error!!\n");
	return (0);
}
