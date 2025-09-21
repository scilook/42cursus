/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:20:50 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:25 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "libft.h"
# include "token.h"
# include "utils.h"

typedef struct s_scanner
{
	char	*start;
	char	*current;
	t_token	*token;
}			t_scanner;
t_token		*lexer_tokenize_all(char *source);
void		_lexer_handle_quote(t_scanner *scanner, char quote);
char		_lexer_advance(t_scanner *scanner);
char		_lexer_peek(t_scanner *scanner, size_t offset);
t_bool		_lexer_match(t_scanner *scanner, const char *expected,
				size_t count);
void		_lexer_lex_operator(t_scanner *scanner);
void		_lexer_lex_word(t_scanner *scanner);
void		_lexer_delimit(t_scanner *scanner, t_token_type type);
t_bool		_lexer_is_at_end(t_scanner *scanner);
t_bool		_lexer_is_start_of_operator(char c);
t_bool		_is_io_number(t_scanner *scanner, char *lexeme);
#endif /* LEXER_H */
