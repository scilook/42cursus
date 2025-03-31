/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:48:17 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/31 17:26:00 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	queue_traversal(t_queue *queue, t_queue *queue0, \
t_queue *queue1, int size)
{
	int	*tmp;

	while (size--)
	{
		tmp = dequeue_point(queue);
		if (*tmp % 2)
		{
			enqueue_point(queue1, *tmp >> 1);
			if (queue == queue0)
				ft_printf("pb\nrb\n");
			else
				ft_printf("rb\n");
		}
		else
		{
			enqueue_point(queue0, *tmp >> 1);
			if (queue == queue0)
				ft_printf("ra\n");
			else
				ft_printf("pa\nra\n");
		}	
		free(tmp);
	}
}


static void	stage_queue(t_queue *queue0, t_queue *queue1)
{
	int	size[2];

	size[0] = queue0->size;
	size[1] = queue1->size;
	queue_traversal(queue0, queue0, queue1, size[0]);
	queue_traversal(queue1, queue0, queue1, size[1]);
}

void	radix_sort(t_queue *queue0, t_queue *queue1)
{
	int	size;

	size = queue0->size;
	while (size)
	{
		stage_queue(queue0, queue1);
		size = size >> 1;
	}
}
