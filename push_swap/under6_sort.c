/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under6_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:34:26 by hyeson            #+#    #+#             */
/*   Updated: 2025/04/04 18:47:57 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	under3_sort_a(t_queue *queue)
{
	int	*tmp;
	int	*tmp2;

	while (queue->size)
	{
		if (*(int *)queue->front->content == 1
			&& *(int *)queue->rear->content == queue->size)
			return ;
		tmp = dequeue_point(queue);
		if (*tmp == 2 && *(int *)queue->rear->content == 3)
		{
			tmp2 = dequeue_point(queue);
			enqueue_point_head(queue, *tmp);
			enqueue_point_head(queue, *tmp2);
			free(tmp);
			free(tmp2);
			ft_printf("sa\n");
			return ;
		}
		ft_printf("ra\n");
		enqueue_point(queue, *tmp);
		free(tmp);
	}
}

void	under3_sort_b(t_queue *queue)
{
	int	*tmp;
	int	*tmp2;

	while (queue->size)
	{
		if (*(int *)queue->front->content == 1
			&& *(int *)queue->rear->content == queue->size)
			return ;
		tmp = dequeue_point_rear(queue);
		if (*tmp == 2 && *(int *)queue->rear->content == 3)
		{
			tmp2 = dequeue_point(queue);
			enqueue_point_head(queue, *tmp);
			enqueue_point_head(queue, *tmp2);
			free(tmp);
			free(tmp2);
			ft_printf("sb\n");
			return ;
		}
		ft_printf("rb\n");
		enqueue_point_head(queue, *tmp);
		free(tmp);
	}
}

static void	queue_division(t_queue *queue0, t_queue *queue1)
{
	int	toss;
	int	i;
	int	*tmp;

	toss = queue0->size >> 1;
	i = 0;
	while (i < toss)
	{
		tmp = dequeue_point(queue0);
		if (*tmp <= toss)
		{
			ft_printf("pb\n");
			enqueue_point(queue1, *tmp);
			i++;
		}
		else
		{
			ft_printf("ra\n");
			enqueue_point(queue0, *tmp);
		}
		free(tmp);
	}
}

void	under6_sort(t_queue *queue0, t_queue *queue1)
{
	int	*tmp;

	if (queue0->size > 3)
		queue_division(queue0, queue1);
	rank_queue(queue0);
	under3_sort_a(queue0);
	under3_sort_b(queue1);
	while (queue1->size)
	{
		tmp = dequeue_point(queue1);
		enqueue_point(queue0, *tmp);
		ft_printf("pa\n");
		free(tmp);
	}
}
