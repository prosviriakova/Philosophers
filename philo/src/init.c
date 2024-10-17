/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 23:52:42 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/18 01:36:04 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->num_philosophers);
	if (!data->philos)
		return (1);
	while (i < data->num_philosophers)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = 0;
		data->philos[i].first_fork = &data->forks[(i + 1) % data->num_philosophers];
		data->philos[i].second_fork = &data->forks[i];
		if (i % 2 == 0)  // even ones are left-handed
		{
			data->philos[i].first_fork = &data->forks[i];
			data->philos[i].second_fork = &data->forks[(i + 1) % data->num_philosophers];
		}
		data->philos[i].data = data;
		i++;
	}
	return (0);
}

static int	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
	if (!data->forks)
		return (1);
	while (i < data->num_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			data->num_philosophers = i;
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (1);
	return (0);
}

void	init_data(t_data *data, char **argv)
{
	data->forks = NULL;
	data->philos = NULL;
	data->num_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->all_alive = 1;
	data->start_time = 0;
	if (argv[5])
		data->must_eat_count = ft_atoi(argv[5]);
	else
		data->must_eat_count = -1;
	if (init_mutexes(data) != 0 || init_philos(data) != 0)
		error_exit(data, "Error initializing data.");
}