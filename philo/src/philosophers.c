/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:17:15 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/16 03:49:48 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)arg;
	print_status(philosopher, "is thinking");
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
	pthread_mutex_destroy(&data->print_mutex);
	return (0);
}
