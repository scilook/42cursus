/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:28:12 by hyeson            #+#    #+#             */
/*   Updated: 2025/09/20 16:54:58 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	state_print(t_philo *philo, char *state)
{
	if (is_activate(philo->units))
	{
		pthread_mutex_lock(philo->units->print_lock);
		printf("%ld %ld %s\n", (get_now() - philo->units->init_time)
			/ 1000, philo->num, state);
		pthread_mutex_unlock(philo->units->print_lock);
	}
}

int	is_activate(t_units *units)
{
	int	bool;

	pthread_mutex_lock(units->activate_lock);
	bool = units->activate;
	pthread_mutex_unlock(units->activate_lock);
	return (bool);
}

void	not_activate(t_units *units)
{
	pthread_mutex_lock(units->activate_lock);
	units->activate = !units->activate;
	pthread_mutex_unlock(units->activate_lock);
}

suseconds_t	get_time(const suseconds_t *time, pthread_mutex_t *lock)
{
	suseconds_t	getter;

	pthread_mutex_lock(lock);
	getter = *time;
	pthread_mutex_unlock(lock);
	return (getter);
}

void	set_time(suseconds_t *old, suseconds_t new, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	*old = new;
	pthread_mutex_unlock(lock);
}
