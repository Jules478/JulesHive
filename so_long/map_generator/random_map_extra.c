/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_map_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:04:57 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/14 15:47:10 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	error_ret_rand(char *msg, t_vars *game, char *str)
{
	if (str)
	{
		free(str);
		while (str)
		{
			str = get_next_line(game->map.fd);
			free(str);
		}
	}
	close(game->map.fd);
	if (game->map.tiles)
		free_tiles_rand(game);
	if (game->map.grid)
		free_game_rand(game);
	free(game);
	ft_printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

void	start_game_rand(char *name, t_vars *game)
{
	game->map.path = name;
	game->collected = 0;
	game->map.exit_accessible = 0;
	game->map.accessible_collectibles = 0;
	game->collectibles = 0;
	game->exit_found = 0;
	game->start_found = 0;
	game->on_top_e = 0;
	game->steps_taken = 0;
	game->map.tiles = NULL;
	game->map.grid = NULL;
}

void	free_tiles_rand(t_vars *game)
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

void	fill_grid_rand(t_vars *game, char *line, t_point coord)
{
	game->map.grid[coord.pos_y][coord.pos_x] = line[coord.pos_x];
	game->map.tiles[coord.pos_y][coord.pos_x].tile = line[coord.pos_x];
	game->map.tiles[coord.pos_y][coord.pos_x].v = 0;
}

void	alloc_line_rand(t_vars *game, t_point grid)
{
	game->map.grid[grid.pos_y] = malloc((game->map.grid_w) * sizeof(char));
	if (!game->map.grid[grid.pos_y])
		error_ret_rand("Memory allocation failed", game, NULL);
	game->map.tiles[grid.pos_y] = malloc((game->map.grid_w) * sizeof(t_tile));
	if (!game->map.tiles[grid.pos_y])
		error_ret_rand("Memory allocation failed", game, NULL);
}
