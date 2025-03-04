/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:21:45 by mpierce           #+#    #+#             */
/*   Updated: 2025/03/04 17:46:43 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_philos(t_philo *philo, int index, char **argv, t_mother *mother)
{
	int	argc;
	int	i;

	i = 1;
	argc = 0;
	while (argv[i++])
		argc++;
	philo->die_time = ft_atoi(argv[2]);
	philo->eat_time = ft_atoi(argv[3]);
	philo->sleep_time = ft_atoi(argv[4]);
	if (argc == 5)
		philo->eat_no = ft_atoi(argv[5]);
	else
		philo->eat_no = -1;
	philo->full = false;
	philo->tid = 0;
	philo->mother = mother;
	philo->philo_index = index;
	philo->left_fork = &mother->forks[index];
	philo->right_fork = &mother->forks[(index + 1) % mother->philo_no];
	philo->since_last = get_current_time(philo->mother) + 200;
}

void	init_mother(t_mother *mother)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&mother->print_lock, NULL) != 0)
		error_ret(mother, "Message mutex initialisation failed", 0);
	mother->forks = malloc(mother->philo_no * sizeof(pthread_mutex_t));
	if (!mother->forks)
		error_ret(mother, "Fork lock allocation failed", 1);
	while (++i < mother->philo_no)
	{
		if (pthread_mutex_init(&mother->forks[i], NULL) != 0)
		{
			while (i--)
				pthread_mutex_destroy(&mother->forks[i]);
			error_ret(mother, "Fork mutex initialisation failed", 1);
		}
	}
	mother->start_time = get_current_time(mother) + 200;
	mother->death = false;
}

void	init_manager(t_mother *mother, char **argv)
{
	int	i;

	i = -1;
	mother->philo = NULL;
	mother->forks = NULL;
	init_mother(mother);
	mother->philo = malloc(mother->philo_no * sizeof(t_philo));
	if (!mother->philo)
		error_ret(mother, "Philo allocation failed", 1);
	while (++i < mother->philo_no)
		init_philos(&mother->philo[i], i, argv, mother);
}

void	assign_to_struct(t_mother *mother, int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		validation(argv[i]);
	mother->philo_no = ft_atoi(argv[1]);
	mother->stop = false;
	mother->philo_full = 0;
	if (argc == 6)
		mother->finite = true;
	else
		mother->finite = false;
	init_manager(mother, argv);
}
