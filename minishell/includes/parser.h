/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:05:53 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 03:11:22 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "command.h"
# include "lexer.h"
# include "minishell.h"
# include "utils.h"

/* PARSER */
t_parser	*parser_init(t_token *tokens);
void		parser_parse_commands(t_minishell *shell);
void		parser_destroy(t_parser *self);

void		_parser_advance(t_parser *self);
t_bool		_parser_check(t_parser *self, t_token_type type);
t_token		*_parser_accept(t_parser *self, t_token_type type);
void		parser_append_command(t_parser *parser, t_command *to_add);

t_token		*_parser_parse_io_number(t_parser *self);
t_command	*_parser_parse_command(t_minishell *shell);
t_redirect	*_parser_parse_redirect(t_parser *parser);

#endif
