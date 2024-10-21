/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:17:15 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/21 18:44:30 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*single(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->first_fork);
	print_status(philo, "has taken a fork");
	sleep_ms(data->time_to_die);
	print_status(philo, "died");
	pthread_mutex_unlock(philo->first_fork);
	return (NULL);
}

static void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->second_fork);
	print_status(philo, "has taken a fork");
}

static void	eat(t_philo *philo, t_data *data)
{
	philo->meals_eaten++;
	philo->last_meal_time = current_time() - data->start_time;
	print_status(philo, "is eating");
	sleep_ms(data->time_to_eat);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	long	thinking_time;

	philo = (t_philo *)arg;
	data = philo->data;
	if (data->num_philosophers == 1)
		return (single(philo, data));
	if (philo->id % 2 == 0)
		sleep_ms(data->time_to_eat / 2);
	while (data->must_eat_count == -1 || philo->meals_eaten < data->must_eat_count)
	{
		take_forks(philo);
		eat(philo, data);
		pthread_mutex_unlock(philo->first_fork);
		pthread_mutex_unlock(philo->second_fork);
		print_status(philo, "is sleeping");
		sleep_ms(data->time_to_sleep);
		print_status(philo, "is thinking");
        thinking_time = (current_time() - philo->last_meal_time) % data->time_to_eat;
        sleep_ms(thinking_time);
	}
	return (NULL);
}
