/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:59:44 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/22 21:46:45 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_status(t_philo *philo, char *status)
{
    long timestamp;

    pthread_mutex_lock(&philo->data->print_mutex);
    if (philo->data->all_alive || ft_strcmp(status, "died") == 0)
    {
        timestamp = current_time() - philo->data->start_time;
        printf("%ld %d %s\n", timestamp, philo->id, status);
    }
    pthread_mutex_unlock(&philo->data->print_mutex);
}

int check_last_meal(t_philo *philo)
{
    long time_since_last_meal;

    pthread_mutex_lock(&philo->data->eat_mutex);
    time_since_last_meal = current_time() - philo->last_meal_time;
    pthread_mutex_unlock(&philo->data->eat_mutex);
    if (time_since_last_meal >= philo->data->time_to_die)
    {
        philo->data->all_alive = 0;
        return (1);
    }
    return (0);
}

void	*monitor_routine(void *arg)
{
    t_data *data;
    int i;

    data = (t_data *)arg;
    while (data->all_alive)
    {
        i = 0;
        while (i < data->num_philosophers)
        {
            if (check_last_meal(&data->philos[i]))
            {
                print_status(&data->philos[i], "died");
                return NULL;
            }
            i++;
        }
        usleep(1000);
    }
    return (NULL);
}
