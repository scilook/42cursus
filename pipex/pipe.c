/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:26:00 by hyeson            #+#    #+#             */
/*   Updated: 2024/12/26 17:46:48 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "stdio.h"

void	pipe_input(int *fd, int num, char **argv, char **envp)
{
	char	**cmd;

	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	cmd = ft_split(argv[num], ' ');
	if (execve(seek_path(cmd[0], envp), cmd, envp))
		perror("ERROR");
}

void	pipe_output(int *fd, int num, char **argv, char **envp)
{
	char	**cmd;

	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	cmd = ft_split(argv[num], ' ');
	if (execve(seek_path(cmd[0], envp), cmd, envp))
		perror("ERROR");
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	pid_t	pid2;
	int		fd[2];

	if (argc != 5)
		return (-1);
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		redirect_input(argv[1]);
		pipe_output(fd, 2, argv, envp);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		redirect_output(argv[4]);
		pipe_input(fd, 3, argv, envp);
	}
	close(fd[0]);
	close(fd[1]);
}
