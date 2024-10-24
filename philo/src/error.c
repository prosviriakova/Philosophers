/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:55:09 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/24 15:08:24 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_exit_full(t_data *data, char *msg)
{
	printf("%s\n", msg);
	if (data)
	{
		destroy_mutexes(data);
		clean_up(data);
	}
	exit(EXIT_FAILURE);
}

void	error_exit(t_data *data, char *msg)
{
	printf("%s\n", msg);
	if (data)
		clean_up(data);
	exit(EXIT_FAILURE);
}
