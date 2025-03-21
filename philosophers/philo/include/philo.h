/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:28:53 by mpierce           #+#    #+#             */
/*   Updated: 2025/03/18 15:32:03 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>

# define USEMSG "Invalid Arguments\n\e[1;37m<philo no> 1 - 1000\n<time \
to die>\n<time to eat>\n<time to sleep>\n<no of times to eat> (optional)"

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

typedef struct s_philo	t_philo;

typedef struct s_forks
{
	pthread_mutex_t	lock;
	_Atomic bool	on_table;
}	t_forks;

typedef struct s_mother
{
	t_philo			*philo;
	t_forks			*forks;
	pthread_mutex_t	print_lock;
	int				philo_no;
	int				philo_full;
	long			start_time;
	_Atomic bool	finite;
	_Atomic bool	stop;
	_Atomic bool	death;
}	t_mother;

typedef struct s_philo
{
	t_mother		*mother;
	int				philo_index;
	int				eat_no;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	long			since_last;
	pthread_t		tid;
	t_forks			*right_fork;
	t_forks			*left_fork;
	_Atomic bool	full;
}	t_philo;

// Validation //

int		ft_atoi(const char *nptr);
int		validation(char *arg);
int		assign_to_struct(t_mother *mother, int argc, char **argv);

// General Functions //

int		error_ret(t_mother *mother, char *msg, int print);
long	get_current_time(t_mother *mother);
void	free_all(t_mother *mother, int print);

// Thread Functions //

int		create_threads(t_mother *mother);
void	print_msg(t_philo *philo, int msg);
long	time_funcs(t_philo *philo, int mode);
void	ft_usleep(t_philo *philo, long time);
void	eating(t_philo *philo);
int		thread_error(t_mother *mother, char *msg, int i);
void	only_one(t_philo *philo);
int		check_left_fork(t_philo *philo);
int		check_right_fork(t_philo *philo);
void	think_at_start(t_philo *philo);

#endif