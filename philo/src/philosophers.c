/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:17:15 by oprosvir          #+#    #+#             */
/*   Updated: 2024/08/17 16:17:26 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philosopher_routine(void *arg)
{
    t_philo *philosopher = (t_philo *)arg;

    //TODO: Philosopher's actions (thinking, eating, sleeping)
    printf("Philosopher %d is thinking...\n", philosopher->id);

    return (NULL);
}

void start_simulation(t_data *data)
{
    int i;

    for (i = 0; i < data->num_philosophers; i++)
        pthread_create(&data->philos[i].thread, NULL, philosopher_routine, &data->philos[i]);

    for (i = 0; i < data->num_philosophers; i++)
        pthread_join(data->philos[i].thread, NULL);
}
