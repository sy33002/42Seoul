/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:47:13 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/11/28 17:40:10 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_to_floor(t_game_info *game, int x_move, int y_move)
{
	char	tmp;

	tmp = '\0';
	ft_printf("move cnt = %d\n", ++game->player_move_cnt);
	tmp = game->str_line[game->player_y][game->player_x];
	game->str_line[game->player_y][game->player_x]
		= game->str_line[game->player_y + y_move][game->player_x + x_move];
	game->str_line[game->player_y + y_move][game->player_x + x_move] = tmp;
	game->player_y += y_move;
	game->player_x += x_move;
}

void	move_key_w(t_game_info *game)
{
	char	move;

	move = game->str_line[game->player_y - 1][game->player_x];
	if (move == '0')
		move_to_floor(game, 0, -1);
	else if (move == 'C')
	{
		ft_printf("move cnt = %d\n", ++game->player_move_cnt);
		game->collec--;
		game->str_line[game->player_y - 1][game->player_x] = 'P';
		game->str_line[game->player_y][game->player_x] = '0';
		game->player_y -= 1;
	}
	else if (move == 'E' && game->collec == 0)
	{
		ft_printf("move cnt = %d\n", ++game->player_move_cnt);
		err_free_exit(NULL, game);
	}
}

void	move_key_s(t_game_info *game)
{
	char	move;

	move = game->str_line[game->player_y +1][game->player_x];
	if (move == '0')
		move_to_floor(game, 0, +1);
	else if (move == 'C')
	{
		ft_printf("move cnt = %d\n", ++game->player_move_cnt);
		game->collec--;
		game->str_line[game->player_y + 1][game->player_x] = 'P';
		game->str_line[game->player_y][game->player_x] = '0';
		game->player_y += 1;
	}
	else if (move == 'E' && game->collec == 0)
	{
		ft_printf("move cnt = %d\n", ++game->player_move_cnt);
		err_free_exit(NULL, game);
	}
}

void	move_key_a(t_game_info *game)
{
	char	move;

	move = game->str_line[game->player_y][game->player_x - 1];
	if (move == '0')
		move_to_floor(game, -1, 0);
	else if (move == 'C')
	{
		ft_printf("move cnt = %d\n", ++game->player_move_cnt);
		game->collec--;
		game->str_line[game->player_y][game->player_x - 1] = 'P';
		game->str_line[game->player_y][game->player_x] = '0';
		game->player_x -= 1;
	}
	else if (move == 'E' && game->collec == 0)
	{
		ft_printf("move cnt = %d\n", ++game->player_move_cnt);
		err_free_exit(NULL, game);
	}
}

void	move_key_d(t_game_info *game)
{
	char	move;

	move = game->str_line[game->player_y][game->player_x + 1];
	if (move == '0')
		move_to_floor(game, +1, 0);
	else if (move == 'C')
	{
		ft_printf("move cnt = %d\n", ++game->player_move_cnt);
		game->collec--;
		game->str_line[game->player_y][game->player_x + 1] = 'P';
		game->str_line[game->player_y][game->player_x] = '0';
		game->player_x += 1;
	}
	else if (move == 'E' && game->collec == 0)
	{
		ft_printf("move cnt = %d\n", ++game->player_move_cnt);
		err_free_exit(NULL, game);
	}
}
