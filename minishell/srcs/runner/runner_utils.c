/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:00:09 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 04:23:06 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"
#include <fcntl.h>
#include <readline/readline.h>
#include <sys/wait.h>

t_bool	dup2_and_close(int old, int new)
{
	if (old == -1)
		return (FALSE);
	dup2(old, new);
	close(old);
	return (TRUE);
}

t_bool	dup_redirect(const t_command *cmd)
{
	t_bool				is_success;
	const t_redirect	*red = cmd->redirects;

	while (red != NULL)
	{
		is_success = TRUE;
		if (red->instruction == R_INPUT_REDIRECTION)
			is_success = dup2_and_close(open(red->redirector.filename,
						O_RDONLY), STDIN_FILENO);
		else if (red->instruction == R_OUTPUT_REDIRECTION)
			is_success = dup2_and_close(open(red->redirector.filename,
						O_WRONLY | O_CREAT | O_TRUNC, 0644), STDOUT_FILENO);
		else if (red->instruction == R_APPENDING_TO)
			is_success = dup2_and_close(open(red->redirector.filename,
						O_WRONLY | O_CREAT | O_APPEND, 0644), STDOUT_FILENO);
		if (!is_success)
			return (FALSE);
		red = red->next;
	}
	return (TRUE);
}

int	wait_command(t_command *cmd)
{
	t_command	*cur;
	int			exit_status;

	cur = cmd;
	while (cur->pipe != NULL)
	{
		waitpid(cur->runtime.pid, NULL, 0);
		cur = cur->pipe;
	}
	waitpid(cur->runtime.pid, &exit_status, 0);
	if (WIFEXITED(exit_status))
		return (WEXITSTATUS(exit_status));
	if (WIFSIGNALED(exit_status))
		return (128 + exit_status);
	return (-1);
}

char	*find_filename_or_null(t_minishell *shell, char *cmd)
{
	int		i;
	char	**org_paths;
	char	**paths;
	char	*filename;

	if (cmd == NULL)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	paths = minishell_getpath(shell);
	org_paths = paths;
	while (paths != NULL && paths[i] != NULL)
	{
		filename = ft_strjoin(paths[i], cmd);
		if (access(filename, X_OK) == 0)
			return (filename);
		free(filename);
		free(paths[i]);
		++paths;
	}
	access(cmd, X_OK);
	if (org_paths != NULL)
		free(org_paths);
	return (NULL);
}
