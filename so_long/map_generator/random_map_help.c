/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_map_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:17:20 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/14 15:47:42 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	stat_count_rand(t_vars *game, char c, t_point coord)
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

int	bad_char_rand(char **s, size_t grid_h, size_t grid_w)
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

int	open_map_rand(char *map)
{
	char	*temp;
	int		fd;

	temp = ft_strjoin("maps/", map);
	fd = open(temp, O_RDONLY);
	free(temp);
	return (fd);
}

void	free_game_rand(t_vars *game)
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
}
