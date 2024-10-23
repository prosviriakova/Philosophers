/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:59:44 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/23 19:07:26 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_last_meal(t_philo *philo)
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
		return (1);
	}
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
			if (check_last_meal(&data->philos[i]))
			{
				print_status(&data->philos[i], "died");
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
