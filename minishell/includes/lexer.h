/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.k>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:20:50 by geonhwki          #+#    #+#             */
/*   Updated: 2025/05/23 13:52:53 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.k>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:20:50 by geonhwki          #+#    #+#             */
/*   Updated: 2025/04/19 16:30:35 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_LEXER_H
# define MINISHELL_LEXER_H
# include "token.h"

typedef struct {
	char* start;
	char* current;
	t_token* token;
} t_scanner;

t_token* tokenize(char* source);
t_bool scan_token(t_scanner* scanner);
void scan_tokens(t_scanner* scanner);

char advance(t_scanner* scanner);
char peek(t_scanner* scanner);
t_bool match(t_scanner* scanner, char expected);
t_bool match_two(t_scanner* scanner, char* two);
void add_token(t_scanner* scanner, t_token* token);

t_bool is_at_end(t_scanner* scanner);



#endif /* MINISHELL_LEXER_H */
