/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 23:52:42 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/15 00:44:59 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		data->philos[i].id = i + 1;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philosophers];
		i++;
	}
}

static void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			data->num_philosophers = i;
			error_exit(data, "Error: Mutex initialization failed.");
		}
		i++;
	}
}

void	init_data(t_data *data, char **argv)
{
	memset(data, 0, sizeof(t_data));
	data->num_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->must_eat_count = ft_atoi(argv[5]);
	else
		data->must_eat_count = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
	data->philos = malloc(sizeof(t_philo) * data->num_philosophers);
	if (!data->philos || !data->forks)
		error_exit(data, "Error: Memory allocation failed.");
	init_forks(data);
	init_philos(data);
}