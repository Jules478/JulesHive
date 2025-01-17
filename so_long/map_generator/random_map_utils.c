/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:05:03 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/13 17:05:03 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_map_rand(t_vars *game)
{
	if (game->exit_found <= 0)
		return (-1);
	if (game->collectibles <= 0)
		return (-1);
	if (game->start_found <= 0)
		return (-1);
	if (!game->map.exit_accessible)
		return (-1);
	if (game->map.accessible_collectibles != game->collectibles)
		return (-1);
	if (game->start_found > 1)
		return (-1);
	if (game->exit_found > 1)
		return (-1);
	return (1);
}

void	reset_rand(t_vars *game)
{
	free_tiles_rand(game);
	free_game_rand(game);
}

void	map_init_rand(t_vars *game, t_point *grid)
{
	game->map.fd = open_map_rand(game->map.path);
	game->map.grid = malloc(game->map.grid_h * sizeof(char *));
	if (!game->map.grid)
		error_ret_rand("Map allocation failure", game, NULL);
	game->map.tiles = malloc(game->map.grid_h * sizeof(t_tile *));
	if (!game->map.tiles)
		error_ret_rand("Map allocation failure", game, NULL);
	grid->pos_x = 0;
	grid->pos_y = 0;
}

void	build_map_rand(t_vars *game, t_point coord)
{
	char	*line;

	line = get_next_line(game->map.fd);
	coord.pos_y = 0;
	while (line)
	{
		coord.pos_x = 0;
		alloc_line_rand(game, coord);
		while (coord.pos_x < game->map.grid_w)
		{
			fill_grid_rand(game, line, coord);
			stat_count_rand(game, game->map.grid[coord.pos_y][coord.pos_x], \
				coord);
			coord.pos_x++;
		}
		coord.pos_y++;
		free(line);
		line = get_next_line(game->map.fd);
	}
	free(line);
}

void	check_valid_path_rand(t_point p, t_vars *game)
{
	size_t	grid_w;
	size_t	grid_h;

	grid_w = game->map.grid_w;
	grid_h = game->map.grid_h;
	if (game->map.grid[p.pos_y][p.pos_x] == WALL || \
		game->map.tiles[p.pos_y][p.pos_x].v == 1 || \
		p.pos_x < 0 || p.pos_y < 0 || p.pos_x > grid_w || \
		p.pos_y > grid_h)
		return ;
	game->map.tiles[p.pos_y][p.pos_x].v = 1;
	if (game->map.grid[p.pos_y][p.pos_x] == EXIT)
		game->map.exit_accessible = 1;
	if (game->map.grid[p.pos_y][p.pos_x] == COLLECT)
		game->map.accessible_collectibles++;
	check_valid_path_rand((t_point){p.pos_x - 1, p.pos_y}, game);
	check_valid_path_rand((t_point){p.pos_x + 1, p.pos_y}, game);
	check_valid_path_rand((t_point){p.pos_x, p.pos_y - 1}, game);
	check_valid_path_rand((t_point){p.pos_x, p.pos_y + 1}, game);
}
