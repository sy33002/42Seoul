/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ver2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:24:44 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/07/23 18:34:18 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ver2(va_list *arg, char a)
{
	int	res;

	res = 0;
	if (a == 'c')
		res = ft_putchar((char)(va_arg(*arg, int)));
	else if (a == 's')
		res = ft_putstr(va_arg(*arg, char *));
	else if (a == 'p')
		res = ft_putnbr16_small_p(va_arg(*arg, unsigned long long));
	else if (a == 'd' || a == 'i')
		res = ft_putnbr(va_arg(*arg, int));
	else if (a == 'u')
		res = ft_putnbr(va_arg(*arg, unsigned int));
	else if (a == 'x')
		res = ft_putnbr16_small(va_arg(*arg, unsigned int));
	else if (a == 'X')
		res = ft_putnbr16_big(va_arg(*arg, unsigned int));
	else if (a == '%')
	{
		write(1, "%", 1);
		res = 1;
	}
	return (res);
}
