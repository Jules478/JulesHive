/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:27:27 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/14 16:14:17 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	valid_map_name(char *name)
{
	int	i;

	i = ft_strlen(name);
	if (name[i - 1] == 'r' && name[i - 2] == 'e' && name[i - 3] == \
		'b' && name[i - 4] == '.')
		return (0);
	return (1);
}

void	validation(int argc, char **argv)
{
	if (argc < 2)
		error_ret("No map specified", NULL, NULL, 0);
	if (argc > 2)
		error_ret("One argument at a time, please", NULL, NULL, 0);
	if (argc == 2 && valid_map_name(argv[1]))
		error_ret("Invalid file type", NULL, NULL, 0);
}

void	parse_map(t_vars *game)
{
	char	*line;

	game->map.fd = open_map(game->map.path);
	if (game->map.fd < 0)
		error_ret("Map not found", game, NULL, 0);
	game->map.grid_h = 0;
	game->map.grid_w = 0;
	line = get_next_line(game->map.fd);
	while (line)
	{
		game->map.grid_h++;
		if (game->map.grid_h == 1)
			game->map.grid_w = map_line_len(line);
		if (map_line_len(line) != game->map.grid_w)
			error_ret("Map not rectangular", game, line, 1);
		free(line);
		line = get_next_line(game->map.fd);
	}
	free(line);
	close(game->map.fd);
	if (game->map.grid_h == 0)
		error_ret("Empty map", game, NULL, 1);
	if (game->map.grid_h > SCREEN_MAX_HEIGHT / PIXELS || game->map.grid_w > \
		SCREEN_MAX_WIDTH / PIXELS)
		error_ret("Map too large", game, NULL, 1);
}
