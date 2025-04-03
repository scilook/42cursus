/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:57:27 by hyeson            #+#    #+#             */
/*   Updated: 2025/04/03 17:02:27 by hyeson           ###   ########.fr       */
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

void	enqueue_point_head(t_queue *queue, int x)
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
		node->next = queue->front;
		queue->front = node;
	}
	queue->size++;
}

int	*dequeue_point(t_queue *queue)
{
	t_list	*tmp;
	int		*point;

	if (queue == NULL || queue->front == NULL)
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

int	*dequeue_point_rear(t_queue *queue)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		*point;

	if (!queue || !queue->front)
		return (NULL);
	tmp = queue->rear;
	tmp2 = queue->front;
	point = tmp->content;
	while (tmp != tmp2->next)
		tmp2 = tmp2->next;
	queue->rear = tmp2;
	free(tmp);
	queue->size--;
	return (point);
}
