/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:34:05 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 20:30:35 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "expander.h"
#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

extern int	g_sig;

void	heredoc_sig_handler(int signum)
{
	(void)signum;
	g_sig = 2;
	ft_putchar_fd('\n', STDOUT_FILENO);
	close(STDIN_FILENO);
}

static char	*_create_tempfile_name(void)
{
	static int	count = 0;
	char		*count_str;
	char		*slot_str;
	char		*temp_file_name;

	count_str = ft_itoa(count);
	slot_str = ft_itoa(ttyslot());
	temp_file_name = ft_malloc(255);
	ft_strcpy(temp_file_name, "/var/tmp/temp_");
	ft_strcat(temp_file_name, slot_str);
	ft_strcat(temp_file_name, "_");
	ft_strcat(temp_file_name, count_str);
	free(count_str);
	free(slot_str);
	return (temp_file_name);
}

static void	_heredoc_loop(t_minishell *shell, t_redirect *redir)
{
	char	*line;
	char	*temp_file_name;
	int		temp_fd;

	temp_file_name = _create_tempfile_name();
	temp_fd = open(temp_file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (g_sig != 2)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (ft_strncmp(line, redir->here_doc_eof, ft_strlen(redir->here_doc_eof)
				+ 1) == 0)
		{
			free(line);
			break ;
		}
		parameter_expand(shell, &line);
		write(temp_fd, line, ft_strlen(line));
		write(temp_fd, "\n", 1);
		free(line);
	}
	close(temp_fd);
	redir->instruction = R_INPUT_REDIRECTION;
	redir->redirector.filename = temp_file_name;
}

void	process_heredoc(t_minishell *shell, t_command *commands)
{
	t_redirect	*red;
	t_command	*cur;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, heredoc_sig_handler);
	cur = commands;
	while (cur != NULL)
	{
		red = cur->redirects;
		while (red != NULL)
		{
			if (red->instruction == R_HERE_DOC)
				_heredoc_loop(shell, red);
			red = red->next;
		}
		cur = cur->pipe;
	}
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_handler);
	dup2(shell->stdin_fd, STDIN_FILENO);
	g_sig = 1;
}
