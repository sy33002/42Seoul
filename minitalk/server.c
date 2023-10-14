/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:40:38 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/09/23 14:40:51 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	show_msg(int signal)
{
	static char	s_char;
	static int	s_cnt;

	s_char = s_char << 1;
	s_cnt++;
	if (signal == SIGUSR1)
		s_char += 1;
	if (s_cnt == 8)
	{
		ft_putchar(s_char);
		s_cnt = 0;
		s_char = 0;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	(void) av;
	if (ac == 1)
	{
		ft_putstr("Process Id : ");
		pid = getpid();
		ft_putnbr(pid);
		ft_putstr("\nmessage : ");
		if (signal(SIGUSR1, show_msg) == SIG_ERR)
			post_error_msg("argc num Error!\n");
		if (signal(SIGUSR2, show_msg) == SIG_ERR)
			post_error_msg("argc num Error!\n");
		while (1)
			pause();
	}
	else
		post_error_msg("argc Error!!!\n");
	return (0);
}
