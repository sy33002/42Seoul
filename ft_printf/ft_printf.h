/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:49:27 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/07/23 18:34:03 by jihyuki2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_printf_ver2(va_list *arg, char a);
int	ft_putchar(char a);
int	ft_putnbr(long num);
int	ft_putnbr16_small(unsigned long long num);
int	ft_putnbr16_small_p(unsigned long long num);
int	ft_putnbr16_big(unsigned long long num);
int	ft_putstr(char *str);

#endif