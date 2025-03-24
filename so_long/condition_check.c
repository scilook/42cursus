/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:39:24 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/24 17:41:25 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	**copied_map(t_set *set)
{
	size_t	**copied;
	int		i;

	copied = (size_t **)malloc(sizeof(size_t *) * set->y);
	if (!copied)
		return (NULL);
	i = 0;
	while (i < set->y)
	{
		copied[i] = (size_t *)malloc(sizeof(size_t) * set->x);
		if (!copied[i])
		{
			while (i > 0)
				free(copied[--i]);
			free(copied);
			return (NULL);
		}
		ft_bzero(copied[i], sizeof(size_t) * set->x);
		i++;
	}
	return (copied);
}

static int	periodic_func(size_t i)
{
	if (i == 0)
		return (-1);
	else if (i == 1)
		return (0);
	else if (i == 2)
		return (1);
	else if (i == 3)
		return (0);
	else if (i == 4)
		return (-1);
	return (0);
}

static size_t	around_search(t_set *set, t_queue *queue, \
t_point *current, size_t **copied)
{
	int		x;
	int		y;
	size_t	i;
	size_t	found;

	i = 0;
	found = 0;
	while (i < 4)
	{
		x = current->x + periodic_func(i + 1);
		y = current->y + periodic_func(i);
		if (set->map[y][x] == 'E')
			found++;
		else if (set->map[y][x] != '1' && !copied[y][x])
		{
			copied[y][x] = '1';
			enqueue_point(queue, x, y);
		}
		i++;
	}
	return (found);
}

static void	bfs_func(t_set *set, t_queue *queue, size_t **copied, int *var)
{
	t_point	*current;

	while (queue->size > 0)
	{
		current = dequeue_point(queue);
		if (!current)
			break ;
		if (set->map[current->y][current->x] == 'C')
			var[1]++;
		if (around_search(set, queue, current, copied))
			var[0]++;
		free(current);
	}
}

void	condition_check(t_set *set)
{
	t_queue	*queue;
	size_t	**copied;
	int		var[3];

	var[0] = 0;
	var[1] = 0;
	queue = init_queue();
	if (!queue)
		if_ret(1, set);
	copied = copied_map(set);
	if (!copied)
	{
		free_queue(queue);
		if_ret(1, set);
	}
	enqueue_point(queue, set->p_x, set->p_y);
	copied[set->p_y][set->p_x] = '1';
	bfs_func(set, queue, copied, var);
	free_queue(queue);
	var[2] = 0;
	while (var[2] < set->y)
		free(copied[var[2]++]);
	free(copied);
	if (var[0] != set->e || var[1] != set->c)
		if_ret(1, set);
}
