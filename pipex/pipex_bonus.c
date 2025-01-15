/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:26:00 by hyeson            #+#    #+#             */
/*   Updated: 2025/01/15 15:13:36 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	seek_quote(char *arg)
{
	size_t	i;
	char	*is_capped;

	while (ft_strchr(arg, '\'') != NULL)
	{
		is_capped = ft_strchr(arg, '\'');
		i = 1;
		while (is_capped != NULL && is_capped[i] != '\'')
		{
			if (is_capped[i] == ' ')
				is_capped[i] = -1;
			if (is_capped[i] == '\0')
				return ;
			i++;
		}
		if (is_capped != NULL)
			is_capped[0] = ' ';
		if (is_capped != NULL && is_capped[i] == '\'')
			is_capped[i] = ' ';
	}
}

void	space_restore(char **split)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (split[i] != NULL)
	{
		j = 0;
		while (split[i][j] != '\0')
		{
			if (split[i][j] == -1)
				split[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	pipe_input(int *fd, char *argv, char **envp)
{
	char	**cmds;
	char	*cmd;

	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	cmds = ft_split(argv, ' ');
	space_restore(cmds);
	cmd = seek_path(cmds[0], envp);
	if (!cmd)
		exit(127);
	if (execve(cmd, cmds, envp))
		perror("ft_sh");
}

void	pipe_output(int *fd, char *argv, char **envp)
{
	char	**cmds;
	char	*cmd;

	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	cmds = ft_split(argv, ' ');
	space_restore(cmds);
	cmd = seek_path(cmds[0], envp);
	if (!cmd)
		exit(127);
	if (execve(cmd, cmds, envp))
		perror("ft_sh");
}
