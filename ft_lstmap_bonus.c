/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:50:52 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/06 11:38:17 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	new_lst = ft_lstnew(f(lst->content));
	if (new_lst == NULL)
		return (NULL);
	tmp = new_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp->next = ft_lstnew(f(lst->content));
		if (tmp->next == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new_lst);
}
