/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:17:15 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/18 01:40:19 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*single(t_philo *philosopher, t_data *data)
{
	pthread_mutex_lock(philosopher->first_fork);
	print_status(philosopher, "has taken a fork");
	usleep(data->time_to_die * 1000);
	print_status(philosopher, "died");
	pthread_mutex_unlock(philosopher->first_fork);
	return (NULL);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->second_fork);
	print_status(philo, "has taken a fork");
}

void	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	philo->meals_eaten++;
	philo->last_meal_time = get_timestamp_in_ms() - data->start_time;
	print_status(philo, "is eating");
	usleep(data->time_to_eat * 1000);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philosopher;
	t_data	*data;

	philosopher = (t_philo *)arg;
	data = philosopher->data;
	if (data->num_philosophers == 1)
		return (single(philosopher, data));
	while (data->must_eat_count == -1 || philosopher->meals_eaten < data->must_eat_count)
	{
		take_forks(philosopher);
		eat(philosopher);
		pthread_mutex_unlock(philosopher->first_fork);
		pthread_mutex_unlock(philosopher->second_fork);
		print_status(philosopher, "is sleeping");
		usleep(data->time_to_sleep * 1000);
		print_status(philosopher, "is thinking");
	}
	return (NULL);
}

int	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_timestamp_in_ms();
	while (i < data->num_philosophers)
	{
		data->philos[i].last_meal_time = data->start_time;
		if (pthread_create(&data->philos[i].thread, NULL, philosopher_routine,
				&data->philos[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < data->num_philosophers)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
