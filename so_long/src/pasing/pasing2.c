/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:48:25 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/11/25 15:33:23 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_param_smth(t_game_info *game)
{
	if (game->player != 1)
		err_free_exit("player is not only one!", game);
	else if (game->exit != 1)
		err_free_exit("exit is not only one!", game);
	else if (game->collec < 1)
		err_free_exit("collection is not enough!", game);
}

void	param_count(t_game_info *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->str_line[i])
	{
		j = 0;
		while (game->str_line[i][j])
		{
			if (game->str_line[i][j] == 'P')
			{
				game->player++;
				game->player_x = j;
				game->player_y = i;
			}
			else if (game->str_line[i][j] == 'E')
				game->exit++;
			else if (game->str_line[i][j] == 'C')
				game->collec++;
			j++;
		}
		i++;
	}
	check_param_smth(game);
}

void	check_wall_consistency(t_game_info *game)
{
	int	i;

	i = 0;
	game->num_col = (unsigned int)ft_strlen(game->str_line[0]);
	while (game->str_line[i])
	{
		if (game->num_col != (int)ft_strlen(game->str_line[i++]))
			err_free_exit("wall is not consistent.", game);
	}
}

void	check_wall_all(t_game_info *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->str_line[i])
	{
		j = 0;
		while (game->str_line[i][j])
		{
			if (i == game->num_row - 1 || i == 0
				|| j == game->num_col - 1 || j == 0)
			{
				if (game->str_line[i][j] != '1')
					err_free_exit("wall is not consistent.", game);
			}
			j++;
		}
		i++;
	}
}
