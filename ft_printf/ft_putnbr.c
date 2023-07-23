/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:59:52 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/07/23 18:37:53 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long num)
{
	int	res;

	res = 0;
	if (num < 0)
	{
		ft_putchar('-');
		res += 1;
		res += ft_putnbr(-num);
	}
	else if (num > 9)
	{
		res += ft_putnbr(num / 10);
		res += ft_putnbr(num % 10);
	}
	else
	{
		res += ft_putchar(num + '0');
		if (res == -1)
			return (-1);
	}
	return (res);
}

int	ft_16len(unsigned long long n)
{
	int	res;

	res = 0;
	while (n)
	{
		n /= 16;
		res++;
	}
	return (res);
}

int	ft_putnbr16_small(unsigned long long num)
{
	int		res;
	char	*buf;

	res = 0;
	buf = "0123456789abcdef";
	if (num > 15)
	{
		res += ft_putnbr16_small(num / 16);
		res += ft_putnbr16_small(num % 16);
	}
	else
	{
		if (res == -1)
			return (-1);
		res += ft_putchar(buf[num]);
	}
	return (res);
}

int	ft_putnbr16_small_p(unsigned long long num)
{
	int		res;
	char	*buf;

	res = 0;
	buf = "0123456789abcdef";
	res += ft_putstr("0x");
	if (num == 0)
		res += ft_putchar('0');
	else
	{
		if (res == -1)
			return (-1);
		ft_putnbr16_small(num);
		res += ft_16len(num);
	}
	return (res);
}

int	ft_putnbr16_big(unsigned long long num)
{
	int		res;
	char	*buf;

	res = 0;
	buf = "0123456789ABCDEF";
	if (num > 15)
	{
		res += ft_putnbr16_big(num / 16);
		res += ft_putnbr16_big(num % 16);
	}
	else
	{
		res += ft_putchar(buf[num]);
		if (res == -1)
			return (-1);
	}
	return (res);
}
