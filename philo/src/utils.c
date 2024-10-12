/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:39:44 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/12 03:09:58 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
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
