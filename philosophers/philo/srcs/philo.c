/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:04:35 by mpierce           #+#    #+#             */
/*   Updated: 2025/03/04 17:43:17 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_mother	mother;

	if (argc < 5 || argc > 6)
		error_ret(NULL, USEMSG, 0);
	assign_to_struct(&mother, argc, argv);
	create_threads(&mother);
	free_all(&mother, 0);
	return (0);
}
