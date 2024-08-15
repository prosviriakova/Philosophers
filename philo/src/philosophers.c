/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:17:15 by oprosvir          #+#    #+#             */
/*   Updated: 2024/08/16 01:24:25 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philosopher_routine(void *arg)
{
    t_philosopher *philosopher = (t_philosopher *)arg;

    //TODO: Philosopher's actions (thinking, eating, sleeping)
    printf("Philosopher %d is thinking...\n", philosopher->id);

    return (NULL);
}

void start_simulation(int num_philosophers, int time_to_die, int time_to_eat, int time_to_sleep)
{
    t_philosopher philosophers[num_philosophers];
    int i;
    
    //TODO
    (void)time_to_die;
    (void)time_to_eat;
    (void)time_to_sleep;

    for (i = 0; i < num_philosophers; i++)
    {
        philosophers[i].id = i + 1;
        pthread_create(&philosophers[i].thread, NULL, philosopher_routine, &philosophers[i]);
    }

    for (i = 0; i < num_philosophers; i++)
    {
        pthread_join(philosophers[i].thread, NULL);
    }
}
