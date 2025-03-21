/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:03:04 by mpierce           #+#    #+#             */
/*   Updated: 2025/03/18 15:34:39 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	only_one(t_philo *philo)
{
	philo->left_fork->on_table = true;
	pthread_mutex_unlock(&philo->left_fork->lock);
	ft_usleep(philo, philo->die_time);
}

int	check_left_fork(t_philo *philo)
{
	philo->left_fork->on_table = false;
	if (philo->mother->stop == true)
	{
		philo->left_fork->on_table = true;
		pthread_mutex_unlock(&philo->left_fork->lock);
		return (1);
	}
	return (0);
}

int	check_right_fork(t_philo *philo)
{
	philo->right_fork->on_table = false;
	if (philo->mother->stop == true)
	{
		philo->left_fork->on_table = true;
		pthread_mutex_unlock(&philo->left_fork->lock);
		philo->right_fork->on_table = true;
		pthread_mutex_unlock(&philo->right_fork->lock);
		return (1);
	}
	return (0);
}

void	think_at_start(t_philo *philo)
{
	if (philo->mother->stop == true)
		return ;
	print_msg(philo, THINK);
	ft_usleep(philo, 10);
}
