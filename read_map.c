/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakrash <anakrash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:19:51 by anakrash          #+#    #+#             */
/*   Updated: 2024/12/21 19:06:55 by anakrash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_position(t_grid *grid)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	x = 0;
	while (y < grid->height)
	{
		x = 0;
		while (x < grid->width)
		{
			c = grid->grid[y][x];
			if (c == 'P')
			{
				grid->player_x = x;
				grid->player_y = y;
			}
			x++;
		}
		y++;
	}
}

void	count_collectibles(t_grid *grid)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	x = 0;
	grid->collectibles_count = 0;
	while (y < grid->height)
	{
		x = 0;
		while (x < grid->width)
		{
			c = grid->grid[y][x];
			if (c == 'C')
				grid->collectibles_count++;
			x++;
		}
		y++;
	}
}

void	write_map(int fd, t_grid *grid)
{
	int		y;
	char	*line;

	y = 0;
	grid->grid = malloc(sizeof(char *) * 100000);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		grid->grid[y++] = line;
		line = get_next_line(fd);
	}
	grid->grid[y] = NULL;
	grid->height = y;
	grid->width = ft_strlen(grid->grid[0]);
}

int	read_map(char *filename, t_grid *grid)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error: Unable to open the map\n", 31);
		exit(1);
	}
	write_map(fd, grid);
	close(fd);
	return (0);
}
