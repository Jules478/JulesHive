/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:21:45 by mpierce           #+#    #+#             */
/*   Updated: 2025/03/18 15:31:46 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_philos(t_philo *philo, int index, char **argv, t_mother *mother)
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
		philo->eat_no = -2;
	if (philo->die_time < 0 || philo->eat_time < 0 || philo->sleep_time < 0 \
		|| philo->eat_no == -1)
		return (error_ret(mother, "Argument Error", 1));
	philo->full = false;
	philo->tid = 0;
	philo->mother = mother;
	philo->philo_index = index;
	philo->left_fork = &mother->forks[index];
	philo->right_fork = &mother->forks[(index + 1) % mother->philo_no];
	philo->since_last = philo->mother->start_time;
	return (0);
}

int	init_mother(t_mother *mother)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&mother->print_lock, NULL) != 0)
		return (error_ret(mother, "Message initialisation failed", 0));
	mother->forks = malloc(mother->philo_no * sizeof(t_forks));
	if (!mother->forks)
		return (error_ret(mother, "Fork lock allocation failed", 1));
	while (++i < mother->philo_no)
	{
		if (pthread_mutex_init(&mother->forks[i].lock, NULL) != 0)
		{
			while (i--)
				pthread_mutex_destroy(&mother->forks[i].lock);
			return (error_ret(mother, "Fork initialisation failed", 1));
		}
		mother->forks[i].on_table = true;
	}
	mother->death = false;
	mother->start_time = get_current_time(mother);
	if (mother->start_time < 0)
		return (error_ret(mother, "gettimeofday failed", 1));
	return (0);
}

int	init_manager(t_mother *mother, char **argv)
{
	int	i;

	i = -1;
	mother->philo = NULL;
	mother->forks = NULL;
	if (init_mother(mother) < 0)
		return (-1);
	mother->philo = malloc(mother->philo_no * sizeof(t_philo));
	if (!mother->philo)
		return (error_ret(mother, "Philo allocation failed", 1));
	while (++i < mother->philo_no)
		if (init_philos(&mother->philo[i], i, argv, mother) < 0)
			return (-1);
	return (0);
}

int	assign_to_struct(t_mother *mother, int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		if (validation(argv[i]) < 0)
			return (-1);
	mother->philo_no = ft_atoi(argv[1]);
	if (mother->philo_no < 0 || mother->philo_no > 1000)
		return (error_ret(mother, "Argument Error", 0));
	mother->stop = false;
	mother->philo_full = 0;
	if (argc == 6)
		mother->finite = true;
	else
		mother->finite = false;
	if (init_manager(mother, argv) < 0)
		return (-1);
	return (0);
}
