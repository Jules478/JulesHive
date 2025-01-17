/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_launch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:41:01 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/14 16:15:06 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	start_game(char *name, t_vars *game)
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
	game->rads_taken = 0;
}

void	map_init(t_vars *game, t_point *grid)
{
	game->map.fd = open_map(game->map.path);
	game->map.grid = malloc(game->map.grid_h * sizeof(char *));
	if (!game->map.grid)
		error_ret("Map allocation failure", game, NULL, 1);
	game->map.tiles = malloc(game->map.grid_h * sizeof(t_tile *));
	if (!game->map.tiles)
		error_ret("Map allocation failure", game, NULL, 1);
	grid->pos_x = 0;
	grid->pos_y = 0;
}

void	fill_grid(t_vars *game, char *line, t_point coord)
{
	game->map.grid[coord.pos_y][coord.pos_x] = line[coord.pos_x];
	game->map.tiles[coord.pos_y][coord.pos_x].tile = line[coord.pos_x];
	game->map.tiles[coord.pos_y][coord.pos_x].v = 0;
}

void	build_map(t_vars *game, t_point coord)
{
	char	*line;

	line = get_next_line(game->map.fd);
	coord.pos_y = 0;
	while (line)
	{
		coord.pos_x = 0;
		alloc_line(game, coord);
		while (coord.pos_x < game->map.grid_w)
		{
			fill_grid(game, line, coord);
			stat_count(game, game->map.grid[coord.pos_y][coord.pos_x], coord);
			coord.pos_x++;
		}
		coord.pos_y++;
		free(line);
		line = get_next_line(game->map.fd);
	}
	if (bad_char(game->map.grid, game->map.grid_h, game->map.grid_w))
		error_ret("Unrecognized character in map file", game, NULL, 1);
	free(line);
}

void	build_game(t_vars *game)
{
	t_point	coord;

	map_init(game, &coord);
	build_map(game, coord);
	close(game->map.fd);
	if (wall_error(game))
		error_ret("Map is not closed", game, NULL, 1);
	check_valid_path(game->player.pos, game);
	check_map(game);
}
