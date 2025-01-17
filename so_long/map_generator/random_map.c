/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:21:42 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/14 15:21:42 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	build_game_rand(t_vars *game)
{
	t_point	coord;

	map_init_rand(game, &coord);
	build_map_rand(game, coord);
	close(game->map.fd);
	if (game->randmap_p_placed != 1)
	{
		reset_rand(game);
		return ;
	}
	check_valid_path_rand(game->player.pos, game);
	if (check_map_rand(game) < 0)
		reset_rand(game);
	else
		game->randmap_valid = 1;
}

char	generate_char_rand(t_vars *game)
{
	int	i;

	i = rand() % 200 + 1;
	if (i < 40)
		return ('1');
	else if (i >= 41 && i <= 65)
		return ('C');
	else if (i == 131)
	{
		if (game->randmap_p_placed == 0)
		{
			game->randmap_p_placed = 1;
			return ('P');
		}
	}
	else if (i == 132)
	{
		if (game->randmap_e_placed == 0)
		{
			game->randmap_e_placed = 1;
			return ('E');
		}
	}
	return ('0');
}

void	create_map_rand(t_vars *game, int fd)
{
	size_t	x;
	size_t	y;
	char	rand;

	y = 0;
	while (y < game->map.grid_h)
	{
		x = 0;
		while (x < game->map.grid_w)
		{
			if (y == 0 || y == game->map.grid_h - 1)
				write(fd, "1", 1);
			else if (x == 0 || x == game->map.grid_w - 1)
				write(fd, "1", 1);
			else
			{
				rand = generate_char_rand(game);
				write(fd, &rand, 1);
			}
			x++;
		}
		write(fd, "\n", 1);
		y++;
	}
}

void	generate_map_rand(t_vars *game)
{
	int		lower_bound;
	int		upper_bound_h;
	int		upper_bound_w;
	int		fd;

	lower_bound = 4;
	upper_bound_h = 45;
	upper_bound_w = 80;
	game->randmap_e_placed = 0;
	game->randmap_p_placed = 0;
	game->map.grid_w = rand() % (upper_bound_w - lower_bound + 1) + lower_bound;
	game->map.grid_h = rand() % (upper_bound_h - lower_bound + 1) + lower_bound;
	fd = open("maps/random.ber", O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
		error_ret_rand("Error Creating File", game, NULL);
	create_map_rand(game, fd);
	close(fd);
}

int	main(void)
{
	t_vars	*game;

	game = (t_vars *)malloc(sizeof(t_vars));
	if (!(game))
		error_ret_rand("Failed to initialize", game, NULL);
	game->randmap_valid = 0;
	srand(getpid());
	while (game->randmap_valid == 0)
	{
		start_game_rand("random.ber", game);
		generate_map_rand(game);
		build_game_rand(game);
	}
	ft_printf("Map Generated\n");
	reset_rand(game);
	free(game);
	return (0);
}
