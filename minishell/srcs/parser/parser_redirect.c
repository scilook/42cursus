/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:53:14 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 18:06:13 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "redirect.h"

static t_redirect	*create_redirect(t_parser *self, t_token *operator,
						t_token *io_number, t_token *filename);

t_r_instruction	operator_to_instruction(t_token_type token_type)
{
	if (token_type == TOKEN_LESS)
		return (R_INPUT_REDIRECTION);
	else if (token_type == TOKEN_DLESS)
		return (R_HERE_DOC);
	else if (token_type == TOKEN_GREAT)
		return (R_OUTPUT_REDIRECTION);
	else if (token_type == TOKEN_DGREAT)
		return (R_APPENDING_TO);
	return (-1);
}

t_redirect	*_parser_parse_redirect(t_parser *parser)
{
	t_token	*operator;
	t_token	*filename;
	t_token	*io_number;

	io_number = _parser_accept(parser, TOKEN_IO_NUMBER);
	if (_parser_check(parser, TOKEN_LESS))
		operator = _parser_accept(parser, TOKEN_LESS);
	else if (_parser_check(parser, TOKEN_GREAT))
		operator = _parser_accept(parser, TOKEN_GREAT);
	else if (_parser_check(parser, TOKEN_DLESS))
		operator = _parser_accept(parser, TOKEN_DLESS);
	else if (_parser_check(parser, TOKEN_DGREAT))
		operator = _parser_accept(parser, TOKEN_DGREAT);
	else
	{
		if (io_number != NULL)
			parser->err = TRUE;
		return (NULL);
	}
	filename = _parser_accept(parser, TOKEN_TOKEN);
	return (create_redirect(parser, operator, io_number, filename));
}

static t_redirect	*create_redirect(t_parser *self, t_token *operator,
		t_token *io_number, t_token *filename)
{
	t_redirect	*redirect_node;

	if (filename == NULL)
	{
		self->err = TRUE;
		return (NULL);
	}
	redirect_node = redirect_init(NULL, NULL);
	if (io_number != NULL)
		redirect_node->redirectee.dest = ft_atoi(io_number->lexeme_or_null);
	redirect_node->redirector.dest = -1;
	redirect_node->instruction = operator_to_instruction(operator->type);
	if (operator->type == TOKEN_DLESS)
		redirect_node->here_doc_eof = ft_strdup(filename->lexeme_or_null);
	else
		redirect_node->redirector.filename = \
					ft_strdup(filename->lexeme_or_null);
	redirect_node->next = _parser_parse_redirect(self);
	return (redirect_node);
}
