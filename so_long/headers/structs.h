/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:21:02 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/14 15:54:33 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_point
{
	size_t	pos_x;
	size_t	pos_y;
}				t_point;

typedef struct s_sprite
{
	int				pos_w;
	int				pos_h;
	mlx_image_t		*image;
}				t_sprite;

typedef struct s_player
{
	t_point		pos;
	t_point		start_pos;
	t_sprite	sprite;
}				t_player;

typedef struct s_tile
{
	char		tile;
	int			v;
}				t_tile;

typedef struct s_map
{
	size_t		grid_h;
	size_t		grid_w;
	t_sprite	grid_point;
	t_tile		**tiles;
	int			accessible_collectibles;
	int			exit_accessible;
	int			fd;
	char		*path;
	char		**grid;
}				t_map;

typedef struct s_vars
{
	mlx_t		*window;
	t_player	player;
	t_map		map;
	t_sprite	wall_sprite;
	t_sprite	collect_sprite;
	t_sprite	floor_sprite;
	t_sprite	exit_sprite;
	t_sprite	player_sprite;
	mlx_image_t	*rads;
	mlx_image_t	*counter;
	int			collected;
	int			collectibles;
	int			exit_found;
	int			start_found;
	int			on_top_e;
	int			steps_taken;
	int			randmap_valid;
	int			randmap_e_placed;
	int			randmap_p_placed;
	int			rads_taken;
}				t_vars;

#endif