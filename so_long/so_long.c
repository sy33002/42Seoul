/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:30:31 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/12/02 14:18:23 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game_info *game)
{
	game->player = 0;
	game->collec = 0;
	game->exit = 0;
	game->num_col = 0;
	game->num_row = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player_move_cnt = 0;
	game->img.img_player = NULL;
	game->img.img_collectible = NULL;
	game->img.img_back = NULL;
	game->img.img_exit = NULL;
	game->img.img_wall = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->str_line = NULL;
}

char	*ft_strdup2(const char *s1)
{
	char	*tmp;
	int		i;
	int		l;

	tmp = NULL;
	i = 0;
	l = ft_strlen(s1) + 1;
	tmp = (char *)ft_calloc(l, 1);
	if (!tmp)
		return (NULL);
	l--;
	while (i < l)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	key_press(int key, t_game_info *game)
{
	if (key == KEY_ESC)
		err_free_exit(NULL, game);
	else if (key == KEY_W)
		move_key_w(game);
	else if (key == KEY_S)
		move_key_s(game);
	else if (key == KEY_A)
		move_key_a(game);
	else if (key == KEY_D)
		move_key_d(game);
	return (0);
}

int	red_btn(t_game_info *game)
{
	err_free_exit(NULL, game);
	return (1);
}

int	main(int ac, char **av)
{
	t_game_info	game;

	if (ac == 2)
	{
		game_init(&game);
		parsing(av[1], &game);
		game.mlx = mlx_init();
		game.win = mlx_new_window
			(game.mlx, game.num_col * PIXEL, game.num_row * PIXEL, "[so_long]");
		game.img = img_init(game.mlx);
		ft_printf("move cnt = %d\n", game.player_move_cnt);
		mlx_hook(game.win, EVENT_KEY_PRESS, 0, &key_press, &game);
		mlx_hook(game.win, EVENT_KEY_EXIT, 0, &red_btn, &game);
		mlx_loop_hook(game.mlx, &set_img, &game);
		mlx_loop(game.mlx);
	}
	else
		err_msg("ac is not two!");
	return (0);
}
