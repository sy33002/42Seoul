/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:31:47 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/11/25 15:33:28 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	err_msg(char *error_msg)
{
	write(2, "Error\n", 6);
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
	exit(1);
}

void	free_table(char **table)
{
	int	i;

	i = 0;
	while (table[i])
		free(table[i++]);
	free(table);
}

void	err_free_exit(char *err, t_game_info *game)
{
	if (err)
	{
		write(2, "Error\n", 6);
		write(2, err, ft_strlen(err));
		write(2, "\n", 1);
	}
	free_table(game->str_line);
	if (err)
		exit(1);
	else
		exit(0);
}
