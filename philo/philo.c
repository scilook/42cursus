/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:18:19 by hyeson            #+#    #+#             */
/*   Updated: 2025/05/07 18:02:43 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*thr_start(t_philo *philo)
{
	struct timeval	tv1;
	struct timeval	tv2;
	
	if (philo + 1)
	{
		pthread_mutex_lock(philo->mutex);
		pthread_mutex_lock((philo + 1)->mutex);
	}
	else
	{
		pthread_mutex_lock(philo->mutex);
		while (philo->num)
			philo = philo - 1;
		pthread_mutex_lock(philo->mutex);
	}
	philo->dur = 0;
	gettimeofday(&tv1, NULL);
	while (philo->dur < philo->time->to_die)
	{
		gettimeofday(&tv2, NULL);
		philo->dur = (tv2.tv_sec - tv1.tv_sec) * 1000 * 1000 \
		+ (tv2.tv_usec - tv1.tv_usec);
	}
}


t_time	*get_time(char **argv)
{
	t_time	*time;

	time = (t_time *)malloc(sizeof(t_time));
	time->to_die = ft_atoi(argv[2]) * 1000;
	time->to_eat = ft_atoi(argv[3]) * 1000;
	time->to_sleep = ft_atoi(argv[4]) * 1000;
	return (time);
}

t_philo	**init_philos(t_philo **philos, t_time *time, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		pthread_mutex_init(philos[i]->mutex, NULL);
		philos[i]->num = i;
		philos[i]->time = time;
		i++;
	}
	return (philos);
}

int	main(int argc, char *argv[])
{
	size_t	i;
	size_t	size;
	t_time	*time;
	t_philo	**philos;

	if (!(argc == 5 || argc == 6))
		return (0);
	size = ft_atoi(argv[1]);
	philos = (t_philo **)ft_calloc(sizeof(t_philo *), size + 1);
	if (!philos)
		return(0);
	time = get_time(argv);
	philos = init_philos(philos, time, size);
	i = 0;
	while (i < size)
	{
		pthread_create(philos[i]->thr, NULL, thr_start, philos[i]);
		i++;
	}
}
