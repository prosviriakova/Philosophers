/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:39:44 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/18 20:15:34 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	current_time(void)
{
	struct timeval	tv;
	long			milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (milliseconds);
}

void	sleep_ms(long sleep_time)
{
	long	start_time;

	start_time = current_time();
	while (current_time() - start_time < sleep_time)
		usleep(100);
}

void	print_status(t_philo *philo, char *status)
{
	long	timestamp;

	pthread_mutex_lock(&philo->data->print_mutex);
	timestamp = current_time() - philo->data->start_time;
	printf("%ld %d %s\n", timestamp, philo->id, status);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

int	ft_atoi(const char *str)
{
	long	res;

	res = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		res = res * 10 + (*str - '0');
		if (res > INT_MAX)
			error_exit(NULL, "Error: Integer overflow.");
		str++;
	}
	return ((int)res);
}

void	error_exit(t_data *data, char *msg)
{
	printf("%s\n", msg);
	if (data)
		clean_up(data);
	exit(EXIT_FAILURE);
}
