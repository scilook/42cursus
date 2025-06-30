/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:15:52 by hyeson            #+#    #+#             */
/*   Updated: 2025/06/30 20:44:59 by hyeson           ###   ########.fr       */
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
	int				death;
	int				must_eat;
	size_t			size;
	suseconds_t		time_to_die;
	suseconds_t		time_to_eat;
	suseconds_t		time_to_sleep;
}	t_units;


typedef struct	s_philo
{
	size_t			num;
	size_t			cnt;
	suseconds_t		dur;
	pthread_t		thr;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*r_fork;
	t_units			*units;
}	t_philo;

int	ft_atoi(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);

#endif /* PHILO_H */