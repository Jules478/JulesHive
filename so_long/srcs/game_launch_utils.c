/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_launch_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:38:22 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/14 16:14:52 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	bad_char(char **s, size_t grid_h, size_t grid_w)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < grid_h)
	{
		j = 0;
		while (j < grid_w)
		{
			if (s[i][j] != COLLECT && s[i][j] != START && s[i][j] != \
				EXIT && s[i][j] != WALL && s[i][j] != FLOOR)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	stat_count(t_vars *game, char c, t_point coord)
{
	if (c == START)
	{
		game->start_found++;
		game->player.pos = coord;
		game->player.start_pos = coord;
	}
	else if (game->map.grid[coord.pos_y][coord.pos_x] == EXIT)
		game->exit_found++;
	else if (game->map.grid[coord.pos_y][coord.pos_x] == COLLECT)
		game->collectibles++;
}

int	wall_error(t_vars *game)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < game->map.grid_w)
	{
		if (game->map.grid[y][x] != WALL)
			return (1);
		else if (game->map.grid[game->map.grid_h - 1][x] != WALL)
			return (1);
		x++;
	}
	x = 0;
	while (y < game->map.grid_h)
	{
		if (game->map.grid[y][x] != WALL)
			return (1);
		else if (game->map.grid[y][game->map.grid_w - 1] != WALL)
			return (1);
		y++;
	}
	return (0);
}

void	check_map(t_vars *game)
{
	if (game->exit_found <= 0)
		error_ret("No exit found", game, NULL, 1);
	if (game->collectibles <= 0)
		error_ret("No collectibles found", game, NULL, 1);
	if (game->start_found <= 0)
		error_ret("No start position found", game, NULL, 1);
	if (!game->map.exit_accessible)
		error_ret("Exit inaccessible", game, NULL, 1);
	if (game->map.accessible_collectibles != game->collectibles)
		error_ret("1 or more collectibles inaccessible", game, NULL, 1);
	if (game->start_found > 1)
		error_ret("Multiple start positions found", game, NULL, 1);
	if (game->exit_found > 1)
		error_ret("Multiple exits found", game, NULL, 1);
}

void	alloc_line(t_vars *game, t_point grid)
{
	game->map.grid[grid.pos_y] = malloc((game->map.grid_w) * sizeof(char));
	if (!game->map.grid[grid.pos_y])
		error_ret("Memory allocation failed", game, NULL, 1);
	game->map.tiles[grid.pos_y] = malloc((game->map.grid_w) * sizeof(t_tile));
	if (!game->map.tiles[grid.pos_y])
		error_ret("Memory allocation failed", game, NULL, 1);
}
