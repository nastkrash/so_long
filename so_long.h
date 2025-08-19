/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakrash <anakrash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:28:05 by anakrash          #+#    #+#             */
/*   Updated: 2024/12/21 19:05:16 by anakrash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "get_next_line.h"
# include "assets/libft/libft.h"
# include "assets/mini-libx/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define TILE_SIZE 32
# define ERR_FORMAT "Error: format must be .so_long <map_file>\n"
# define ERR_PATH "Error: no valid path in map\n"

typedef struct s_image
{
	void		*img;
	int			width;
	int			height;
}				t_image;

typedef struct s_assets
{
	t_image		wall;
	t_image		player;
	t_image		collectible;
	t_image		exit;
	t_image		background;
}				t_assets;

typedef struct s_grid
{
	char		**grid;
	int			width;
	int			height;
	int			collectibles_count;
	int			player_x;
	int			player_y;
}				t_grid;

typedef struct s_map
{
	t_grid		grid;
	t_assets	assets;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map		map;
	int			moves_count;
}				t_game;

bool			find_exit(t_grid grid);
void			free_grid(t_grid *grid);
bool			flood_fill_init(t_grid grid);
void			flood_fill(int x, int y, t_grid *copy);
bool			is_rectangular(t_grid grid);
bool			has_valid_characters(t_grid grid);
bool			has_single_player_and_exit(t_grid grid);
bool			is_surrounded_by_walls(t_grid grid);
bool			is_map_valid(t_grid grid);
void			update_player_position(t_game *game, int player_x, int player_y,
					int new_x, int new_y);
int				go_to_exit(t_game *game);
int				key_handler(int key_code, t_game *game);
void			set_player_position(t_grid *grid);
void			count_collectibles(t_grid *grid);
int				read_map(char *filename, t_grid *grid);
void			load_images(t_game *game);
void			render_map(t_game *game);
void			start_game(t_game *game);
int				game_exit(t_game *game);

#endif