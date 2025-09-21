/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 22:53:14 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:28 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdio.h>

t_token	*lexer_tokenize_all(char *source)
{
	t_scanner	scanner;

	scanner.start = source;
	scanner.current = source;
	scanner.token = NULL;
	while (!_lexer_is_at_end(&scanner))
	{
		_lexer_lex_operator(&scanner);
		_lexer_lex_word(&scanner);
	}
	return (scanner.token);
}

void	_lexer_lex_operator(t_scanner *scanner)
{
	if (_lexer_match(scanner, "{", 1))
		_lexer_delimit(scanner, TOKEN_LBRACE);
	else if (_lexer_match(scanner, "}", 1))
		_lexer_delimit(scanner, TOKEN_RBRACE);
	else if (_lexer_match(scanner, "&&", 2))
		_lexer_delimit(scanner, TOKEN_AND_IF);
	else if (_lexer_match(scanner, "||", 2))
		_lexer_delimit(scanner, TOKEN_OR_IF);
	else if (_lexer_match(scanner, "<<", 2))
		_lexer_delimit(scanner, TOKEN_DLESS);
	else if (_lexer_match(scanner, ">>", 2))
		_lexer_delimit(scanner, TOKEN_DGREAT);
	else if (_lexer_match(scanner, "<", 1))
		_lexer_delimit(scanner, TOKEN_LESS);
	else if (_lexer_match(scanner, ">", 1))
		_lexer_delimit(scanner, TOKEN_GREAT);
	else if (_lexer_match(scanner, "|", 1))
		_lexer_delimit(scanner, TOKEN_PIPE);
}

void	_lexer_lex_word(t_scanner *scanner)
{
	char	cur;

	if (*scanner->current == ' ')
	{
		_lexer_advance(scanner);
		scanner->start = scanner->current;
		return ;
	}
	while (_lexer_peek(scanner, 0) != ' '
		&& !_lexer_is_start_of_operator(_lexer_peek(scanner, 0))
		&& !_lexer_is_at_end(scanner))
	{
		cur = _lexer_advance(scanner);
		if (cur == '\\' || cur == '\'' || cur == '"')
			_lexer_handle_quote(scanner, cur);
	}
	_lexer_delimit(scanner, TOKEN_TOKEN);
}

void	_lexer_handle_quote(t_scanner *scanner, char quote)
{
	char	cur;
	t_bool	is_quote_closed;

	is_quote_closed = FALSE;
	if (quote == '\\')
	{
		_lexer_advance(scanner);
		return ;
	}
	while (!_lexer_is_at_end(scanner))
	{
		cur = _lexer_advance(scanner);
		if (cur == quote)
		{
			is_quote_closed = TRUE;
			break ;
		}
		if (quote == '"' && cur == '\\')
			_lexer_advance(scanner);
	}
	if (!is_quote_closed)
		printf("Unterminated Quote\n");
}
