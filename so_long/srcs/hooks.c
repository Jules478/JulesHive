/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:01:50 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/14 16:59:15 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	reapply_texture(t_vars *game, int x, int y)
{
	int	px;
	int	py;

	px = game->player.pos.pos_x;
	py = game->player.pos.pos_y;
	game->player.pos.pos_x = x;
	game->player.pos.pos_y = y;
	game->map.grid[py][px] = '0';
	game->map.grid[y][x] = 'P';
	if (!game->on_top_e)
		assign_texture(game, py, px);
	else
	{
		game->on_top_e = 0;
		game->map.grid[py][px] = 'E';
		assign_texture(game, py, px);
	}
	assign_texture(game, y, x);
}

void	check_game_state(t_vars *game, int type)
{
	if (type == 1)
	{
		if (game->collected == game->collectibles)
		{
			print_message(game, 1);
			mlx_terminate(game->window);
			free_game(game, 1);
			exit(EXIT_SUCCESS);
		}
		print_message(game, 3);
	}
	else if (type == 2)
	{
		game->rads_taken += 10;
		if (game->rads_taken == 1000)
		{
			print_message(game, 6);
			mlx_terminate(game->window);
			free_game(game, 1);
			exit(EXIT_SUCCESS);
		}
		update_rad_counter(game);
	}
}

void	player_moves(t_vars *game, int x, int y)
{
	if (game->map.grid[y][x] == '1')
	{
		check_game_state(game, 2);
		print_message(game, 5);
		return ;
	}
	game->steps_taken += 1;
	update_screen_counter(game);
	if (game->map.grid[y][x] == 'E')
	{
		check_game_state(game, 1);
		reapply_texture(game, x, y);
		game->on_top_e = 1;
	}
	if (game->map.grid[y][x] == '0')
	{
		print_message(game, 3);
		reapply_texture(game, x, y);
	}
	else if (game->map.grid[y][x] == 'C')
	{
		game->collected += 1;
		print_message(game, 2);
		reapply_texture(game, x, y);
	}
}

void	fa_hook(mlx_key_data_t keydata, void *param)
{
	t_vars	*game;
	int		x;
	int		y;

	game = (t_vars *)param;
	x = game->player.pos.pos_x;
	y = game->player.pos.pos_y;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(game->window);
		free_game(game, 1);
		exit(EXIT_SUCCESS);
	}
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == \
		MLX_KEY_S) && keydata.action == MLX_PRESS)
		player_moves(game, x, y + 1);
	if ((keydata.key == MLX_KEY_UP || keydata.key == \
		MLX_KEY_W) && keydata.action == MLX_PRESS)
		player_moves(game, x, y - 1);
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == \
		MLX_KEY_A) && keydata.action == MLX_PRESS)
		player_moves(game, x - 1, y);
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == \
		MLX_KEY_D) && keydata.action == MLX_PRESS)
		player_moves(game, x + 1, y);
}
