/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:56:40 by geonhwki          #+#    #+#             */
/*   Updated: 2025/05/23 18:28:30 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "token.h"
#include <stdlib.h>
#include <stdio.h>

void print_error(t_parser *parser) {
	printf("parse error near: %s\n", parser->cur->lexeme_or_null);
}

const char *token_type_str(t_token_type type) {
	switch (type) {
		case TOKEN_TOKEN:
			return "TOKEN";
		case TOKEN_WORD:
			return "WORD";
		case TOKEN_ASSIGNMENT_WORD:
			return "ASSIGNMENT_WORD";
		case TOKEN_NAME:
			return "NAME";
		case TOKEN_NEWLINE:
			return "NEWLINE";
		case TOKEN_IO_NUMBER:
			return "IO_NUMBER";
		case TOKEN_AND_IF:
			return "AND_IF";
		case TOKEN_OR_IF:
			return "OR_IF";
		case TOKEN_DSEMI:
			return "DSEMI";
		case TOKEN_DLESS:
			return "DLESS";
		case TOKEN_DGREAT:
			return "DGREAT";
		case TOKEN_LESSAND:
			return "LESSAND";
		case TOKEN_GREATAND:
			return "GREATAND";
		case TOKEN_LESSGREAT:
			return "LESSGREAT";
		case TOKEN_DLESSDASH:
			return "DLESSDASH";
		case TOKEN_CLOBBER:
			return "CLOBBER";
		case TOKEN_LBRACE:
			return "LBRACE";
		case TOKEN_RBRACE:
			return "RBRACE";
		case TOKEN_BANG:
			return "BANG";
		case TOKEN_LESS:
			return "LESS";
		case TOKEN_GREAT:
			return "GREAT";
		default:
			return "UNKNOWN";
	}
}


void print_indent(int depth) {
	for (int i = 0; i < depth; i++) printf("  ");
}

// PREFIX PART 트리 출력
void print_cmd_prefix_part(t_cmd_prefix_part *part, int depth) {
	int idx = 0;
	while (part) {
		print_indent(depth);
		printf("└─PREFIX_PART %d\n", idx++);
		if (part->assignment_word_or_null) {
			print_indent(depth + 1);
			printf("└─할당어: %s\n", part->assignment_word_or_null->lexeme_or_null);
		}
		if (part->io_redirect_or_null && part->io_redirect_or_null->io_file_or_null) {
			t_io_file *io = part->io_redirect_or_null->io_file_or_null;
			print_indent(depth + 1);
			printf("└─리다이렉트: %s %s\n", token_type_str(io->operator->type), io->filename->lexeme_or_null);
		}
		part = part->next_or_null;
	}
}

// SUFFIX PART 트리 출력
void print_cmd_suffix_part(t_cmd_suffix_part *part, int depth) {
	int idx = 0;
	while (part) {
		print_indent(depth);
		printf("└─SUFFIX_PART %d\n", idx++);
		if (part->word_or_null) {
			print_indent(depth + 1);
			printf("└─단어: %s\n", part->word_or_null->lexeme_or_null);
		}
		if (part->io_redirect_or_null != NULL && part->io_redirect_or_null->io_file_or_null != NULL) {
			t_io_file *io = part->io_redirect_or_null->io_file_or_null;
			print_indent(depth + 1);
			printf("└─리다이렉트: %s %s\n", token_type_str(io->operator->type), io->filename->lexeme_or_null);
		}
		part = part->next_or_null;
	}
}

// 전체 simple_command 트리 출력
void print_simple_command_tree(t_simple_command *cmd, int depth) {
	print_indent(depth);
	printf("simple_command\n");
	if (cmd->cmd_prefix_or_null) {
		print_indent(depth + 1);
		printf("└─PREFIX\n");
		print_cmd_prefix_part(cmd->cmd_prefix_or_null->part_list, depth + 2);
	}
	if (cmd->cmd_name_or_null && cmd->cmd_name_or_null->word_or_null) {
		print_indent(depth + 1);
		printf("└─NAME: %s\n", cmd->cmd_name_or_null->word_or_null->lexeme_or_null);
	}
	if (cmd->cmd_word_or_null && cmd->cmd_word_or_null->word_or_null) {
		print_indent(depth + 1);
		printf("└─WORD: %s\n", cmd->cmd_word_or_null->word_or_null->lexeme_or_null);
	}
	if (cmd->cmd_suffix_or_null) {
		print_indent(depth + 1);
		printf("└─SUFFIX\n");
		print_cmd_suffix_part(cmd->cmd_suffix_or_null->part_list, depth + 2);
	}
}

void next(t_parser *parser) {
	if (parser->cur == NULL)
		return;
	parser->cur = parser->cur->next_or_null;
}

t_bool check(t_parser *parser, t_token_type type) {
	return (parser->cur != NULL && parser->cur->type == type);
}

t_token *accept(t_parser *parser, t_token_type type) {
	t_token *tmp = parser->cur;

	if (check(parser, type)) {
		next(parser);
		return tmp;
	}

	return NULL;
}

t_simple_command *simple_command(t_parser *parser) {
	t_simple_command *cmd;

	cmd = malloc(sizeof(t_simple_command));

	cmd->cmd_name_or_null = NULL;
	cmd->cmd_suffix_or_null = NULL;
	cmd->cmd_prefix_or_null = NULL;
	cmd->cmd_word_or_null = NULL;

	cmd->cmd_prefix_or_null = cmd_prefix(parser);

	if (cmd->cmd_prefix_or_null != NULL) {
		cmd->cmd_word_or_null = cmd_word(parser);
		cmd->cmd_suffix_or_null = cmd_suffix(parser);
	} else {
		cmd->cmd_name_or_null = cmd_name(parser);
		cmd->cmd_suffix_or_null = cmd_suffix(parser);

		if (cmd->cmd_name_or_null == NULL)
			exit(1);
	}

	return (cmd);
}

t_cmd_name *cmd_name(t_parser *parser) {
	t_token *token;
	t_cmd_name *name;


	token = accept(parser, TOKEN_TOKEN);
	if (token == NULL)
		return NULL;

	name = malloc(sizeof(t_cmd_name));
	name->word_or_null = token;

	return name;
}

t_cmd_word *cmd_word(t_parser *parser) {
	t_token *token;
	t_cmd_word *word;


	token = accept(parser, TOKEN_TOKEN);
	if (token == NULL)
		return NULL;

	word = malloc(sizeof(t_cmd_word));
	word->word_or_null = token;

	return word;
}

t_cmd_prefix *cmd_prefix(t_parser *parser) {
	t_cmd_prefix *prefix;
	t_cmd_prefix_part *part_node;
	t_cmd_prefix_part *cur;

	part_node = cmd_prefix_part(parser);
	if (part_node == NULL)
		return NULL;

	prefix = malloc(sizeof(t_cmd_prefix));
	prefix->part_list = part_node;
	cur = part_node;

	while (TRUE) {
		part_node = cmd_prefix_part(parser);

		if (part_node == NULL)
			break;

		cur->next_or_null = part_node;
		cur = part_node;
	}

	return (prefix);
}

t_cmd_prefix_part *cmd_prefix_part(t_parser *parser) {
	t_cmd_prefix_part *part;
	t_io_redirect *io_redirect_node;
	t_token *assignment_word_node;

	part = NULL;
	io_redirect_node = NULL;
	assignment_word_node = NULL;

	assignment_word_node = accept(parser, TOKEN_ASSIGNMENT_WORD);
	if (assignment_word_node == NULL)
		io_redirect_node = io_redirect(parser);

	if (assignment_word_node == NULL && io_redirect_node == NULL)
		return (NULL);

	part = malloc(sizeof(t_cmd_prefix_part));
	part->io_redirect_or_null = io_redirect_node;
	part->assignment_word_or_null = assignment_word_node;
	part->next_or_null = NULL;

	return part;
}

t_cmd_suffix *cmd_suffix(t_parser *parser) {
	t_cmd_suffix *suffix;

	t_cmd_suffix_part *new;
	t_cmd_suffix_part *cur;

	new = cmd_suffix_part(parser);
	if (new == NULL)
		return NULL;

	suffix = malloc(sizeof(t_cmd_suffix));
	suffix->part_list = new;
	cur = new;

	while (TRUE) {
		new = cmd_suffix_part(parser);

		if (new == NULL)
			break;

		cur->next_or_null = new;
		cur = new;
	}

	return (suffix);
}

t_cmd_suffix_part *cmd_suffix_part(t_parser *parser) {
	t_cmd_suffix_part *part;
	t_io_redirect *io_redirect_node;
	t_token *word_node;

	io_redirect_node = NULL;
	word_node = accept(parser, TOKEN_TOKEN);
	if (word_node == NULL)
		io_redirect_node = io_redirect(parser);

	if (word_node == NULL && io_redirect_node == NULL)
		return (NULL);

	part = malloc(sizeof(t_cmd_suffix_part));
	part->io_redirect_or_null = io_redirect_node;
	part->word_or_null = word_node;
	part->next_or_null = NULL;

	return part;
}

//t_redirect_list *redirect_list(t_parser *parser);

t_io_redirect *io_redirect(t_parser *parser) {
	t_io_redirect *redir;
	t_token *io_number_node;
	t_io_file *io_file_node;
	t_io_here *io_here_node;

	io_here_node = NULL;
	io_number_node = accept(parser, TOKEN_IO_NUMBER);
	io_file_node = io_file(parser);
	if (io_file_node == NULL)
		io_here_node = io_here(parser);

	if (io_file_node == NULL && io_here_node == NULL)
		return (NULL);

	redir = malloc(sizeof(t_io_redirect));
	redir->io_file_or_null = io_file_node;
	redir->io_number = io_number_node;
	redir->io_here_or_null = io_here_node;

	return (redir);
}

t_io_file *io_file(t_parser *parser) {
	t_token *operator;
	t_token *filename;
	t_io_file *io_file_node;

	if (check(parser, TOKEN_LESSAND))
		operator = accept(parser, TOKEN_LESSAND);
	else if (check(parser, TOKEN_GREATAND))
		operator = accept(parser, TOKEN_GREATAND);
	else if (check(parser, TOKEN_LESS))
		operator = accept(parser, TOKEN_LESS);
	else if (check(parser, TOKEN_GREAT))
		operator = accept(parser, TOKEN_GREAT);
	else if (check(parser, TOKEN_LESSGREAT))
		operator = accept(parser, TOKEN_LESSGREAT);
	else if (check(parser, TOKEN_CLOBBER))
		operator = accept(parser, TOKEN_CLOBBER);
	else if (check(parser, TOKEN_DGREAT))
		operator = accept(parser, TOKEN_DGREAT);
	else
		return (NULL);

	filename = accept(parser, TOKEN_TOKEN);
	if (filename == NULL) {
		print_error(parser);
		return (NULL);
	}


	io_file_node = malloc(sizeof(t_io_file));
	io_file_node->operator = operator;
	io_file_node->filename = filename;
	return (io_file_node);
}

//t_token *filename(t_parser *parser);

t_io_here *io_here(t_parser *parser) {
	parser->err = 0;
	return NULL;
}

t_token *here_end(t_parser *parser);

