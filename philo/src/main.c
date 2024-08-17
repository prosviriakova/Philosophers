/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:50:01 by oprosvir          #+#    #+#             */
/*   Updated: 2024/08/17 16:27:10 by oprosvir         ###   ########.fr       */
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

static void init_philosophers(t_data *data)
{
	int i;

	i = 0;
    data->philos = malloc(sizeof(t_philo) * data->num_philosophers);
    if (!data->philos)
    {
        error_exit("Error: Memory allocation failed.");
    }
	while (i < data->num_philosophers)
	{
		data->philos[i].id = i + 1;
        i++;
	}
}

static void init_data(t_data *data, char **argv)
{
    data->num_philosophers = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    if (argv[5])
		data->must_eat_count = ft_atoi(argv[5]);
	else
		data->must_eat_count = -1;
    init_philosophers(data);
}


void clean_up(t_data *data)
{
    // Free all allocated memory, destroy mutexes, etc.
    free(data->philos);
}

int	main(int argc, char **argv)
{
    t_data  data;

	validate_input(argc, argv);
    init_data(&data, argv);
	start_simulation(&data);
    clean_up(&data);
	return (0);
}
