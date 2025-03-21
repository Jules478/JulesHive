/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:04:35 by mpierce           #+#    #+#             */
/*   Updated: 2025/03/18 15:31:58 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_mother	mother;

	mother.forks = NULL;
	mother.philo = NULL;
	if (argc < 5 || argc > 6)
		return (error_ret(NULL, USEMSG, 0));
	if (assign_to_struct(&mother, argc, argv) < 0)
		return (-1);
	if (create_threads(&mother) < 0)
		return (-1);
	free_all(&mother, 1);
	return (0);
}
