/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakrash <anakrash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:12:48 by anakrash          #+#    #+#             */
/*   Updated: 2024/12/21 19:05:49 by anakrash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	game->map.assets.background.img = mlx_xpm_file_to_image(game->mlx,
			"assets/images/background.xpm", &game->map.assets.background.width,
			&game->map.assets.background.height);
	game->map.assets.collectible.img = mlx_xpm_file_to_image(game->mlx,
			"assets/images/collectible.xpm",
			&game->map.assets.collectible.width,
			&game->map.assets.collectible.height);
	game->map.assets.wall.img = mlx_xpm_file_to_image(game->mlx,
			"assets/images/wall.xpm", &game->map.assets.wall.width,
			&game->map.assets.wall.height);
	game->map.assets.player.img = mlx_xpm_file_to_image(game->mlx,
			"assets/images/player.xpm", &game->map.assets.player.width,
			&game->map.assets.player.height);
	game->map.assets.exit.img = mlx_xpm_file_to_image(game->mlx,
			"assets/images/exit.xpm", &game->map.assets.exit.width,
			&game->map.assets.exit.height);
}

void	render_map(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	y = -1;
	while (++y < game->map.grid.height)
	{
		x = -1;
		while (++x < game->map.grid.width)
		{
			if (game->map.grid.grid[y][x] == '0')
				img = game->map.assets.background.img;
			if (game->map.grid.grid[y][x] == 'C')
				img = game->map.assets.collectible.img;
			if (game->map.grid.grid[y][x] == '1')
				img = game->map.assets.wall.img;
			if (game->map.grid.grid[y][x] == 'P')
				img = game->map.assets.player.img;
			if (game->map.grid.grid[y][x] == 'E')
				img = game->map.assets.exit.img;
			mlx_put_image_to_window(game->mlx, game->window, img, x * TILE_SIZE,
				y * TILE_SIZE);
		}
	}
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map.grid.width * TILE_SIZE,
			game->map.grid.height * TILE_SIZE, "so_long");
	game->moves_count = 0;
	load_images(game);
	render_map(game);
	mlx_hook(game->window, 17, 0, game_exit, game);
	mlx_key_hook(game->window, key_handler, game);
	mlx_loop(game->mlx);
}

int	game_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_image(game->mlx, game->map.assets.background.img);
	mlx_destroy_image(game->mlx, game->map.assets.collectible.img);
	mlx_destroy_image(game->mlx, game->map.assets.wall.img);
	mlx_destroy_image(game->mlx, game->map.assets.player.img);
	mlx_destroy_image(game->mlx, game->map.assets.exit.img);
	free_grid(&game->map.grid);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	int		len;
	t_game	game;
	t_grid	grid;

	if (argc != 2)
		return (write(2, ERR_FORMAT, 43), 1);
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
		return (write(2, "Error: invalid extension of map\n", 33), 1);
	read_map(argv[1], &grid);
	if (is_map_valid(grid) == false)
		return (write(2, "Error: invalid map\n", 20), free_grid(&grid), 1);
	set_player_position(&grid);
	count_collectibles(&grid);
	if (flood_fill_init(grid) == false)
		return (write(2, ERR_PATH, 29), free_grid(&grid), 1);
	game.map.grid = grid;
	start_game(&game);
}
