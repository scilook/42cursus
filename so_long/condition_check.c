/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:39:24 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/23 18:09:34 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	**copied_map(t_set *set)
{
	int	**copied;
	int	i;

	copied = (int **)malloc(sizeof(int *) * set->y);
	if (!copied)
		return (NULL);
	i = 0;
	while (i < set->y)
	{
		copied[i] = (int *)malloc(sizeof(int) * set->x);
		if (!copied[i])
		{
			while (i > 0)
				free(copied[--i]);
			free(copied);
			return (NULL);
		}
		ft_bzero(copied[i], sizeof(int) * set->x);
		i++;
	}
	return (copied);
}

static void	free_visited_map(int **copied, int y)
{
	int i;

	i = 0;
	while (i < y)
		free(copied[i++]);
	free(copied);
}

int	periodic_func(int i)
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
		return (0);
}

static size_t	func(t_set *set, t_queue *queue, t_point *current, int **copied)
{
	int i, x, y;
	size_t found = 0;

	while (queue->size > 0)
	{
		current = dequeue_point(queue);
		if (!current)
			break ;
		if (set->map[current->y][current->x] == 'E')
			found++;
		if (set->map[current->y][current->x] == 'C')
			found++;
		i = 0;
		while (i < 4)
		{
			x = current->x + periodic_func(i + 1);
			y = current->y + periodic_func(i);
			if (x >= 0 && x < set->x && y >= 0 && y < set->y \
				&& set->map[y][x] != '1' && !copied[y][x])
			{
				copied[y][x] = '1';
				enqueue_point(queue, x, y);
			}
			i++;
		}
		free(current);
	}
	return (found);
}

void	condition_check(t_set *set)
{
	t_queue	*queue;
	t_point	*current;
	size_t	found;
	int		**copied;

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
	found = func(set, queue, current, copied);
	free_queue(queue);
	free_visited_map(copied, set->y);
	if (found != set->e + set->c)
		if_ret(1, set);
}

// e랑 c분리