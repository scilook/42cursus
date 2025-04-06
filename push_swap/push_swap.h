/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:39:53 by hyeson            #+#    #+#             */
/*   Updated: 2025/04/04 16:37:34 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct s_queue
{
	t_list	*front;
	t_list	*rear;
	int		size;
}			t_queue;

t_queue		*init_queue(void);
void		enqueue_point(t_queue *queue, int x);
void		enqueue_point_head(t_queue *queue, int x);
int			*dequeue_point(t_queue *queue);
int			*dequeue_point_rear(t_queue *queue);
int			rank_queue(t_queue *queue);
void		free_queue(t_queue *queue);
void		radix_sort(t_queue *queue0, t_queue *queue1);
void		under6_sort(t_queue *queue0, t_queue *queue1);
void		under3_sort_a(t_queue *queue);

#endif /* PUSH_SWAP_H */