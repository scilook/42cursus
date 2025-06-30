/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:28:32 by geonhwki          #+#    #+#             */
/*   Updated: 2025/05/28 13:37:17 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"


int main(void) {
	t_token *token;
	t_simple_command *command;
	t_parser parser;
	char *line;
	char *path;

	while (1)
	{
		line = readline("sh> ");
		token = tokenize(line);
		add_history(line);
		free(line);

		parser.cur = token;
		command = simple_command(&parser);
		print_simple_command_tree(command, 1);
		// path = seek_path(command);
		// command->cmd_suffix_or_null->part_list
		// execve(path, )
	}

	return 0;
}