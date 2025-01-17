/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_launch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:41:01 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/08 15:44:45 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	print_message(t_vars *game, int msg)
{
	ft_printf("\n --------------------\n|                    |\n");
	if (msg == 1)
		ft_printf("\nYou returned to the vault!\nYou collected %d caps.\n", \
			game->collected);
	else if (msg == 2)
	{
		print_message(game, 3);
		ft_printf("\nYou found a bottlecap!\nYou have %d caps.\n", \
			game->collected);
	}
	else if (msg == 3)
		ft_printf("\nYou have taken %d steps.\n", game->steps_taken);
	else if (msg == 4)
		ft_printf("\nYou cannot go that way.\n");
	else if (msg == 5)
		ft_printf("\nYou cannot go that way.\nYou took 10 rads.\n");
	else if (msg == 6)
		ft_printf("\nYou died.\nYou collected %d caps.\n", game->collected);
	ft_printf("\n|                    |\n --------------------\n");
}
