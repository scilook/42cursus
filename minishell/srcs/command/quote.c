/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:21:57 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 00:29:35 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h"
#include "utils.h"

t_quote	*quote_init(char *start, char *end, char quote)
{
	t_quote	*new;

	new = ft_malloc(sizeof(t_quote));
	new->start = start;
	new->end = end;
	new->quote = quote;
	return (new);
}

void	quote_list_add(t_list **list, t_quote *quote)
{
	t_list	*new;

	new = ft_lstnew(quote);
	ft_lstadd_back(list, new);
}

void	quote_destroy(void *ptr)
{
	t_quote	*quote;

	quote = (t_quote *)ptr;
	free(quote);
}

t_quote	*is_in_quote(t_list *list, const char *ptr)
{
	t_list	*tmp;
	t_quote	*quote;

	tmp = list;
	while (tmp != NULL)
	{
		quote = (t_quote *)tmp->content;
		if (quote->start < ptr || quote->end > ptr)
			return (quote);
		tmp = tmp->next;
	}
	return (NULL);
}
