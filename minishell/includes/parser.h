/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.k>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:05:53 by geonhwki          #+#    #+#             */
/*   Updated: 2025/05/23 16:46:59 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef struct s_io_here {
	t_token *operator;
	t_token *here_end;
} t_io_here;

typedef struct s_io_file {
	t_token *operator;
	t_token *filename;
} t_io_file;

typedef struct s_io_redirect {
	t_token *io_number;
	t_io_file *io_file_or_null;
	t_io_here *io_here_or_null;
} t_io_redirect;

typedef struct s_redirect_list {
	t_io_redirect *redirect;
	struct s_redirect_list *next_or_null;
} t_redirect_list;

typedef struct s_cmd_suffix_part {
	t_io_redirect *io_redirect_or_null;
	t_token *word_or_null;
	struct s_cmd_suffix_part *next_or_null;
} t_cmd_suffix_part;

typedef struct s_cmd_suffix {
	t_cmd_suffix_part *part_list;
} t_cmd_suffix;

typedef struct s_cmd_word {
	t_token *word_or_null;
} t_cmd_word;

typedef struct s_cmd_name {
	t_token *word_or_null;
} t_cmd_name;

typedef struct s_cmd_prefix_part {
	t_io_redirect *io_redirect_or_null;
	t_token *assignment_word_or_null;
	struct s_cmd_prefix_part *next_or_null;
} t_cmd_prefix_part;

typedef struct s_cmd_prefix {
	t_cmd_prefix_part *part_list;
} t_cmd_prefix;

typedef struct s_simple_command {
	t_cmd_prefix *cmd_prefix_or_null;
	t_cmd_word *cmd_word_or_null;
	t_cmd_suffix *cmd_suffix_or_null;
	t_cmd_name *cmd_name_or_null;

} t_simple_command;


typedef struct s_redirect {
	int fd;
	char *filename;
	t_token_type type;
	struct s_redirect *next;
} t_redirect;

typedef struct s_ast_command {
	char **argv;           // 명령어와 인자들
	t_redirect *redirects; // 리다이렉션 리스트
	int argc;
} t_ast_command;

typedef struct s_ast_arg {
} t_ast_arg;

typedef struct {
	t_token *cur;
	t_simple_command *ast;
	t_bool err;
} t_parser;

void print_simple_command_tree(t_simple_command *cmd, int depth);

t_simple_command *simple_command(t_parser *parser);

t_cmd_name *cmd_name(t_parser *parser);

t_cmd_word *cmd_word(t_parser *parser);

t_cmd_prefix *cmd_prefix(t_parser *parser);

t_cmd_prefix_part *cmd_prefix_part(t_parser *parser);

t_cmd_suffix *cmd_suffix(t_parser *parser);

t_cmd_suffix_part *cmd_suffix_part(t_parser *parser);

//t_redirect_list *redirect_list(t_parser *parser);

t_io_redirect *io_redirect(t_parser *parser);

t_io_file *io_file(t_parser *parser);

//t_token *filename(t_parser *parser);

t_io_here *io_here(t_parser *parser);

t_token *here_end(t_parser *parser);

#endif