/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:49:36 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/22 15:50:20 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"


int	ft_pointcmp(t_point *content, t_list *lst)
{
	t_point	*point;

	while (lst)
	{
		point = lst->content;
		if (content->x == point->x && content->y == point->y)
			return (1);
		lst = lst->next;
	}
	return (0);
}
/* 현재 player의 위치를 저장 */
t_list	*point_list(t_point *point)
{
	t_point	*new;

	new = malloc(sizeof(t_point));
	if (!new)
		return (NULL);
	new->x = point->x;
	new->y = point->y;
	return (ft_lstnew(new));
}

void	lst_clear(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}
