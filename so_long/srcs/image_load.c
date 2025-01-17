/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:53:06 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/14 16:15:24 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

mlx_image_t	*load_image(t_vars *game, char *image_path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	image = NULL;
	texture = mlx_load_png(image_path);
	if (!texture)
	{
		mlx_terminate(game->window);
		error_ret("Texture loading failed", game, NULL, 1);
	}
	image = mlx_texture_to_image(game->window, texture);
	if (!image)
	{
		mlx_delete_texture(texture);
		mlx_terminate(game->window);
		error_ret("Texture to image conversion failure", game, NULL, 1);
	}
	mlx_delete_texture(texture);
	return (image);
}

void	load_textures(t_vars *game)
{
	game->wall_sprite.image = load_image(game, WALL_PNG);
	game->floor_sprite.image = load_image(game, FLOOR_PNG);
	game->player_sprite.image = load_image(game, PLAYER_PNG);
	game->collect_sprite.image = load_image(game, COLLECT_PNG);
	game->exit_sprite.image = load_image(game, EXIT_PNG);
}

void	load_background(t_vars *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < SCREEN_MAX_WIDTH / PIXELS)
	{
		y = 0;
		while (y < SCREEN_MAX_HEIGHT / PIXELS)
		{
			if (mlx_image_to_window(game->window, game->floor_sprite.image, x * \
				PIXELS, y * PIXELS) < 0)
			{
				mlx_terminate(game->window);
				error_ret("Background loading failure", game, NULL, 1);
			}
			y++;
		}
		x++;
	}
}

void	assign_texture(t_vars *game, int y, int x)
{
	game->map.grid_point.pos_h = y;
	game->map.grid_point.pos_w = x;
	if (game->map.grid[y][x] == '1')
		game->map.grid_point.image = game->wall_sprite.image;
	else if (game->map.grid[y][x] == '0')
		game->map.grid_point.image = game->floor_sprite.image;
	else if (game->map.grid[y][x] == 'P')
		game->map.grid_point.image = game->player_sprite.image;
	else if (game->map.grid[y][x] == 'E')
		game->map.grid_point.image = game->exit_sprite.image;
	else if (game->map.grid[y][x] == 'C')
		game->map.grid_point.image = game->collect_sprite.image;
	if (mlx_image_to_window(game->window, game->map.grid_point.image, x * \
		PIXELS, y * PIXELS) < 0)
	{
		mlx_terminate(game->window);
		error_ret("Texture loading failure", game, NULL, 1);
	}
}

void	texture_placement(t_vars *game)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < game->map.grid_w)
	{
		y = 0;
		while (y < game->map.grid_h)
		{
			assign_texture(game, y, x);
			y++;
		}
		x++;
	}
}
