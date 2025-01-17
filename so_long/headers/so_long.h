/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:44:25 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/14 16:39:23 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL '1'
# define FLOOR '0'
# define START 'P'
# define EXIT 'E'
# define COLLECT 'C'

# define WALL_PNG		"png/rad.png"
# define FLOOR_PNG		"png/grass2.png"
# define COLLECT_PNG	"png/bottlecap.png"
# define PLAYER_PNG		"png/vaultboy.png"
# define EXIT_PNG		"png/vaultdoor.png"

# define SCREEN_MAX_WIDTH 3840
# define SCREEN_MAX_HEIGHT 2160
# define PIXELS 48

# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stddef.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "structs.h"
# include "../libftmaster/libft.h"

int		error_ret(char *msg, t_vars *game, char *str, int check);
void	validation(int argc, char **argv);
void	parse_map(t_vars *game);
void	start_game(char *name, t_vars *game);
size_t	map_line_len(char *line);
void	build_game(t_vars *game);
int		bad_char(char **s, size_t grid_h, size_t grid_w);
void	stat_count(t_vars *game, char c, t_point coord);
int		wall_error(t_vars *game);
void	free_tiles(t_vars *game);
void	check_valid_path(t_point p, t_vars *game);
void	check_map(t_vars *game);
int		open_map(char *map);
void	alloc_line(t_vars *game, t_point grid);
void	load_textures(t_vars *game);
void	load_background(t_vars *game);
void	texture_placement(t_vars *game);
void	fa_hook(mlx_key_data_t keydata, void *param);
void	assign_texture(t_vars *game, int y, int x);
void	print_message(t_vars *game, int msg);
void	screen_counter_init(t_vars *game);
void	update_screen_counter(t_vars *game);
void	free_game(t_vars *game, int end);
void	screen_rads_init(t_vars *game);
void	update_rad_counter(t_vars *game);

// Map Generator Declarations

void	map_init_rand(t_vars *game, t_point *grid);
int		check_map_rand(t_vars *game);
void	reset_rand(t_vars *game);
void	fill_grid_rand(t_vars *game, char *line, t_point coord);
void	build_map_rand(t_vars *game, t_point coord);
void	alloc_line_rand(t_vars *game, t_point grid);
void	check_valid_path_rand(t_point p, t_vars *game);
int		error_ret_rand(char *msg, t_vars *game, char *str);
void	start_game_rand(char *name, t_vars *game);
void	free_tiles_rand(t_vars *game);
void	stat_count_rand(t_vars *game, char c, t_point coord);
int		bad_char_rand(char **s, size_t grid_h, size_t grid_w);
int		open_map_rand(char *map);
void	free_game_rand(t_vars *game);

#endif