/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:49:27 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/12/02 12:53:52 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_printf_ver2(va_list *arg, char a);
int	ft_putchar(char a);
int	ft_putnbr(long num);
int	ft_putnbr16_small(unsigned long long num);
int	ft_putnbr16_small_p(unsigned long long num);
int	ft_putnbr16_big(unsigned long long num);
int	ft_putstr(char *str);

#endif