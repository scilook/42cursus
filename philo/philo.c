/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:18:19 by hyeson            #+#    #+#             */
/*   Updated: 2025/06/30 20:45:08 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thinking_time(t_philo *philo, suseconds_t start)
{
	struct timeval	tv;
	suseconds_t		duration;
	size_t			catch;

	catch = 0;
	duration = 0;
	while (duration < philo->units->time_to_die && !philo->units->death)
	{
		if (!pthread_mutex_lock(philo->fork))
		{
			gettimeofday(&tv, NULL);
			duration = tv.tv_sec * 1000 * 1000 + tv.tv_usec - start;
			printf("%ld %ld has taken a fork\n", duration / 1000, philo->num);
			catch++;
		}
		if (!pthread_mutex_lock(philo->r_fork))
		{
			gettimeofday(&tv, NULL);
			duration = tv.tv_sec * 1000 * 1000 + tv.tv_usec - start;
			printf("%ld %ld has taken a fork\n", duration / 1000, philo->num);
			catch++;
		}
		if (catch == 2)
		{
			gettimeofday(&tv, NULL);
			duration = tv.tv_sec * 1000 * 1000 + tv.tv_usec - start;
			printf("%ld %ld is thinking\n", duration / 1000, philo->num);
			return (0);
		}
	}
	return (1);
}

void	eating_time(t_philo *philo, suseconds_t start)
{
	struct timeval	tv;
	suseconds_t		duration;

	usleep(philo->units->time_to_eat);
	gettimeofday(&tv, NULL);
	duration = tv.tv_sec * 1000 * 1000 + tv.tv_usec - start;
	printf("%ld %ld is eating\n", duration / 1000, philo->num);
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleeping_time(t_philo *philo, suseconds_t start)
{
	struct timeval	tv;
	suseconds_t		duration;

	if (philo->units->time_to_sleep < philo->units->time_to_die)
	usleep(philo->units->time_to_sleep);
	else
	{
		usleep(philo->units->time_to_die);
		return ;
	}
	gettimeofday(&tv, NULL);
	duration = tv.tv_sec * 1000 * 1000 + tv.tv_usec - start;
	printf("%ld %ld is sleeping\n", duration / 1000, philo->num);
}

/* static void	*monitoring(void *arg)
{
	size_t	i;
	t_philo	**philos;

	philos = arg;
	i = 0;
	while(i < philos[i]->units->size)
	{
		pthread_detach(philos[i]->thr);
		i++;
	}
	if (philos[i]->units->death)
	everyone_is_death(philos);
	return (philos);
} */

void	*thr_start(void *arg)
{
	t_philo			*philo;
	suseconds_t		start;
	struct timeval	tv;
	struct timeval	tv2;
	
	philo = (t_philo *)arg;
	gettimeofday(&tv, NULL);
	start = tv.tv_sec * 1000 * 1000 + tv.tv_usec;
	philo->dur = 0;
	while (philo->dur < philo->units->time_to_die && !philo->units->death)
	{	
		if (thinking_time(philo, start))
			break ;
		eating_time(philo, start);
		gettimeofday(&tv, NULL);
		sleeping_time(philo, start);
		gettimeofday(&tv2, NULL);
		philo->dur = (tv2.tv_sec - tv.tv_sec) * 1000 * 1000 \
		+ (tv2.tv_usec - tv.tv_usec);
	}
	philo->units->death = 1;
	printf("%ld is died\n", philo->num);
	return (philo);
}

t_units	*get_units(int argc, char **argv)
{
	t_units	*units;

	units = (t_units *)malloc(sizeof(t_units));
	units->size = ft_atoi(argv[1]);
	units->time_to_die = ft_atoi(argv[2]) * 1000;
	units->time_to_eat = ft_atoi(argv[3]) * 1000;
	units->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		units->must_eat = ft_atoi(argv[5]);
	units->death = 0;
	return (units);
}

t_philo	**init_philos(t_philo **philos, t_units *units)
{
	size_t	i;

	i = 0;
	while (i < units->size)
	{
		philos[i] = malloc(sizeof(t_philo));
		philos[i]->fork = malloc(sizeof(pthread_mutex_t));
		philos[i]->r_fork = malloc(sizeof(pthread_mutex_t));
		philos[i]->units = malloc(sizeof(t_units));
		pthread_mutex_init(philos[i]->fork, NULL);
		philos[i]->num = i + 1;
		philos[i]->units = units;
		i++;
	}
	i = 0;
	while (i < units->size)
	{
		philos[i]->r_fork = philos[(i + 1) % units->size]->fork;
		i++;
	}
	return (philos);
}

int	main(int argc, char *argv[])
{
	size_t		i;
	//pthread_t	monitor;
	t_units		*units;
	t_philo		**philos;

	if (!(argc == 5 || argc == 6))
		return (0);
	i = 0;
	units = get_units(argc, argv);
	philos = (t_philo **)malloc(sizeof(t_philo *) * (units->size));
	philos = init_philos(philos, units);
	//pthread_join(monitor, NULL);
	i = 0;
	while (i < units->size)
	{
		pthread_create(&philos[i]->thr, NULL, thr_start, philos[i]);
		i++;
	}
	i = 0;
	while (i < units->size)
	{
		pthread_join(philos[i]->thr, NULL);
		i++;
	}
	//pthread_create(&monitor, NULL, &monitoring, philos);
}
