/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:50:01 by oprosvir          #+#    #+#             */
/*   Updated: 2024/08/16 01:17:54 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int parse_arguments(int argc, char **argv, int *num_philosophers, int *time_to_die, int *time_to_eat, int *time_to_sleep)
{
    if (argc < 5 || argc > 6)
    {
        printf("Usage: %s num_philosophers time_to_die time_to_eat time_to_sleep [num_times_each_philosopher_must_eat]\n", argv[0]);
        return (1);
    }
    *num_philosophers = atoi(argv[1]);
    *time_to_die = atoi(argv[2]);
    *time_to_eat = atoi(argv[3]);
    *time_to_sleep = atoi(argv[4]);
    return (0);
}

int main(int argc, char **argv)
{
    int num_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;

    if (parse_arguments(argc, argv, &num_philosophers, &time_to_die, &time_to_eat, &time_to_sleep))
        return (1);

    start_simulation(num_philosophers, time_to_die, time_to_eat, time_to_sleep);

    return (0);
}
