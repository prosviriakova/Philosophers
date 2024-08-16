/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:17:15 by oprosvir          #+#    #+#             */
/*   Updated: 2024/08/16 23:49:58 by oprosvir         ###   ########.fr       */
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

void start_simulation(int num_philosophers, t_philo *philos)
{
    int i;

    for (i = 0; i < num_philosophers; i++)
        pthread_create(&philos[i].thread, NULL, philosopher_routine, &philos[i]);

    for (i = 0; i < num_philosophers; i++)
        pthread_join(philos[i].thread, NULL);
}
