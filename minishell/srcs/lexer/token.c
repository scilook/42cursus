/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:02:34 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:28 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"
#include <stdlib.h>

t_token	*token_init(t_token_type type, char *lexeme_or_null)
{
	t_token	*token;

	token = ft_malloc(sizeof(t_token));
	token->type = type;
	token->lexeme_or_null = lexeme_or_null;
	token->next_or_null = NULL;
	return (token);
}

void	token_add_to_last(t_token **head_ptr, t_token *to_add)
{
	t_token	*current;

	current = *head_ptr;
	if (current == NULL)
	{
		*head_ptr = to_add;
		return ;
	}
	while (current->next_or_null != NULL)
		current = current->next_or_null;
	current->next_or_null = to_add;
}

void	_token_destroy(t_token *token)
{
	if (token->lexeme_or_null != NULL)
		free(token->lexeme_or_null);
	free(token);
}

void	token_destroy_all(t_token *token)
{
	t_token	*cur;
	t_token	*next;

	cur = token;
	while (cur != NULL)
	{
		next = cur->next_or_null;
		_token_destroy(cur);
		cur = next;
	}
}
