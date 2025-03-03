/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:49:21 by mpierce           #+#    #+#             */
/*   Updated: 2025/03/03 13:57:39 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	snoozenthink(t_philo *philo)
{
	if (philo->mother->stop == true)
		return ;
	print_msg(philo, SLEEP);
	ft_usleep(philo, philo->sleep_time);
	if (philo->mother->stop == true)
		return ;
	print_msg(philo, THINK);
	usleep(1);
}

void	eat(t_philo *philo)
{
	if (philo->mother->stop == true)
		return ;
	pthread_mutex_lock(philo->left_fork);
	if (philo->mother->stop == true)
	{
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	print_msg(philo, FORK);
	if (philo->mother->philo_no == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		ft_usleep(philo, philo->die_time);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	if (philo->mother->stop == true)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	eating(philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*philo_control(void *param)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)param;
	time_funcs(philo, 1);
	if (philo->philo_index % 2 == 0)
		usleep(100);
	while (philo->mother->stop == false)
	{
		if (philo->mother->stop == true)
			break ;
		if (time_funcs(philo, 3) == 1)
			break ;
		if (philo->eat_no > 0 && i++ == philo->eat_no)
			break ;
		eat(philo);
		if (philo->mother->philo_no != 1)
			snoozenthink(philo);
	}
	return (NULL);
}

void	create_threads(t_mother *mother)
{
	int	i;

	i = -1;
	while (++i < mother->philo_no)
	{
		if (pthread_create(&mother->philo[i].tid, NULL, &philo_control, \
			&mother->philo[i]) != 0)
			error_ret(mother, "Thread creation failed");
	}
	while (i--)
	{
		if (pthread_join(mother->philo[i].tid, NULL) != 0)
			error_ret(mother, "Thread joining failed");
	}
	pthread_mutex_destroy(&mother->print_lock);
	while (++i < mother->philo_no)
		pthread_mutex_destroy(&mother->forks[i]);
}
