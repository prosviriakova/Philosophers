/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:51:24 by oprosvir          #+#    #+#             */
/*   Updated: 2024/08/16 01:12:38 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>  // pthread_xxx
# include <stdio.h>    // printf
# include <stdlib.h>   // malloc, free
# include <string.h>   // memset
# include <sys/time.h> // gettimeofday
# include <unistd.h>   // usleep, write

typedef struct s_philosopher
{
	int			id;
	pthread_t	thread;
}				t_philosopher;

void start_simulation(int num_philosophers, int time_to_die, int time_to_eat, int time_to_sleep);

#endif