/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyuki2 <jihyuki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:30:51 by jihyuki2          #+#    #+#             */
/*   Updated: 2023/11/26 15:58:38 by jihyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define   SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include "./mlx/mlx.h"
# include "./src/gnl/get_next_line.h"

# define X_EVENT_KEY_PRESS		2
# define PIXEL                  63
# define KEY_W			        13
# define KEY_A			        0
# define KEY_S			        1
# define KEY_D			        2
# define KEY_ESC		        53
# define X_EVENT_KEY_EXIT		17

typedef struct s_image
{
	void	*img_player;
	void	*img_collectible;
	void	*img_wall;
	void	*img_exit;
	void	*img_floor;
}		t_images;

typedef struct s_game
{
	char		**str_line;
	int			num_row;
	int			num_col;
	int			collec;
	int			player;
	int			player_x;
	int			player_y;
	int			exit;
	int			player_move_cnt;
	void		*mlx;
	void		*win;
	t_images	img;
}		t_game_info;

void		err_msg(char *error_msg);
void		parsing(char *map, t_game_info *game);
void		valid_map(char *check_map);
void		check_param(t_game_info *game);
void		check_param_smth(t_game_info *game);
void		count_rows_in_file(char *map, t_game_info *game);
void		gnl_str(char *map, t_game_info *game);
void		err_free_exit(char *error_msg, t_game_info *game);
void		param_count(t_game_info *game);
void		check_wall_consistency(t_game_info *game);
void		check_wall_all(t_game_info *game);
void		put_img(t_game_info *g, int i, int j);
int			set_img(t_game_info *game);
void		move_key_w(t_game_info *game);
void		move_key_s(t_game_info *game);
void		move_key_a(t_game_info *game);
void		move_key_d(t_game_info *game);
void		print_map(char **line);
char		*ft_strdup2(const char *s1);
t_images	img_init(void *mlx);

#endif