/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:20:50 by geonhwki          #+#    #+#             */
/*   Updated: 2025/05/23 18:42:30 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char *make_lexeme(t_scanner *scanner);

void handle_backslash_quote(t_scanner *scanner);

void handle_single_quote(t_scanner *scanner);

void handle_double_quote(t_scanner *scanner);

char advanced(t_scanner *scanner);


const char *token_type_to_str(t_token_type type) {
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

void print_tokens(const t_token *head) {
	const t_token *curr = head;

	while (curr != NULL) {
		printf("%s |%s|\n", token_type_to_str(curr->type),
			   curr->lexeme_or_null ? curr->lexeme_or_null : "(null)");
		curr = curr->next_or_null;
	}
}

char *preprocess_line_continuations(char *str) {
	char *new;
	char *ret;

	new = malloc(ft_strlen(str) + 1);
	ret = new;
	while (*str != '\0') {
		if (str[0] == '\\' && str[1] == '\n')
			str += 2;
		*new++ = *str++;
	}
	*new = '\0';
	return ret;
}

t_token *tokenize(char *source) {
	t_scanner scanner;
	char *preprocessed_source;

	preprocessed_source = preprocess_line_continuations(source);
	scanner.current = preprocessed_source;
	scanner.start = preprocessed_source;
	scanner.token = NULL;
	scan_tokens(&scanner);
//	print_tokens(scanner.token);
	return scanner.token;
}

void scan_tokens(t_scanner *scanner) {
	t_bool is_delimited;

	is_delimited = FALSE;
	while (!is_at_end(scanner)) {
		if (is_delimited)
			scanner->start = scanner->current;
		is_delimited = scan_token(scanner);
	}
}

t_bool is_start_of_operator(char c);

void delimit(t_scanner *scanner, t_bool can_be_io_number);

t_bool handle_operator(t_scanner *scanner);

t_bool handle_string(t_scanner *scanner);

t_bool scan_token(t_scanner *scanner) {
	if (peek(scanner) == '\n' || peek(scanner) == '\0') {
		delimit(scanner, FALSE);
		return TRUE;
	}
	if (is_start_of_operator(peek(scanner))) {
		return handle_operator(scanner);
	}
	return handle_string(scanner);
}

char *temp(t_scanner *scanner);

t_bool handle_string(t_scanner *scanner) {
	char cur;
	t_bool can_be_io_number;

	cur = peek(scanner);
	can_be_io_number = FALSE;
	if (cur == ' ') {
		advance(scanner);
		return TRUE;
	}
	while (cur != ' ' && cur != '\0' && cur != '\n') /* Rule 1, 3, 7 */
	{
		if (cur == '\\')
			handle_backslash_quote(scanner);
		else if (cur == '\'')
			handle_single_quote(scanner);
		else if (cur == '"')
			handle_double_quote(scanner);
		else if (is_start_of_operator(cur)) {
			can_be_io_number = TRUE;
			break;
		}
		advance(scanner);
		cur = peek(scanner);
	}
	if (scanner->current - scanner->start == 0)
		return TRUE;
	delimit(scanner, can_be_io_number);
	return TRUE;
}

t_bool is_digits(char *str) {
	while (*str != '\0') {
		if (!ft_isdigit(*str))
			return FALSE;
		++str;
	}
	return TRUE;
}

void delimit(t_scanner *scanner, t_bool can_be_io_number) {
	char *lexeme;

	lexeme = make_lexeme(scanner);
	if (can_be_io_number && is_digits(lexeme))
		add_token(scanner, token(TOKEN_IO_NUMBER, make_lexeme(scanner), NULL));
	else
		add_token(scanner, token(TOKEN_TOKEN, make_lexeme(scanner), NULL));
}

void add_token(t_scanner *scanner, t_token *token) {
	add_token_to_last(&scanner->token, token);
}

char *make_lexeme(t_scanner *scanner) {
	char *lexeme;
	size_t size;

	size = scanner->current - scanner->start + 1;
	lexeme = malloc(size);
	ft_strlcpy(lexeme, scanner->start, size);
	return lexeme;
}

t_bool is_start_of_operator(char c) {
	if (c == '{')
		return TRUE;
	if (c == '}')
		return TRUE;
	if (c == '<')
		return TRUE;
	if (c == '>')
		return TRUE;
	if (c == '&')
		return TRUE;
	if (c == '|')
		return TRUE;
	if (c == ';')
		return TRUE;
	if (c == '!')
		return TRUE;
	return FALSE;
}

t_bool handle_operator(t_scanner *scanner) {
	char cur;

	cur = advance(scanner);
	if (cur == '{')
		add_token(scanner, token(TOKEN_LBRACE, NULL, NULL));
	else if (cur == '}')
		add_token(scanner, token(TOKEN_RBRACE, NULL, NULL));
	else if (match_two(scanner, "&&"))
		add_token(scanner, token(TOKEN_AND_IF, NULL, NULL));
	else if (match_two(scanner, "||"))
		add_token(scanner, token(TOKEN_OR_IF, NULL, NULL));
	else if (match_two(scanner, ";;"))
		add_token(scanner, token(TOKEN_DSEMI, NULL, NULL));
	else if (match_two(scanner, "<<"))
		add_token(scanner, token(TOKEN_DLESS, NULL, NULL));
	else if (match_two(scanner, ">>"))
		add_token(scanner, token(TOKEN_DGREAT, NULL, NULL));
	else if (match_two(scanner, "<&"))
		add_token(scanner, token(TOKEN_LESSAND, NULL, NULL));
	else if (match_two(scanner, ">&"))
		add_token(scanner, token(TOKEN_GREATAND, NULL, NULL));
	else if (match_two(scanner, "<>"))
		add_token(scanner, token(TOKEN_LESSGREAT, NULL, NULL));
	else if (match_two(scanner, ">|"))
		add_token(scanner, token(TOKEN_CLOBBER, NULL, NULL));
	else if (cur == '<')
		add_token(scanner, token(TOKEN_LESS, NULL, NULL));
	else if (cur == '>')
		add_token(scanner, token(TOKEN_GREAT, NULL, NULL));
	else
		return FALSE;
	return TRUE;
}

/* 2.2.1 Escape Character (Backslash) */
void handle_backslash_quote(t_scanner *scanner) {
	advance(scanner);
}

/* 2.2.2 Single-Quotes */
void handle_single_quote(t_scanner *scanner) {
	char cur;

	cur = advanced(scanner);
	while (cur != '\'')
		cur = advanced(scanner);
}

/* 2.2.3  Double-Quotes */
void handle_double_quote(t_scanner *scanner) {
	char cur;

	cur = advanced(scanner);
	while (cur != '"')
		cur = advanced(scanner);
}

char advance(t_scanner *scanner) {
	return *scanner->current++;
}

char advanced(t_scanner *scanner) {
	return *(++scanner->current);
}

char peek(t_scanner *scanner) {
	return *scanner->current;
}

t_bool match(t_scanner *scanner, char expected) {
	if (peek(scanner) == expected) {
		advance(scanner);
		return TRUE;
	}
	return FALSE;
}

t_bool match_two(t_scanner *scanner, char *two) {
	if (*(scanner->current - 1) != two[0])
		return FALSE;
	return match(scanner, two[1]);
}

t_bool is_at_end(t_scanner *scanner) {
	return (*scanner->current == '\n' || *scanner->current == '\0');
}
