/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:24:36 by hyeson            #+#    #+#             */
/*   Updated: 2025/09/21 11:49:23 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_units	*get_units(int argc, char **argv, t_units *units)
{
	units->cnt_lock = malloc(sizeof(pthread_mutex_t));
	units->start_lock = malloc(sizeof(pthread_mutex_t));
	units->print_lock = malloc(sizeof(pthread_mutex_t));
	units->activate_lock = malloc(sizeof(pthread_mutex_t));
	units->size = ft_atoi(argv[1]);
	units->activate = 1;
	units->init_time = 0;
	units->time_to_die = ft_atoi(argv[2]) * 1000;
	units->time_to_eat = ft_atoi(argv[3]) * 1000;
	units->time_to_sleep = ft_atoi(argv[4]) * 1000;
	pthread_mutex_init(units->cnt_lock, NULL);
	pthread_mutex_init(units->start_lock, NULL);
	pthread_mutex_init(units->print_lock, NULL);
	pthread_mutex_init(units->activate_lock, NULL);
	if (argc == 6)
		units->must_eat = ft_atoi(argv[5]);
	else
		units->must_eat = -1;
	return (units);
}

t_philo	**init_philos(t_philo **philos, t_units *units)
{
	size_t	i;

	i = 0;
	while (i < units->size)
	{
		philos[i] = malloc(sizeof(t_philo));
		philos[i]->l_fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philos[i]->l_fork, NULL);
		philos[i]->cnt = 0;
		philos[i]->checked = 0;
		philos[i]->start_time = 0;
		philos[i]->dur = 0;
		philos[i]->num = i + 1;
		philos[i]->units = units;
		i++;
	}
	i = 0;
	while (i < units->size)
	{
		philos[i]->r_fork = philos[(i + 1) % units->size]->l_fork;
		i++;
	}
	return (philos);
}

void	monitor_action(t_philo **philos, t_units *units, size_t i, size_t *e)
{
	if (get_time(&philos[i]->start_time, units->start_lock) != 0)
		philos[i]->dur = get_now()
			- get_time(&philos[i]->start_time, units->start_lock);
	if (get_size(&philos[i]->cnt, units->cnt_lock) >= \
		units->must_eat && philos[i]->checked == 0)
	{
		philos[i]->checked = 1;
		(*e)++;
	}
}

void	philos_monitor(t_philo **philos, t_units *units)
{
	size_t	i;
	size_t	enough;

	i = 0;
	enough = 0;
	set_time(&units->init_time, get_now(), units->print_lock);
	pthread_mutex_unlock(units->activate_lock);
	while (philos[i]->dur < units->time_to_die)
	{
		monitor_action(philos, units, i, &enough);
		if (enough == units->size)
			break ;
		if (++i == units->size)
			i = 0;
		usleep(10);
	}
	not_activate(units);
	usleep(1000);
	if (philos[i]->dur >= units->time_to_die)
		printf("%ld %ld died\n", \
			(get_now() - get_time(&units->init_time, \
			units->print_lock)) / 1000, philos[i]->num);
}

int	main(int argc, char *argv[])
{
	size_t		i;
	t_units		*units;
	t_philo		**philos;

	if (!(argc == 5 || argc == 6) || ft_atoi(argv[1]) < 1 || \
		ft_atoi(argv[1]) > 10000 || (argc == 6 && (ft_atoi(argv[5]) < 1)))
		return (1);
	units = (t_units *)malloc(sizeof(t_units));
	units = get_units(argc, argv, units);
	philos = (t_philo **)malloc(sizeof(t_philo *) * (units->size));
	philos = init_philos(philos, units);
	pthread_mutex_lock(units->activate_lock);
	i = 0;
	while (i < units->size)
	{
		pthread_create(&philos[i]->thr, NULL, thr_start, philos[i]);
		i++;
	}
	usleep(1000);
	philos_monitor(philos, units);
	i = 0;
	while (i < units->size)
		pthread_join(philos[i++]->thr, NULL);
	memory_clean(philos, units);
}
