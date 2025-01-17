/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   screen_counter.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mpierce <mpierce@student.hive.fi>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/14 12:23:17 by mpierce		   #+#	#+#			 */
/*   Updated: 2025/01/14 12:23:17 by mpierce		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../headers/so_long.h"

void	screen_counter_init(t_vars *game)
{
	char	*steps;
	char	*text;

	steps = ft_itoa(game->steps_taken);
	text = ft_strjoin("Steps: ", steps);
	game->counter = mlx_put_string(game->window, text, 0, 0);
	if (!game->counter)
	{
		mlx_terminate(game->window);
		error_ret("Step counter failed to load\n", game, NULL, 1);
	}
	free(text);
	free(steps);
}

void	update_screen_counter(t_vars *game)
{
	char	*steps;
	char	*text;

	steps = ft_itoa(game->steps_taken);
	text = ft_strjoin("Steps: ", steps);
	mlx_delete_image(game->window, game->counter);
	game->counter = mlx_put_string(game->window, text, 0, 0);
	if (!game->counter)
	{
		mlx_terminate(game->window);
		error_ret("Step counter failed to update\n", game, NULL, 1);
	}
	free(text);
	free(steps);
}

void	screen_rads_init(t_vars *game)
{
	char	*rads;
	char	*text;

	rads = ft_itoa(game->rads_taken);
	text = ft_strjoin("Rads: ", rads);
	game->rads = mlx_put_string(game->window, text, 0, 20);
	if (!game->rads)
	{
		mlx_terminate(game->window);
		error_ret("Rad counter failed to load\n", game, NULL, 1);
	}
	free(text);
	free(rads);
}

void	update_rad_counter(t_vars *game)
{
	char	*rads;
	char	*text;

	rads = ft_itoa(game->rads_taken);
	text = ft_strjoin("Rads: ", rads);
	mlx_delete_image(game->window, game->rads);
	game->rads = mlx_put_string(game->window, text, 0, 20);
	if (!game->rads)
	{
		mlx_terminate(game->window);
		error_ret("Step counter failed to update\n", game, NULL, 1);
	}
	free(text);
	free(rads);
}
