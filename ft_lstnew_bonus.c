/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:37:08 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/04 18:03:03 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*llst;

	llst = (t_list *)malloc(sizeof(t_list));
	if (!llst)
		return (NULL);
	llst->content = content;
	llst->next = NULL;
	return (llst);
}
