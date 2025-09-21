/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:58:42 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 21:31:22 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "ft_builtins.h"
#include "minishell.h"
#include "parser.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern int	g_sig;
void		process_heredoc(t_minishell *shell, t_command *commands);

void	_exec(t_command *cmd, t_minishell *shell)
{
	char	*filename;

	if (cmd->words == NULL)
	{
		destroy_shell(shell);
		exit(0);
	}
	filename = find_filename_or_null(shell, cmd->words[0]);
	if (filename == NULL)
	{
		perror(cmd->words[0]);
		destroy_shell(shell);
		if (errno == ENOENT)
			exit(127);
		exit(126);
	}
	if (execve(filename, cmd->words, shell->envp) == -1)
	{
		perror(filename);
		free(filename);
		destroy_shell(shell);
		exit(127);
	}
}

void	_dup_internal(t_minishell *shell, t_command *cur, int *fds)
{
	dup2(shell->pipe_in_fd, STDIN_FILENO);
	close(fds[0]);
	if (cur->pipe == NULL)
		dup2(shell->stdout_fd, STDOUT_FILENO);
	else
		dup2(fds[1], STDOUT_FILENO);
	close(fds[1]);
	if (!dup_redirect(cur))
	{
		perror("");
		destroy_shell(shell);
		exit(1);
	}
}

void	_run_child(t_command *cur, t_minishell *shell)
{
	int		fds[2];
	pid_t	pid;

	pipe(fds);
	pid = fork();
	if (pid == 0)
	{
		_dup_internal(shell, cur, fds);
		if (is_builtin_command(cur) != NONE)
			_builtin_exec(cur, shell, is_builtin_command(cur), TRUE);
		else
			_exec(cur, shell);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], shell->pipe_in_fd);
		close(fds[0]);
		cur->runtime.pid = pid;
	}
}

int	_run_builtins_no_pipe(t_minishell *shell, t_command *cur, t_token *tokens,
		t_parser *parser)
{
	if (!dup_redirect(cur))
	{
		perror("");
		dup2(shell->stdin_fd, STDIN_FILENO);
		dup2(shell->stdout_fd, STDOUT_FILENO);
		return (1);
	}
	dup_redirect(cur);
	_builtin_exec(cur, shell, is_builtin_command(cur), FALSE);
	dup2(shell->stdin_fd, STDIN_FILENO);
	dup2(shell->stdout_fd, STDOUT_FILENO);
	token_destroy_all(tokens);
	parser_destroy(parser);
	shell->tokens = NULL;
	shell->parser = NULL;
	return (0);
}

int	minishell_run(t_minishell *shell, char *input)
{
	int			exit_status;
	t_command	*cur;

	g_sig = 1;
	shell->tokens = lexer_tokenize_all(input);
	shell->parser = parser_init(shell->tokens);
	parser_parse_commands(shell);
	cur = shell->parser->commands;
	process_heredoc(shell, cur);
	if (is_builtin_command(cur) != 0 && cur->pipe == NULL)
		return (_run_builtins_no_pipe(shell, cur, shell->tokens,
				shell->parser));
	while (cur != NULL)
	{
		_run_child(cur, shell);
		cur = cur->pipe;
	}
	exit_status = wait_command(shell->parser->commands);
	token_destroy_all(shell->tokens);
	parser_destroy(shell->parser);
	shell->tokens = NULL;
	shell->parser = NULL;
	return (exit_status);
}
