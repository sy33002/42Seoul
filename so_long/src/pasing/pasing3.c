/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:14:19 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/11/28 13:53:54 by jihyuki2         ###   ########.fr       */
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


void	get_info(t_game_info *game, int	*info)
{
	if (info != NULL)
	{
		info[0] = game->collec;
		info[1] = game->exit;
	}
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