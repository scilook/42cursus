/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:36:30 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/27 11:24:35 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	allocate_queue(char *argv[], t_queue *queue)
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
					free_queue(queue);
					ft_printf("Error\n");
					exit(0);
				}
			}
			enqueue_point(queue, ft_atoi(nbr[j++]));
		}
	}
}

	// 같은 값 확인 >> 정렬시 파괴
	// 목표 생성
	// 자릿값 정렬을 통해 1. 크기 할당 및 2. push_swap 수행
int	main(int argc, char *argv[])
{
	t_queue	*queue_a;  //0버킷 항상 dequeue후 어디 넣을지 판단 >> n개 원소 
	t_queue	*queue_b;  //1버킷

	queue_a = init_queue();
	queue_b = init_queue();
	allocate_queue(argv, queue_a);

	int *a = dequeue_point(queue_a);
	while (a)
	{
	ft_printf("%d\n", *a);
	a = dequeue_point(queue_a);
}
}