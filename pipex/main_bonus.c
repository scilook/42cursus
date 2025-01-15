/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:02:07 by hyeson            #+#    #+#             */
/*   Updated: 2025/01/15 18:25:39 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	here_doc(char **argv, char **envp)
{
	pid_t	pid;
	size_t	i;
	int		fd[2];

	redirect_input(argv[2]);
	pipe(fd);
	i = 3;
	while (argv[i + 2])
	{
		seek_quote(argv[i]);
		pid = fork();
		if (pid == 0)
			pipe_output(fd, argv[i], envp);
		i++;
	}
	here_doc_output(argv[i + 1]);
	seek_quote(argv[i]);
	pipe_input(fd, argv[i], envp);
}

static void	pipex(char **argv, char **envp)
{
	pid_t	pid;
	size_t	i;
	int		fd[2];

	redirect_input(argv[1]);
	pipe(fd);
	i = 2;
	while (argv[i + 2])
	{
		seek_quote(argv[i]);
		pid = fork();
		if (pid == 0)
			pipe_output(fd, argv[i], envp);
		i++;
	}
	redirect_output(argv[i + 1]);
	seek_quote(argv[i]);
	pipe_input(fd, argv[i], envp);
}

int	main(int argc, char **argv, char **envp)
{
	size_t	i;
	char	**cmds;

	if (argc < 4)
		return (-1);
	i = 2;
	while (argv[i + 1])
	{
		cmds = ft_split(argv[i], ' ');
		if (!cmds)
			return (1);
		if (!seek_path(cmds[0], envp))
			exit(127);
		i++;
	}
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")))
	{
		here_doc(argv, envp);
	}
	else
	{
		pipex(argv, envp);
	}
	return (0);
}
