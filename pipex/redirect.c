/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:00:52 by hyeson            #+#    #+#             */
/*   Updated: 2024/12/24 18:43:18 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_input(char *file)
{
	int	fdin;

	fdin = open(file, O_RDONLY);
	if (fdin < 0)
	{
		perror("file error: ");
		exit(-1);
	}
	dup2(fdin, STDIN_FILENO);
	close(fdin);
}

void	redirect_output(char *file)
{
	int	fdout;

	fdout = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fdout < 0)
	{
		perror("file error");
		exit(-1);
	}
	dup2(fdout, STDOUT_FILENO);
	close(fdout);
}

int main(int ac, char **av, char **env)
{
	char *buf;
	char *path = "file";
	int fd_pipe[2];
	pipe(fd_pipe);
	int fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	pid_t pid = fork();
	if (pid == 0)
	{
		dup2(fd_pipe[0], 0);
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		if (read(fd_pipe[1], buf, 1024) < 0)
			perror("ERROR");
		printf("%s\n", buf);
	}
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	if (execve(seek_path(av[0], env), av, env) < 0)
		exit(-1);
}