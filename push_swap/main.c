/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:36:30 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/31 17:27:12 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	validation_check(char *nbrj, t_queue *queue)
{
	char	*tmp;
	int		k;

	k = 0;
	if (nbrj[k] == '+' || nbrj[k] == '-')
		k++;
	while (nbrj[k] == '0')
		k++;
	if_ret(ft_strlen(nbrj + k) > 16, queue);
	while (nbrj[k])
		if_ret(!ft_isdigit(nbrj[k++]), queue);
	tmp = ft_itoa(ft_atoi(nbrj));
	if (!ft_strnstr(nbrj, tmp, ft_strlen(nbrj))) // -07 등을 어떻게 처리하나
	{
		free(tmp);
		free_queue(queue);
		ft_printf("Error\n");
		exit(0);
	}
	free(tmp);
}

static void	allocate_queue(char *argv[], t_queue *queue)
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
			validation_check(nbr[j], queue);
			enqueue_point(queue, ft_atoi(nbr[j]));
			free(nbr[j]);
			j++;
		}
		free(nbr);
	}
}

//나중에 지워라
void test_print(t_queue *queue)
{
	int *a = dequeue_point(queue);

	while (a)
	{
		ft_printf("%d\n", *a);
		free(a); //사용후 free
		a = dequeue_point(queue);
	}
}


	// 같은 값 확인 >> 유효성 검사
	// 목표 생성
	// 자릿값 정렬을 통해 1. 크기 할당 및 2. push_swap 수행
int	main(int argc, char *argv[])
{
	t_queue	*queue0;
	t_queue	*queue1;

	queue0 = init_queue();
	queue1 = init_queue();
	allocate_queue(argv, queue0);
	rank_queue(queue0);
	radix_sort(queue0, queue1);
	queue_traversal(queue1, queue0, queue1, queue1->size);
	free_queue(queue0);
	free_queue(queue1);
}