/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 23:19:12 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 03:32:50 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "ft_builtins.h"
#include "minishell.h"
#include "parser.h"
#include <fcntl.h>
#include <stdlib.h>

static void	_ft_exit(t_minishell *shell, t_command *cmd)
{
	int	status;

	status = 0;
	if (cmd->words[1] != NULL)
		status = ft_atoi(cmd->words[1]);
	destroy_shell(shell);
	ft_putstr_fd("exit\n", 1);
	exit(status);
}

t_builtin	is_builtin_command(t_command *cmd)
{
	if (cmd->words == NULL)
		return (NONE);
	if (ft_strncmp(cmd->words[0], "exit", 5) == 0)
		return (EXIT);
	else if (ft_strncmp(cmd->words[0], "cd", 3) == 0)
		return (CD);
	else if (ft_strncmp(cmd->words[0], "export", 7) == 0)
		return (EXPORT);
	else if (ft_strncmp(cmd->words[0], "unset", 6) == 0)
		return (UNSET);
	else if (ft_strncmp(cmd->words[0], "env", 4) == 0)
		return (ENV);
	else if (ft_strncmp(cmd->words[0], "pwd", 4) == 0)
		return (PWD);
	else if (ft_strncmp(cmd->words[0], "echo", 5) == 0)
		return (ECHO);
	return (NONE);
}

int	_builtin_exec(t_command *cmd, t_minishell *shell, t_builtin builtin,
		t_bool is_child)
{
	int	status;

	status = 0;
	if (builtin == EXIT)
		_ft_exit(shell, cmd);
	if (builtin == CD)
		status = (ft_cd(shell, cmd->words));
	else if (builtin == EXPORT)
		status = (ft_export(shell, cmd->words));
	else if (builtin == UNSET)
		status = (ft_unset(shell, cmd->words));
	else if (builtin == ENV)
		status = (ft_env(shell));
	else if (builtin == PWD)
		status = (ft_pwd());
	else if (builtin == ECHO)
		status = (ft_echo(cmd->words));
	if (is_child)
	{
		destroy_shell(shell);
		exit(status);
	}
	return (status);
}
