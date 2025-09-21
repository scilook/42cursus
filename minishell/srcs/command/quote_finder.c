/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_finder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:23:34 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 00:38:37 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h"
#include "utils.h"

t_list	*_find_quotes(t_list *list, char *str, t_quote *cur)
{
	while (*str != '\0')
	{
		if (*str == '\\')
			quote_list_add(&list, quote_init(str, str + 1, *str));
		if (*str == '\\')
			str += 1;
		else if (*str == '"' || *str == '\'')
		{
			cur->quote = *str;
			cur->start = str;
			++str;
			while (*str != '\0')
			{
				if (cur->quote == '"' && *str == '\\')
					str += 2;
				if (*str == cur->quote)
					break ;
				++str;
			}
			cur->end = str;
			quote_list_add(&list, quote_init(cur->start, cur->end, cur->quote));
		}
		++str;
	}
	return (list);
}

t_list	*find_quotes(char *str)
{
	t_list	*list;
	t_quote	cur;

	list = 0;
	list = _find_quotes(list, str, &cur);
	return (list);
}
