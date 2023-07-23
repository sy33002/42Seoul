/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:42:42 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/07/23 18:38:17 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_start(int *i, int *count)
{
	*i = -1;
	*count = 0;
}

int	ft_check_str(const char *str)
{
	if (!str)
		return (-1);
	return (0);
}

int	ft_check_len(int len)
{
	if (len == -1)
		return (-1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;
	int		res;

	i = 0;
	len = 0;
	res = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			len = ft_printf_ver2(&arg, str[i]);
		}
		else
			len = ft_putchar(str[i]);
		i++;
		res += len;
	}
	va_end(arg);
	return (res);
}
