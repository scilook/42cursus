/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.k>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:17:28 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 18:19:32 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include <readline/readline.h>
#include <signal.h>

extern int	g_sig;

void	sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_on_new_line();
		if (g_sig == 0)
			rl_redisplay();
	}
}

void	init_shell(t_minishell *shell, int argc, char **argv, char **envp)
{
	((void)(argc));
	((void)(argv));
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_handler);
	shell->last_exit_status = 0;
	minishell_initenv(shell, envp);
	shell->stdin_fd = dup(0);
	shell->stdout_fd = dup(1);
	shell->pipe_in_fd = dup(0);
	shell->pipe_out_fd = dup(1);
	shell->parser = NULL;
	shell->tokens = NULL;
}

void	destroy_shell(t_minishell *shell)
{
	if (shell->tokens != NULL)
		token_destroy_all(shell->tokens);
	if (shell->parser != NULL)
		parser_destroy(shell->parser);
	close(shell->stdin_fd);
	close(shell->stdout_fd);
	close(shell->pipe_in_fd);
	close(shell->pipe_out_fd);
	minishell_destroyenv(shell);
	free(shell);
}
