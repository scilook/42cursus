/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_internal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 22:53:46 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:28 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	_lexer_advance(t_scanner *scanner)
{
	if (!_lexer_is_at_end(scanner))
		return (*scanner->current++);
	return (*scanner->current);
}

char	_lexer_peek(t_scanner *scanner, size_t offset)
{
	return (scanner->current[offset]);
}

t_bool	_lexer_match(t_scanner *scanner, const char *expected, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (scanner->current[i] == '\0' || scanner->current[i] != expected[i])
			return (FALSE);
		++i;
	}
	scanner->current += count;
	return (TRUE);
}

void	_lexer_delimit(t_scanner *scanner, t_token_type type)
{
	char	*lexeme;
	size_t	size;

	size = scanner->current - scanner->start + 1;
	lexeme = ft_malloc(size);
	ft_strlcpy(lexeme, scanner->start, size);
	if (type == TOKEN_TOKEN && _is_io_number(scanner, lexeme))
		type = TOKEN_IO_NUMBER;
	token_add_to_last(&scanner->token, token_init(type, lexeme));
	scanner->start = scanner->current;
}

t_bool	_is_io_number(t_scanner *scanner, char *lexeme)
{
	const char	cur = *(scanner->current);

	if (cur != '<' && cur != '>')
		return (FALSE);
	return (ft_isdigits(lexeme));
}
