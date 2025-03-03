/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:16:29 by mpierce           #+#    #+#             */
/*   Updated: 2025/03/03 13:56:51 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_usleep(t_philo *philo, long time)
{
	long	start;

	start = get_current_time(philo->mother);
	while (philo->mother->stop == false && (get_current_time(philo->mother) \
		- start) < time)
	{
		usleep(1000);
		time_funcs(philo, 3);
	}
}

long	time_funcs(t_philo *philo, int mode)
{
	if (mode == 1)
	{
		while (get_current_time(philo->mother) < philo->mother->start_time)
			usleep(100);
		return (0);
	}
	else if (mode == 2)
		return (get_current_time(philo->mother) - philo->mother->start_time);
	else if (mode == 3)
	{
		if (get_current_time(philo->mother) - \
			philo->die_time >= philo->since_last)
		{
			philo->mother->stop = true;
			print_msg(philo, DIE);
			return (1);
		}
	}
	return (0);
}

void	print_msg(t_philo *philo, int msg)
{
	if (philo->mother->stop == true && msg != DIE)
		return ;
	pthread_mutex_lock(&philo->mother->print_lock);
	if (msg == FORK && philo->mother->stop == false)
		printf("[%ld] %d has taken a fork\n", time_funcs(philo, 2), \
		philo->philo_index + 1);
	else if (msg == EAT && philo->mother->stop == false)
	{
		printf("[%ld] %d is eating\n", time_funcs(philo, 2), \
		philo->philo_index + 1);
	}
	else if (msg == SLEEP && philo->mother->stop == false)
		printf("[%ld] %d is sleeping\n", time_funcs(philo, 2), \
		philo->philo_index + 1);
	else if (msg == THINK && philo->mother->stop == false)
		printf("[%ld] %d is thinking\n", time_funcs(philo, 2), \
		philo->philo_index + 1);
	else if (msg == DIE && philo->mother->death == false)
	{
		philo->mother->death = true;
		printf("[%ld] %d has died\n", time_funcs(philo, 2), \
		philo->philo_index + 1);
	}
	pthread_mutex_unlock(&philo->mother->print_lock);
}

void	eating(t_philo *philo)
{
	print_msg(philo, FORK);
	print_msg(philo, EAT);
	philo->since_last = get_current_time(philo->mother);
	ft_usleep(philo, philo->eat_time);
}
