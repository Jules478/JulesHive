/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:49:21 by mpierce           #+#    #+#             */
/*   Updated: 2025/03/18 15:32:20 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	snooze(t_philo *philo)
{
	if (philo->mother->stop == true)
		return ;
	print_msg(philo, SLEEP);
	ft_usleep(philo, philo->sleep_time);
}

void	think(t_philo *philo)
{
	if (philo->mother->stop == true)
		return ;
	print_msg(philo, THINK);
	usleep(1000);
}

void	eat(t_philo *philo)
{
	if (philo->mother->stop == true)
		return ;
	while (philo->left_fork->on_table == false)
		time_funcs(philo, 3);
	pthread_mutex_lock(&philo->left_fork->lock);
	if (check_left_fork(philo) == 1)
		return ;
	print_msg(philo, FORK);
	if (philo->mother->philo_no == 1)
		return (only_one(philo));
	while (philo->right_fork->on_table == false)
		time_funcs(philo, 3);
	pthread_mutex_lock(&philo->right_fork->lock);
	if (check_right_fork(philo) == 1)
		return ;
	eating(philo);
}

void	*philo_control(void *param)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)param;
	if (philo->philo_index % 2 != 0)
		think_at_start(philo);
	else
		think(philo);
	while (philo->mother->stop == false)
	{
		if (philo->mother->stop == true)
			break ;
		if (time_funcs(philo, 3) == 1)
			break ;
		if (philo->eat_no != -2 && i++ == philo->eat_no)
			break ;
		eat(philo);
		if (philo->mother->philo_no != 1)
		{
			snooze(philo);
			think(philo);
		}
	}
	return (NULL);
}

int	create_threads(t_mother *mother)
{
	int	i;

	i = -1;
	while (++i < mother->philo_no)
	{
		if (pthread_create(&mother->philo[i].tid, NULL, &philo_control, \
				&mother->philo[i]) != 0)
		{
			mother->stop = true;
			return (thread_error(mother, "Thread creation failed", i));
		}
	}
	while (i--)
	{
		if (pthread_join(mother->philo[i].tid, NULL) != 0)
			return (error_ret(mother, "Thread joining failed", 1));
	}
	return (0);
}
