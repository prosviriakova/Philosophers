/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:50:01 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/15 00:43:45 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	validate_input(int argc, char **argv)
{
	int	i;
	int	value;

	if (argc < 5 || argc > 6)
		error_exit(NULL, HELP_MSG);
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (value == 0)
			error_exit(NULL, "Invalid argument.");
		i++;
	}
}

void	clean_up(t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->num_philosophers)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
		data->forks = NULL;
	}
	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	validate_input(argc, argv);
	init_data(&data, argv);
	if (start_simulation(&data) != 0)
		error_exit(&data, "Error: Failed to create thread.\n");
	clean_up(&data);
	return (EXIT_SUCCESS);
}
