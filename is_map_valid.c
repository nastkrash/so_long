/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakrash <anakrash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:22:20 by anakrash          #+#    #+#             */
/*   Updated: 2024/12/21 16:57:26 by anakrash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_rectangular(t_grid grid)
{
	int	i;

	i = 0;
	while (grid.grid[i])
	{
		if (ft_strlen(grid.grid[i]) != grid.width)
			return (false);
		i++;
	}
	return (true);
}

bool	has_valid_characters(t_grid grid)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < grid.height)
	{
		x = 0;
		while (x < grid.width)
		{
			c = grid.grid[y][x];
			if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	has_single_player_and_exit(t_grid grid)
{
	int	x;
	int	y;
	int	exit_count;
	int	player_count;

	y = 0;
	exit_count = 0;
	player_count = 0;
	while (y < grid.height)
	{
		x = 0;
		while (x < grid.width)
		{
			if (grid.grid[y][x] == 'P')
				player_count++;
			if (grid.grid[y][x] == 'E')
				exit_count++;
			x++;
		}
		y++;
	}
	if (player_count != 1 || exit_count != 1)
		return (false);
	return (true);
}

bool	is_surrounded_by_walls(t_grid grid)
{
	int	x;
	int	y;

	x = 0;
	while (x < grid.width)
	{
		if (grid.grid[0][x] != '1' || grid.grid[grid.height - 1][x] != '1')
			return (false);
		x++;
	}
	y = 0;
	while (y < grid.height)
	{
		if (grid.grid[y][0] != '1' || grid.grid[y][grid.width - 1] != '1')
			return (false);
		y++;
	}
	return (true);
}

bool	is_map_valid(t_grid grid)
{
	if (grid.height > 31 || grid.width > 60)
		return (false);
	if (!is_rectangular(grid) || !has_single_player_and_exit(grid)
		|| !has_valid_characters(grid) || !is_surrounded_by_walls(grid))
		return (false);
	return (true);
}
