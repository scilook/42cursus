/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:57:27 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/25 18:56:52 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_queue	*init_queue(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
	return (queue);
}

void	enqueue_point(t_queue *queue, int x)
{
	int		*point;
	t_list	*node;

	point = (int *)malloc(sizeof(int));
	if (!point)
		return ;
	*point = x;
	node = ft_lstnew(point);
	if (!node)
	{
		free(point);
		return ;
	}
	if (queue->rear == NULL)
	{
		queue->front = node;
		queue->rear = node;
	}
	else
	{
		queue->rear->next = node;
		queue->rear = node;
	}
	queue->size++;
}

int	*dequeue_point(t_queue *queue)
{
	t_list	*tmp;
	int		*point;

	if (!queue || !queue->front)
		return (NULL);
	tmp = queue->front;
	point = tmp->content;
	queue->front = queue->front->next;
	if (queue->front == NULL)
		queue->rear = NULL;
	free(tmp);
	queue->size--;
	return (point);
}

void	free_queue(t_queue *queue)
{
	int	*point;

	if (!queue)
		return ;
	while (queue->size > 0)
	{
		point = dequeue_point(queue);
		if (point)
			free(point);
	}
	free(queue);
}
