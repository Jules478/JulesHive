/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:09:55 by mpierce           #+#    #+#             */
/*   Updated: 2025/03/18 15:31:25 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while ((nptr[i] >= 48 && nptr[i] <= 57) && nptr[i])
	{
		if (num > 214748364 || (num == 214748364 && (nptr[i] - 48) > 7))
			return (-1);
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	if (num == 0)
		return (-1);
	return (num);
}

int	validation(char *arg)
{
	int	i;

	i = -1;
	if (!arg || *arg == 0)
		return (error_ret(NULL, "Arguments cannot be blank", 0));
	while (arg[++i])
	{
		if (arg[i] < 48 || arg[i] > 57)
			return (error_ret(NULL, "Arguments must be unsigned integers", 0));
	}
	return (0);
}

long	get_current_time(t_mother *mother)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) < 0)
	{
		mother->stop = true;
		return (-1);
	}
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	free_all(t_mother *mother, int print)
{
	int	i;

	i = -1;
	if (mother)
	{
		if (mother->philo)
		{
			free(mother->philo);
			mother->philo = NULL;
		}
		if (mother->forks)
		{
			while (++i < mother->philo_no)
				pthread_mutex_destroy(&mother->forks[i].lock);
			free(mother->forks);
			mother->forks = NULL;
		}
		if (print == 1)
			pthread_mutex_destroy(&mother->print_lock);
	}
}

int	error_ret(t_mother *mother, char *msg, int print)
{
	free_all(mother, print);
	printf("\e[1;31m%s\n\e[0m", msg);
	return (-1);
}
