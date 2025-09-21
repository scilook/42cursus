/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:13:16 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 18:19:45 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>

int			g_sig;

static void	reset_pipe_fd(t_minishell *shell)
{
	close(shell->pipe_in_fd);
	close(shell->pipe_out_fd);
	shell->pipe_in_fd = dup(shell->stdin_fd);
	shell->pipe_out_fd = dup(shell->stdout_fd);
	dup2(shell->stdin_fd, STDIN_FILENO);
	dup2(shell->stdout_fd, STDOUT_FILENO);
}

void	minishell_loop(t_minishell *shell, char *line)
{
	while (1)
	{
		g_sig = 0;
		if (isatty(shell->stdin_fd))
			line = readline("minishell> ");
		else
			line = readline(NULL);
		if (line == NULL)
			break ;
		if (*line == '\0')
		{
			reset_pipe_fd(shell);
			free(line);
			continue ;
		}
		add_history(line);
		shell->last_exit_status = minishell_run(shell, line);
		reset_pipe_fd(shell);
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*shell;
	char		*line;

	line = NULL;
	shell = ft_malloc(sizeof(t_minishell));
	init_shell(shell, argc, argv, envp);
	minishell_loop(shell, line);
	destroy_shell(shell);
	printf("exit\n");
	return (0);
}
