/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:51:24 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/28 16:38:49 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define HELP_MSG	"Usage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]"

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				philo_ready;
	int				philo_full;
	long			start_time;
	bool			treads_ready;
	bool			end_simulation;
	pthread_t		monitor_thread;
	pthread_mutex_t	treads_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	eat_mutex;
	t_philo			*philos;
}					t_data;

// simulation
int					start_simulation(t_data *data);
int					finish_simulation(t_data *data);
bool				threads_ready(pthread_mutex_t *mutex, int *threads,
						int philo_nbr);
bool				sim_finished(t_data *data);

// utility
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
long				current_time(void);
void				sleep_ms(long duration, t_data *data);
void				print_status(t_philo *philosopher, char *status);
void				destroy_mutexes(t_data *data);
void				clean_up(t_data *data);
void				error_exit(t_data *data, char *msg);
void				error_exit_full(t_data *data, char *msg);
void				init_data(t_data *data, char **argv);
void				increase_int(pthread_mutex_t *mutex, int *value);

// thread
void				*philosopher_routine(void *arg);
void				*monitor_routine(void *arg);
void				wait_all_threads(t_data *data);

// getters and setters
void				set_bool(pthread_mutex_t *mutex, bool *dest, bool value);
void				set_long(pthread_mutex_t *mutex, long *dest, long value);
bool				get_bool(pthread_mutex_t *mutex, bool *value);
long				get_long(pthread_mutex_t *mutex, long *value);

#endif