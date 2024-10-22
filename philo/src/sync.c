/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:03:28 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/22 23:43:58 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(pthread_mutex_t *mutex, bool *value, bool new_value)
{
	SET_VALUE(mutex, value, new_value);
}

void	set_long(pthread_mutex_t *mutex, long *value, long new_value)
{
	SET_VALUE(mutex, value, new_value);
}

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	result;

    GET_VALUE(mutex, value, result);
	return (result);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long result;

    GET_VALUE(mutex, value, result);
	return (result);
}