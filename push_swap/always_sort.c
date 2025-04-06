/*
가장빨리 정렬 가능한 하나를 선택하는 알고리즘
a는 항상 정렬된 상태 이를 만족하면 아래를 시행
a가 사용가능한 함수 ra=탑 값이 바닥보다 크다
b가 사용가능한 함수 rb=탑값이 조건을 만족하지 못한다 rrb=바닥값이 조건을 만족한다
pa=조건을 만족하는 값이 탑에 위치한다
1인경우 탐색 2인경우 탐색 3인경우 탐색 ... 있는대로 수행
*/

#include "push_swap.h"

static void	push_values(t_queue *queue0, t_queue *queue1)
{
	int	*value;

	while (queue0->size > 3)
	{
		value = dequeue_point(queue0);
		enqueue_point_head(queue1, *value);
		free(value);
		ft_printf("pb\n");
	}
}

void	ra_pa_sort(t_queue *queue0, t_queue *queue1)
{
	int	*value;
	int	*tmp;
	int	i;

	value = dequeue_point(queue1);
	if (*value > *(int *)queue0->rear->content)
	{
		enqueue_point(queue0, *value);
		ft_printf("pa\nra\n");
		return ;
	}
	else
	{
		tmp = dequeue_point(queue0);
		i = 0;
		while (*value > *tmp)
		{
			enqueue_point(queue0, *tmp);
			tmp = dequeue_point(queue0);
			i++;
			ft_printf("ra\n");
		}
		enqueue_point_head(queue0, *tmp);
		enqueue_point_head(queue0, *value);
		free(tmp);
	}
	free(value);
	ft_printf("pa\n");
	if (queue0->size - i > i)
	{
		while (queue0->size - i++)
		{
			value = dequeue_point(queue0);
			enqueue_point(queue0, *value);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (i--)
		{
			value = dequeue_point_rear(queue0);
			enqueue_point_head(queue0, *value);
			ft_printf("rra\n");
		}
	}
	free(value);
}

void	always_sort(t_queue *queue0, t_queue *queue1)
{
	int	*value;

	push_values(queue0, queue1);
	under3_sort_a(queue0);
	ra_pa_sort(queue0, queue1);
}
