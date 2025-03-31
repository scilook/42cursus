/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:39:53 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/31 17:18:07 by hyeson           ###   ########.fr       */
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
}	t_queue;

t_queue	*init_queue(void);
void	enqueue_point(t_queue *queue, int x);
int		*dequeue_point(t_queue *queue);
void	free_queue(t_queue *queue);
void	rank_queue(t_queue *queue);
void	if_ret(int bool, t_queue *queue);
void	radix_sort(t_queue *queue0, t_queue *queue1);
void	queue_traversal(t_queue *queue, t_queue *queue0, \
t_queue *queue1, int size);

#endif /* PUSH_SWAP_H */