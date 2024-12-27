/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:26:00 by hyeson            #+#    #+#             */
/*   Updated: 2024/12/27 18:14:34 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	special_guard(char *arg)
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
	char	**cmd;

	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	cmd = ft_split(argv, ' ');
	space_restore(cmd);
	if (execve(seek_path(cmd[0], envp), cmd, envp))
		perror("ERROR");
}

void	pipe_output(int *fd, char *argv, char **envp)
{
	char	**cmd;

	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	cmd = ft_split(argv, ' ');
	space_restore(cmd);
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
		special_guard(argv[2]);
		pipe_output(fd, argv[2], envp);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		redirect_output(argv[4]);
		special_guard(argv[3]);
		pipe_input(fd, argv[3], envp);
	}
	close(fd[0]);
	close(fd[1]);
}
