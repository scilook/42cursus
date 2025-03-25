/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:36:30 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/25 20:01:12 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//queue_a에 int argv넣기 과제: 이미 할당 된 큐에 error시 메모리 정리
void	allogate_queue(char *argv[], t_queue *queue)
{
	int		i;
	int		j;
	int		k;
	char	**nbr;

	i = 1;
	while (argv[i])
	{
		nbr = ft_split(argv[i++], ' ');
		j = 0;
		while (nbr[j])
		{
			k = 0;
			while (nbr[j][k])
			{
				if (!ft_isdigit(nbr[j][k++]))
				{
					ft_printf("Error\n");
					exit(0);
				}
			}
			enqueue_point(queue, ft_atoi(nbr[j++]));
		}
	}
}

void	issame(t_queue *queue)
{


}


int	main(int argc, char *argv[])
{
	t_queue	*queue_a;
	t_queue	*queue_b;

	queue_a = init_queue();
	queue_b = init_queue();
	allogate_queue(argv, queue_a);
	issame(queue_a); // 같은 값 확인
}
