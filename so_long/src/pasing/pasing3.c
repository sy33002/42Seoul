/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:14:19 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/12/02 13:28:43 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	get_tmp_str_line(t_game_info *game, char **tmp_str_line)
{
	int	i;

	i = 0;
	while (game->str_line[i])
	{
		tmp_str_line[i] = ft_strdup(game->str_line[i]);
		i++;
	}
	tmp_str_line[i] = NULL;
}

int	check_path2(char **map, int x, int y, int *info)
{
	if (map[y][x] != '1' && map[y][x] != 'E')
	{
		if (map[y][x] == 'C')
			info[0]--;
		if (map[y][x] == 'E')
			info[1]--;
		map[y][x] = '1';
		if (map[y][x + 1] != '1' && map[y][x + 1] != 'E')
			check_path2(map, x + 1, y, info);
		if (map[y][x - 1] != '1' && map[y][x - 1] != 'E')
			check_path2(map, x - 1, y, info);
		if (map[y - 1][x] != '1' && map[y - 1][x] != 'E')
			check_path2(map, x, y - 1, info);
		if (map[y + 1][x] != '1' && map[y + 1][x] != 'E')
			check_path2(map, x, y + 1, info);
	}
	if (info[0] == 0)
		return (1);
	return (0);
}

void	get_info_check_path(char **map, int x, int y, t_game_info *game)
{
	int	*info;
	int	chk;

	info = malloc(2 * sizeof(int));
	if (info != NULL)
	{
		info[0] = game->collec;
		info[1] = game->exit;
	}
	chk = check_path(map, x, y, info);
	free(info);
	if (chk == 0)
		err_free_exit("this map is not valid!!!", game);
}

void	get_info_check_path2(char **map, int x, int y, t_game_info *game)
{
	int	*info;
	int	chk;

	info = malloc(2 * sizeof(int));
	if (info != NULL)
	{
		info[0] = game->collec;
		info[1] = game->exit;
	}
	chk = check_path2(map, x, y, info);
	free(info);
	if (chk == 0)
		err_free_exit("this map is not valid!!!", game);
}
