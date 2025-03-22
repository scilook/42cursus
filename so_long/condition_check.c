/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:21:33 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/22 16:29:30 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	left_search(t_point *point, t_list **place, t_list **savepoint)
{
	t_list	*get_place;

	get_place = *place;
	if (ft_pointcmp(get_place->content, *savepoint))
		*place = get_place->next;
	else
	{
		if (*savepoint == NULL)
			*savepoint = point_list(point);
		else
			ft_lstadd_front(savepoint, point_list(point));
		point->x--;
		ft_lstadd_front(place, point_list(point));
	}
}

static void	upper_search(t_point *point, t_list **place, t_list **savepoint)
{
	t_list	*get_place;

	get_place = *place;
	if (ft_pointcmp(get_place->content, *savepoint))
		*place = get_place->next;
	else
	{
		if (*savepoint == NULL)
			*savepoint = point_list(point);
		else
			ft_lstadd_front(savepoint, point_list(point));
		point->y--;
		ft_lstadd_front(place, point_list(point));
	}
}

static void	right_search(t_point *point, t_list **place, t_list **savepoint)
{
	t_list	*get_place;

	get_place = *place;
	if (ft_pointcmp(get_place->content, *savepoint))
		*place = get_place->next;
	else
	{
		if (*savepoint == NULL)
			*savepoint = point_list(point);
		else
			ft_lstadd_front(savepoint, point_list(point));
		point->x++;
		ft_lstadd_front(place, point_list(point));
	}
}

static void	down_search(t_point *point, t_list **place, t_list **savepoint)
{
	t_list	*get_place;

	get_place = *place;
	if (ft_pointcmp(get_place->content, *savepoint))
		*place = get_place->next;
	else
	{
		if (*savepoint == NULL)
			*savepoint = point_list(point);
		else
			ft_lstadd_front(savepoint, point_list(point));
		point->y++;
		ft_lstadd_front(place, point_list(point));
	}
}

void	condition_check(t_set *set)
{
	t_list	*place;
	t_list	*savepoint;
	t_point	*point;

	savepoint = NULL;
	point = (t_point *)malloc(sizeof(t_point));
	point->x = set->p_x;
	point->y = set->p_y;
	place = point_list(point);
	while (place || set->map[point->y][point->x] != 'E')
	{
		point = place->content;
		if (set->map[point->y][point->x - 1] != '1')
			left_search(point, &place, &savepoint);
		if (set->map[point->y - 1][point->x] != '1')
			upper_search(point, &place, &savepoint);
		if (set->map[point->y][point->x + 1] != '1')
			right_search(point, &place, &savepoint);
		if (set->map[point->y + 1][point->x] != '1')
			down_search(point, &place, &savepoint);
	}
	if (place == NULL)
		if_ret(1, set);
	lst_clear(place);
	lst_clear(savepoint);
}
/* 
	계획
	//1. 모든 'C'를 0xCC000000이상의 값으로 대치 및 목록 작성
	2. 'E' 찾기
	3. 갈곳 링크드리스트D의 0번 기준 상하좌우 조회(A)
	4. A를 간 곳 링크드리스트(B) 및 'E', '1' 인지 아닌지 조회(C)
	5. 모든 C를 D의 앞에 연결


 */