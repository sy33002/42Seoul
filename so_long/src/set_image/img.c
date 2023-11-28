/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:49:00 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/11/28 16:57:18 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_images	img_init(void *mlx)
{
	t_images		setting;
	int				w;
	int				h;

	setting.img_collectible
		= mlx_xpm_file_to_image(mlx, "./src/img/col.xpm", &w, &h);
	setting.img_wall
		= mlx_xpm_file_to_image(mlx, "./src/img/wall.xpm", &w, &h);
	setting.img_exit
		= mlx_xpm_file_to_image(mlx, "./src/img/exit.xpm", &w, &h);
	setting.img_back
		= mlx_xpm_file_to_image(mlx, "./src/img/back.xpm", &w, &h);
	setting.img_player
		= mlx_xpm_file_to_image(mlx, "./src/img/player.xpm", &w, &h);
	return (setting);
}

void	put_img(t_game_info *g, int i, int j)
{
	if (g->str_line[i][j] == 'P')
		mlx_put_image_to_window
			(g->mlx, g->win, g->img.img_player, j * PIXEL, i * PIXEL);
	else if (g->str_line[i][j] == '0')
		mlx_put_image_to_window
			(g->mlx, g->win, g->img.img_back, j * PIXEL, i * PIXEL);
	else if (g->str_line[i][j] == '1')
		mlx_put_image_to_window
			(g->mlx, g->win, g->img.img_wall, j * PIXEL, i * PIXEL);
	else if (g->str_line[i][j] == 'C')
		mlx_put_image_to_window
			(g->mlx, g->win, g->img.img_collectible, j * PIXEL, i * PIXEL);
	else if (g->str_line[i][j] == 'E')
		mlx_put_image_to_window
			(g->mlx, g->win, g->img.img_exit, j * PIXEL, i * PIXEL);
}

int	set_img(t_game_info *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->num_row)
	{
		j = 0;
		while (j < game->num_col)
		{
			put_img(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
