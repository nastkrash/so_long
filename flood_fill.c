/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakrash <anakrash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:37:26 by anakrash          #+#    #+#             */
/*   Updated: 2024/12/21 16:57:10 by anakrash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	find_exit(t_grid grid)
{
	int	i;

	i = 0;
	while (i < grid.height)
	{
		if (ft_strchr(grid.grid[i], 'E') != NULL)
			return (true);
		i++;
	}
	return (false);
}

void	free_grid(t_grid *grid)
{
	int	i;

	i = 0;
	while (i < grid->height)
	{
		free(grid->grid[i]);
		i++;
	}
	free(grid->grid);
}

bool	flood_fill_init(t_grid grid)
{
	t_grid	copy;
	int		i;

	copy.grid = malloc(sizeof(char *) * 100000);
	i = 0;
	while (i < grid.height)
	{
		copy.grid[i] = ft_strdup(grid.grid[i]);
		i++;
	}
	copy.grid[i] = NULL;
	copy.height = grid.height;
	copy.width = grid.width;
	copy.collectibles_count = 0;
	flood_fill(grid.player_x, grid.player_y, &copy);
	if (copy.collectibles_count != grid.collectibles_count
		|| find_exit(copy) == true)
	{
		free_grid(&copy);
		return (false);
	}
	free_grid(&copy);
	return (true);
}

void	flood_fill(int x, int y, t_grid *copy)
{
	if (copy->grid[y][x] == '1')
		return ;
	if (copy->grid[y][x] == 'E')
	{
		copy->grid[y][x] = '1';
		return ;
	}
	if (copy->grid[y][x] == 'C')
		copy->collectibles_count++;
	copy->grid[y][x] = '1';
	flood_fill(x - 1, y, copy);
	flood_fill(x + 1, y, copy);
	flood_fill(x, y - 1, copy);
	flood_fill(x, y + 1, copy);
}
