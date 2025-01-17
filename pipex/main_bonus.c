/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:02:07 by hyeson            #+#    #+#             */
/*   Updated: 2025/01/17 13:16:47 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	here_doc(int argc, char **argv, char **envp)
{
	pid_t	pid;
	size_t	i;
	int		fd[2];

	if (argc < 5)
		return ;
	here_doc_input(argv[2]);
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

static void	pipex(int argc, char **argv, char **envp)
{
	pid_t	pid;
	size_t	i;
	int		fd[2];

	if (argc < 4)
		return ;
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
	char	*path;
	char	**cmds;

	i = 2;
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")))
		i++;
	while (argv[i + 1])
	{
		cmds = ft_split(argv[i], ' ');
		if (!cmds)
			return (1);
		path = seek_path(cmds[0], envp);
		if (!path && free_split(cmds))
			exit(127);
		free(path);
		free_split(cmds);
		i++;
	}
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")))
		here_doc(argc, argv, envp);
	else
		pipex(argc, argv, envp);
	return (0);
}
