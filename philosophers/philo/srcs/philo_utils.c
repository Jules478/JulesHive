/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:09:55 by mpierce           #+#    #+#             */
/*   Updated: 2025/03/03 13:58:57 by mpierce          ###   ########.fr       */
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
			error_ret(NULL, "Overflow Error");
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	if (num == 0)
		error_ret(NULL, "Arguments cannot be 0");
	return (num);
}

void	validation(char *arg)
{
	int	i;

	i = -1;
	if (!arg || *arg == 0)
		error_ret(NULL, "Arguments cannot be blank");
	while (arg[++i])
	{
		if (arg[i] < 48 || arg[i] > 57)
			error_ret(NULL, "Arguments must be unsigned integers");
	}
}

long	get_current_time(t_mother *mother)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		error_ret(mother, "gettimeofday failure");
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	free_all(t_mother *mother)
{
	if (mother)
	{
		if (mother->philo)
			free(mother->philo);
		if (mother->forks)
			free(mother->forks);
	}
}

void	error_ret(t_mother *mother, char *msg)
{
	free_all(mother);
	printf("\e[1;31m%s\n\e[0m", msg);
	exit(1);
}
