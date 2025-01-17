/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:27:25 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/14 16:40:31 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	start_window(t_vars *game)
{
	mlx_t	*window;

	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	window = mlx_init(game->map.grid_w * PIXELS, game->map.grid_h * \
		PIXELS, "Fallout 5", true);
	if (!window)
		error_ret("Error Opening Window", game, NULL, 1);
	game->window = window;
	load_textures(game);
	load_background(game);
	texture_placement(game);
	screen_counter_init(game);
	screen_rads_init(game);
}

int	main(int argc, char **argv)
{
	t_vars	*game;

	validation(argc, argv);
	game = (t_vars *)malloc(sizeof(t_vars));
	if (!(game))
		error_ret("Failed to initialize game", game, NULL, 0);
	start_game(argv[1], game);
	parse_map(game);
	build_game(game);
	free_tiles(game);
	start_window(game);
	mlx_close_hook(game->window, (mlx_closefunc)free_game, game);
	mlx_key_hook(game->window, &fa_hook, game);
	mlx_loop(game->window);
	mlx_terminate(game->window);
	free(game);
	return (0);
}
