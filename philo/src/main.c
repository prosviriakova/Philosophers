/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:50:01 by oprosvir          #+#    #+#             */
/*   Updated: 2024/08/17 15:09:10 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	parse_arguments(char **argv, int *num_philosophers, t_philo *philos)
{
	int	i;

	*num_philosophers = ft_atoi(argv[1]);
	for (i = 0; i < *num_philosophers; i++)
	{
		philos[i].id = i + 1;
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].time_to_eat = ft_atoi(argv[3]);
		philos[i].time_to_sleep = ft_atoi(argv[4]);
	}
	return (0);
}

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
		if (value <= 0)
			error_exit("Invalid argument: must be > 0.");
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_philo	*philos;
	int		num_philosophers;

	validate_input(argc, argv);
	num_philosophers = ft_atoi(argv[1]);
	philos = (t_philo *)malloc(sizeof(t_philo) * num_philosophers);
	if (!philos)
		error_exit("Memory allocation failed!");
	if (parse_arguments(argv, &num_philosophers, philos))
	{
		free(philos);
		return (1);
	}
	start_simulation(num_philosophers, philos);
	free(philos);
	return (0);
}
