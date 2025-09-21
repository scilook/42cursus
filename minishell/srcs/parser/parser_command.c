/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:53:09 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 03:15:20 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "parser.h"
#include "redirect.h"
#include <stdio.h>

void	parser_parse_commands(t_minishell *shell)
{
	t_command	*cmd;

	cmd = _parser_parse_command(shell);
	parser_append_command(shell->parser, cmd);
	while (_parser_check(shell->parser, TOKEN_OR_IF)
		|| _parser_check(shell->parser, TOKEN_AND_IF))
	{
		_parser_advance(shell->parser);
		cmd = _parser_parse_command(shell);
		parser_append_command(shell->parser, cmd);
	}
}

t_command	*_parser_parse_command(t_minishell *shell)
{
	t_redirect	*redirect;
	t_command	*new;
	t_token		*word;

	new = command_init();
	redirect = _parser_parse_redirect(shell->parser);
	redirect_add_to_last(shell, &new->redirects, redirect);
	word = _parser_accept(shell->parser, TOKEN_TOKEN);
	while (word != NULL)
	{
		word_add_to_last(&new->words, word->lexeme_or_null);
		redirect = _parser_parse_redirect(shell->parser);
		redirect_add_to_last(shell, &new->redirects, redirect);
		word = _parser_accept(shell->parser, TOKEN_TOKEN);
	}
	if (_parser_check(shell->parser, TOKEN_PIPE))
	{
		_parser_accept(shell->parser, TOKEN_PIPE);
		new->pipe = _parser_parse_command(shell);
	}
	if (new->words != NULL)
		expand_word(shell, &new->words);
	return (new);
}

void	parser_append_command(t_parser *self, t_command *to_add)
{
	t_command	*command;

	command = self->commands;
	if (command == NULL)
	{
		self->commands = to_add;
		return ;
	}
	while (command->next != NULL)
		command = command->next;
	command->next = to_add;
}
