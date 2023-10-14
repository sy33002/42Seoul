/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:25:15 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/09/23 14:39:15 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/proc.h>

unsigned int	ft_strlen(char *str);
int				is_number(char *str);
int				ft_atoi(const char	*str);
void			ft_putchar(char c);
void			ft_putstr(char	*str);
void			ft_putnbr(int n);
void			check_bit(int bit, int pid);
void			post_bit(char ori_c, int pid);
void			post_msg(char *str, int pid);
void			show_msg(int signal);
void			post_error_msg(char	*str);
void			show_msg(int signal);

#endif