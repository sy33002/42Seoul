/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:52:50 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/07/23 22:04:30 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char a)
{
	int	res;

	res = 0;
	res = write(1, &a, 1);
	if (res == -1)
		return (-1);
	return (res);
}

int	ft_putstr(char *str)
{
	int	i;
	int	res;
	int	len;

	i = 0;
	res = 0;
	len = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		len = ft_putchar(str[i++]);
		res += len;
		if (len == -1)
			return (-1);
	}
	return (res);
}
