/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:39:53 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/25 18:57:30 by hyeson           ###   ########.fr       */
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

#endif /* PUSH_SWAP_H */