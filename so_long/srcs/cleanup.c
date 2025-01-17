/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:53:22 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/14 16:39:10 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_tiles(t_vars *game)
{
	size_t	i;

	i = 0;
	while (i < game->map.grid_h)
	{
		free(game->map.tiles[i]);
		game->map.tiles[i] = NULL;
		i++;
	}
	free(game->map.tiles);
	game->map.tiles = NULL;
}

void	free_game(t_vars *game, int end)
{
	size_t	i;

	i = 0;
	while (i < game->map.grid_h)
	{
		free(game->map.grid[i]);
		game->map.grid[i] = NULL;
		i++;
	}
	free(game->map.grid);
	game->map.grid = NULL;
	if (end == 1)
		free(game);
}
