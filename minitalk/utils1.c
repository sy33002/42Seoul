/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:25:03 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/08/27 17:25:41 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\0')
		i++;
	return (i);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	res;
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
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (minor * res);
}

void	post_error_msg(char *str)
{
	write(2, "Error : ", ft_strlen("Error : "));
	write(2, str, ft_strlen(str));
	write(2, "\n", ft_strlen("\n"));
	exit(1);
}
