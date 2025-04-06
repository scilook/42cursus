/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:48:17 by hyeson            #+#    #+#             */
/*   Updated: 2025/04/06 14:02:34 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	queue_traversal(t_queue *queue0, t_queue *queue1)
{
	int	*tmp;
	int	size;

	size = queue0->size;
	while (size--)
	{
		tmp = dequeue_point(queue0);
		if (*tmp % 2)
		{
			enqueue_point(queue0, *tmp >> 1);
			ft_printf("ra\n");
		}
		else
		{
			enqueue_point_head(queue1, *tmp >> 1);
			ft_printf("pb\n");
		}
		free(tmp);
	}
}

void	radix_sort(t_queue *queue0, t_queue *queue1)
{
	int	size;
	int	*tmp;

	size = queue0->size;
	while (size)
	{
		queue_traversal(queue0, queue1);
		while (queue1->size)
		{
			tmp = dequeue_point(queue1);
			enqueue_point_head(queue0, *tmp);
			free(tmp);
			ft_printf("pa\n");
		}
		size = size >> 1;
	}
}
