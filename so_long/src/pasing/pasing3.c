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
