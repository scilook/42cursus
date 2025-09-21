/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:15:52 by hyeson            #+#    #+#             */
/*   Updated: 2025/09/21 11:49:33 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_units
{
	size_t			size;
	size_t			activate;
	size_t			must_eat;
	suseconds_t		init_time;
	suseconds_t		time_to_die;
	suseconds_t		time_to_eat;
	suseconds_t		time_to_sleep;
	pthread_mutex_t	*activate_lock;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*start_lock;
	pthread_mutex_t	*cnt_lock;
}	t_units;

typedef struct s_philo
{
	size_t			num;
	size_t			cnt;
	size_t			checked;
	suseconds_t		dur;
	suseconds_t		start_time;
	pthread_t		thr;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_units			*units;
}	t_philo;

suseconds_t	get_now(void);
suseconds_t	get_time(const suseconds_t *time, pthread_mutex_t *lock);
void		set_time(suseconds_t *old, suseconds_t new, pthread_mutex_t *lock);
void		*thr_start(void *arg);
void		state_print(t_philo *philo, char *state);
void		dying_msg(t_philo *philo);
void		not_activate(t_units *units);
int			is_activate(t_units *units);
int			ft_atoi(const char *s);
void		size_up(size_t *old, pthread_mutex_t *lock);
void		memory_clean(t_philo **philos, t_units *units);
size_t		get_size(const size_t *size, pthread_mutex_t *lock);

#endif /* PHILO_H */