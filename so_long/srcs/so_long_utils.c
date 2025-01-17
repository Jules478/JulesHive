/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:47:31 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/14 16:20:42 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	error_ret(char *msg, t_vars *game, char *str, int check)
{
	if (str)
	{
		free(str);
		while (str)
		{
			str = get_next_line(game->map.fd);
			free(str);
		}
	}
	if (check == 1)
	{
		close(game->map.fd);
		if (game->map.tiles)
			free_tiles(game);
		if (game->map.grid)
			free_game(game, 0);
	}
	free(game);
	ft_printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

size_t	map_line_len(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}
