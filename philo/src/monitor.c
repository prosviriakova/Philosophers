/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:59:44 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/24 17:19:13 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	t_data	*data;
	long	time_since_last_meal;

	data = philo->data;
	pthread_mutex_lock(&data->eat_mutex);
	time_since_last_meal = current_time() - philo->last_meal_time;
	pthread_mutex_unlock(&data->eat_mutex);
	if (time_since_last_meal >= data->time_to_die)
	{
		set_bool(&data->treads_mutex, &data->end_simulation, true);
		print_status(philo, "died");
		return (1);
	}
	return (0);
}

int	check_full(t_data *data)
{
	if (data->must_eat_count == -1)
		return (0);
	pthread_mutex_lock(&data->eat_mutex);
	if (data->philo_full == data->num_philos)
	{
		set_bool(&data->treads_mutex, &data->end_simulation, true);
		pthread_mutex_unlock(&data->eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->eat_mutex);
	return (0);
}

bool	threads_ready(pthread_mutex_t *mutex, int *threads, int philo_nbr)
{
	bool	result;

	result = false;
	pthread_mutex_lock(mutex);
	if (*threads == philo_nbr)
		result = true;
	pthread_mutex_unlock(mutex);
	return (result);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!threads_ready(&data->treads_mutex, &data->philo_ready,
			data->num_philos))
		usleep(100);
	while (!sim_finished(data))
	{
		i = 0;
		while (i < data->num_philos)
		{
			if (check_death(&data->philos[i]) || check_full(data))
				return (NULL);
			i++;
		}
		usleep(100);
	}
	return (NULL);
}
