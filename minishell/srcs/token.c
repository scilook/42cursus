/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:02:34 by geonhwki          #+#    #+#             */
/*   Updated: 2025/05/23 15:46:16 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>

t_token	*token(t_token_type type, char *lexeme_or_null, t_token *next_or_null)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->type = type;
	token->lexeme_or_null = lexeme_or_null;
	token->next_or_null = next_or_null;
	return (token);
}

void	add_token_to_last(t_token **head_ptr, t_token *to_add)
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

void	destroy(t_token *token)
{
	if (token->lexeme_or_null != NULL)
		free(token->lexeme_or_null);
	free(token);
}

void	destroy_all(t_token *token)
{
	t_token *cur;

	cur = token;

	while (cur != NULL)
	{
		destroy(cur);
		cur = cur->next_or_null;
	}
}