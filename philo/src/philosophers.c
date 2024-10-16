/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:17:15 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/16 13:27:41 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*single(t_philo *philosopher, t_data *data)
{
	pthread_mutex_lock(philosopher->left_fork);
	print_status(philosopher, "has taken a fork");
	usleep(data->time_to_die * 1000);
	print_status(philosopher, "died");
	pthread_mutex_unlock(philosopher->left_fork);
	return (NULL);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philosopher;
	t_data	*data;

	philosopher = (t_philo *)arg;
	data = philosopher->data;
	if (data->num_philosophers == 1)
		return (single(philosopher, data));
	print_status(philosopher, "is thinking");
	usleep(2000);
	print_status(philosopher, "is eating");
	usleep(data->time_to_eat * 1000);
	print_status(philosopher, "is sleeping");
	usleep(data->time_to_sleep * 1000);
	return (NULL);
}

int	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_timestamp_in_ms();
	while (i < data->num_philosophers)
	{
		if (pthread_create(&data->philos[i].thread, NULL, philosopher_routine, &data->philos[i]) != 0)
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
