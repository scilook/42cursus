/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:36:30 by hyeson            #+#    #+#             */
/*   Updated: 2025/04/03 17:58:02 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	if_ret(int bool, t_queue *queue)
{
	if (bool)
	{
		free_queue(queue);
		ft_printf("Error\n");
		exit(0);
	}
}

static int	validation_check(char *nbrj)
{
	char	*tmp;
	int		k;

	k = 0;
	if (nbrj[k] == '+' || nbrj[k] == '-')
		k++;
	while (nbrj[k] == '0')
		k++;
	if (ft_strlen(nbrj + k) > 16)
		return (0);
	tmp = ft_itoa(ft_atoi(nbrj + k));
	if (nbrj[k] == '+' || nbrj[k] == '-' || !ft_strnstr(nbrj, tmp,
			ft_strlen(nbrj)))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	while (nbrj[k])
		if (!ft_isdigit(nbrj[k++]))
			return (0);
	return (1);
}

static void	allocate_queue(char *argv[], t_queue *queue)
{
	int		i;
	int		j;
	char	**nbr;

	i = 1;
	while (argv[i])
	{
		nbr = ft_split(argv[i++], ' ');
		j = 0;
		while (nbr[j])
		{
			if (!validation_check(nbr[j]))
			{
				free(nbr[j]);
				free(nbr);
				free_queue(queue);
				ft_printf("Error\n");
				exit(0);
			}
			enqueue_point(queue, ft_atoi(nbr[j]));
			free(nbr[j]);
			j++;
		}
		free(nbr);
	}
}

int	main(int argc, char *argv[])
{
	t_queue	*queue0;
	t_queue	*queue1;
	int		k;

	if (argc < 2)
		return (0);
	queue0 = init_queue();
	allocate_queue(argv, queue0);
	k = rank_queue(queue0);
	queue1 = init_queue();
	if (k != queue0->size)
	{
		if (queue0->size > 6)
			radix_sort(queue0, queue1);
		else
			under6_sort(queue0, queue1);
	}
	free_queue(queue0);
	free_queue(queue1);
}
