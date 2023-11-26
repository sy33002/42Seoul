/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:48:05 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/11/26 16:03:51 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	valid_map(char *check_map)
{
	char	*check_ext;
	int		len;

	len = ft_strlen(check_map) - 3;
	check_ext = check_map + len;
	if (ft_strncmp(check_ext, "ber", 3) != 0)
	{
		err_msg("It is not a valid map extension!");
		exit(1);
	}
}

void	count_rows_in_file(char *map, t_game_info *game)
{
	int		fd;
	char	*read_line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		err_msg("File fd error!");
	read_line = get_next_line(fd);
	while (read_line != NULL)
	{
		game->num_row++;
		free(read_line);
		read_line = get_next_line(fd);
	}
	close(fd);
	if (game->num_row < 3)
		err_msg("map doesn't have a valid number of lines.");
}

void	gnl_str(char *map, t_game_info *game)
{
	int		i;
	int		fd;
	char	*line;

	count_rows_in_file(map, game);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		err_msg("file can't open");
	line = get_next_line(fd);
	game->str_line = (char **)malloc(sizeof(char *) * (game->num_row + 1));
	if (!(game->str_line))
		return ;
	i = 0;
	while (line)
	{
		game->str_line[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	game->str_line[i] = NULL;
	close(fd);
}

void	check_param(t_game_info *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;

	while (game->str_line[i])
	{
		j = 0;
		while (game->str_line[i][j])
		{
			c = game->str_line[i][j];
			if (!(c == 'P' || c == '0' || c == '1' || c == 'C' || c == 'E' ))
				err_free_exit("param error", game);
			j++;
		}
		i++;
	}
}


// check_invalid_dfs()

void	parsing(char *map, t_game_info *game)
{
	valid_map(map);
	gnl_str(map, game);
	// check_invalid_dfs(map,game);
	check_param(game);
	param_count(game);
	check_wall_consistency(game);
	check_wall_all(game);
}
