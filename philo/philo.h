/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:15:52 by hyeson            #+#    #+#             */
/*   Updated: 2025/05/07 17:57:30 by hyeson           ###   ########.fr       */
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

typedef struct	s_time
{
	suseconds_t		to_die;
	suseconds_t		to_eat;
	suseconds_t		to_sleep;
}	t_time;

typedef struct	s_philo
{
	size_t			num;
	suseconds_t		dur;
	pthread_t		*thr;
	pthread_mutex_t	*mutex;
	t_time			*time;
}	t_philo;

typedef struct	s_set
{
	t_philo	*philo;
	t_time	*time;
}	t_set;

int	ft_atoi(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);

#endif /* PHILO_H */