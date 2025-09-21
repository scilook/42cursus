/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lock2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 14:32:03 by hyeson            #+#    #+#             */
/*   Updated: 2025/09/20 16:53:21 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_size(const size_t *size, pthread_mutex_t *lock)
{
	size_t	getter;

	pthread_mutex_lock(lock);
	getter = *size;
	pthread_mutex_unlock(lock);
	return (getter);
}

void	size_up(size_t *old, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	*old += 1;
	pthread_mutex_unlock(lock);
}
