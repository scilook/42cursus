/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:05:59 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 00:39:20 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "token.h"
#include <stdlib.h>

t_parser	*parser_init(t_token *tokens)
{
	t_parser	*self;

	self = ft_malloc(sizeof(t_parser));
	self->cur = tokens;
	self->commands = NULL;
	self->err = FALSE;
	return (self);
}

void	parser_destroy(t_parser *self)
{
	command_destroy_all(self->commands);
	free(self);
}

void	_parser_advance(t_parser *self)
{
	if (self->cur == NULL)
		return ;
	self->cur = self->cur->next_or_null;
}

t_bool	_parser_check(t_parser *self, t_token_type type)
{
	return (self->cur != NULL && self->cur->type == type);
}

t_token	*_parser_accept(t_parser *self, t_token_type type)
{
	t_token	*tmp;

	tmp = self->cur;
	if (_parser_check(self, type))
	{
		_parser_advance(self);
		return (tmp);
	}
	return (NULL);
}
