/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:50:01 by oprosvir          #+#    #+#             */
/*   Updated: 2024/08/22 23:55:06 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	validate_input(int argc, char **argv)
{
	int	i;
	int	j;
	int	value;

	if (argc < 5 || argc > 6)
		error_exit(HELP_MSG);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				error_exit("Arguments must be positive integers.");
			j++;
		}
		value = ft_atoi(argv[i]);
		if (value == 0)
			error_exit("Invalid argument: must be > 0.");
		i++;
	}
}

void	clean_up(t_data *data)
{
	pthread_mutex_t	*current_fork;
	int				count;

	current_fork = data->forks;
	count = data->num_philosophers;
	while (count > 0)
	{
		pthread_mutex_destroy(current_fork);
		current_fork++;
		count--;
	}
	free(data->forks);
	free(data->philos);
}

int	main(int argc, char **argv)
{
	t_data	data;

	validate_input(argc, argv);
	init_data(&data, argv);
	start_simulation(&data);
	clean_up(&data);
	return (0);
}
