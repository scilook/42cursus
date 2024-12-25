/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:26:00 by hyeson            #+#    #+#             */
/*   Updated: 2024/12/25 17:47:34 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "stdio.h"

void	pipex(char **argv, char **envp, size_t i)
{
	pid_t	pid;
	char	**cmd;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		cmd = ft_split(argv[i++], ' ');
		execve(seek_path(cmd[0], envp), cmd, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		cmd = ft_split(argv[i++], ' ');
		execve(seek_path(cmd[0], envp), cmd, envp);
	}
	close(fd[0]);
	close(fd[1]);
}
