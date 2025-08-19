/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakrash <anakrash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:54:18 by anakrash          #+#    #+#             */
/*   Updated: 2024/12/21 18:10:58 by anakrash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_pos(t_game *game, int new_x, int new_y)
{
	int	player_x;
	int	player_y;

	player_x = game->map.grid.player_x;
	player_y = game->map.grid.player_y;
	game->map.grid.grid[player_y][player_x] = '0';
	game->map.grid.grid[new_y][new_x] = 'P';
	game->moves_count++;
	game->map.grid.player_x = new_x;
	game->map.grid.player_y = new_y;
	ft_putstr_fd("Current number of movements: ", 1);
	ft_putnbr_fd(game->moves_count, 1);
	ft_putstr_fd("\n", 1);
	render_map(game);
}

int	go_to_exit(t_game *game)
{
	game->moves_count++;
	ft_putstr_fd("Current number of movements: ", 1);
	ft_putnbr_fd(game->moves_count, 1);
	ft_putstr_fd("\n", 1);
	game_exit(game);
	return (0);
}

int	key_handler(int key_code, t_game *game)
{
	t_grid	grid;
	int		new[2];

	grid = game->map.grid;
	new[0] = grid.player_x;
	new[1] = grid.player_y;
	if (key_code == 119 || key_code == 115 || key_code == 97 || key_code == 100)
	{
		if (key_code == 119)
			new[1] = grid.player_y - 1;
		else if (key_code == 115)
			new[1] = grid.player_y + 1;
		else if (key_code == 97)
			new[0] = grid.player_x - 1;
		else if (key_code == 100)
			new[0] = grid.player_x + 1;
		if (grid.grid[new[1]][new[0]] != 'E' && grid.grid[new[1]][new[0]] != 49)
			update_player_pos(game, new[0], new[1]);
		count_collectibles(&game->map.grid);
		if (grid.grid[new[1]][new[0]] == 'E' && grid.collectibles_count == 0)
			go_to_exit(game);
	}
	else if (key_code == 65307)
		game_exit(game);
	return (0);
}
