/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:42:42 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/07/23 22:11:12 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;
	int		res;

	i = -1;
	len = 0;
	res = 0;
	va_start(arg, str);
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
			len = ft_printf_ver2(&arg, str[++i]);
		else
		{
			len = ft_putchar(str[i]);
			if (len == -1)
				return (-1);
		}
		res += len;
	}
	va_end(arg);
	return (res);
}
