/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:17:10 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/21 17:40:39 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int finish_simulation(t_data *data)
{
    int i;

    i = 0;
    while (i < data->num_philosophers)
    {
        if (pthread_join(data->philos[i].thread, NULL) != 0)
            return (1);
        i++;
    }
    if (data->num_philosophers > 1)
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
	data->start_time = current_time();
	while (i < data->num_philosophers)
	{
		data->philos[i].last_meal_time = data->start_time;
		if (pthread_create(&data->philos[i].thread, NULL, philosopher_routine,
				&data->philos[i]) != 0)
			return (1);
		i++;
	}
	if (data->num_philosophers > 1)
	{
		if (pthread_create(&data->monitor_thread, NULL, &monitor_routine, data) != 0)
			return (1);
	}
	return (0);
}