/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:17:10 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/23 19:02:36 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	sim_finished(t_data *data)
{
	return (get_bool(&data->treads_mutex, &data->end_simulation));
}

void	wait_all_threads(t_data *data)
{
	while (!get_bool(&data->treads_mutex, &data->treads_ready))
		usleep(100);
}

void	print_status(t_philo *philo, char *status)
{
	long	timestamp;

	pthread_mutex_lock(&philo->data->print_mutex);
	if (!sim_finished(philo->data) || ft_strcmp(status, "died") == 0)
	{
		timestamp = current_time() - philo->data->start_time;
		printf("%ld %d %s\n", timestamp, philo->id, status);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}

int	finish_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	if (data->num_philos > 1)
	{
		if (pthread_join(data->monitor_thread, NULL) != 0)
			return (1);
	}
	return (0);
}

int	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, philosopher_routine,
				&data->philos[i]) != 0)
			return (1);
		i++;
	}
	data->start_time = current_time();
	set_bool(&data->treads_mutex, &data->treads_ready, true);
	if (data->num_philos > 1)
	{
		if (pthread_create(&data->monitor_thread, NULL, &monitor_routine,
				data) != 0)
			return (1);
	}
	return (0);
}
