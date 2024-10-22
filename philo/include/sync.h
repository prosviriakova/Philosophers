/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:32:21 by oprosvir          #+#    #+#             */
/*   Updated: 2024/10/22 23:33:51 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNC_H
# define SYNC_H

# include <pthread.h>
# include <stdbool.h>

// macros for thread-safe data access
# define SET_VALUE(mutex, value_ptr, new_value) \
	pthread_mutex_lock(mutex);                 \
	*(value_ptr) = new_value;                  \
	pthread_mutex_unlock(mutex)

# define GET_VALUE(mutex, value_ptr, result) \
	pthread_mutex_lock(mutex);              \
	result = *(value_ptr);                  \
	pthread_mutex_unlock(mutex)

// getters and setters
void	set_bool(pthread_mutex_t *mutex, bool *value, bool new_value);
void	set_long(pthread_mutex_t *mutex, long *value, long new_value);
bool	get_bool(pthread_mutex_t *mutex, bool *value);
long	get_long(pthread_mutex_t *mutex, long *value);

#endif
