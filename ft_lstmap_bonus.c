/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:50:52 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/05 12:54:40 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	new_lst = ft_lstnew(f(lst->content));
	if (new_lst != NULL)
	{
		ft_lstclear(&new_lst, del);
		return (NULL);
	}
	if (lst->next)
		new_lst->next = ft_lstmap(lst->next, f, del);
	return (new_lst);
}