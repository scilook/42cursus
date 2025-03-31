/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:12:50 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/31 17:30:46 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	ft_sort_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	j = 0;
	while (++j < size)
	{
		i = j;
		while (i > 0)
		{
			tmp = tab[i];
			if (tmp < tab[i - 1])
			{
				tab[i] = tab[i - 1];
				tab[i - 1] = tmp;
			}
			i--;
		}
	}
}

void	free_data(int **contents, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(contents[i++]);
	free(contents);
	free(tab);
}

int	sequence_check(int **contents, int *tab, int size, t_queue *queue)
{
	int	var[3];

	var[0] = 0;
	var[2] = 0;
	while (var[0] < size)
	{
		if (var[0] + 1 != size && tab[var[0]] == tab[var[0] + 1])
		{
			ft_printf("Error\n");
			free_data(contents, tab, size);
			free_queue(queue);
			exit(0);
		}
		var[1] = 0;
		while (var[1] < size)
		{
			if (tab[var[1]] == *contents[var[0]])
			{
				if (var[0] == var[1])
					var[2]++;
				enqueue_point(queue, ++var[1]);
				break ;
			}
			var[1]++;
		}
		var[0]++;
	}
	return (var[2]);
}


void	rank_queue(t_queue *queue)
{
	int	**contents;
	int	*tab;
	int	size;
	int	k;

	contents = (int **)malloc(sizeof(int *) * queue->size);
	tab = (int *)malloc(sizeof(int) * queue->size);
	size = 0;
	while (queue->size)
	{
		contents[size] = dequeue_point(queue); //우변 먼저 실행 해서 좌변의 size가 1 작아짐
		tab[size] = *contents[size];
		size++;
	}
	ft_sort_int_tab(tab, size);
	k = sequence_check(contents, tab, size, queue);
	free_data(contents, tab, size);
	if (k == size)
	{
		free_queue(queue);
		exit(0);
	}
}
