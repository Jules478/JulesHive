/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:44:54 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/14 12:22:59 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	check_valid_path(t_point p, t_vars *game)
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
	check_valid_path((t_point){p.pos_x - 1, p.pos_y}, game);
	check_valid_path((t_point){p.pos_x + 1, p.pos_y}, game);
	check_valid_path((t_point){p.pos_x, p.pos_y - 1}, game);
	check_valid_path((t_point){p.pos_x, p.pos_y + 1}, game);
}
