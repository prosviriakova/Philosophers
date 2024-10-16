/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:39:44 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/16 03:35:08 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_timestamp_in_ms(void)
{
	struct timeval	tv;
	long			ms;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

void	print_status(t_philo *philosopher, char *status)
{
	t_data	*data;
	long	timestamp;

	data = philosopher->data;
	pthread_mutex_lock(&data->print_mutex);
	timestamp = get_timestamp_in_ms() - data->start_time; 		// Calculate elapsed time
	printf("%ld %d %s\n", timestamp, philosopher->id, status);
	pthread_mutex_unlock(&data->print_mutex);
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
