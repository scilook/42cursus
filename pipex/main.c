/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:04:14 by hyeson            #+#    #+#             */
/*   Updated: 2025/01/17 13:19:19 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pipex(char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	redirect_input(argv[1]);
	pipe(fd);
	seek_quote(argv[2]);
	pid = fork();
	if (pid == 0)
		pipe_output(fd, argv[2], envp);
	redirect_output(argv[4]);
	seek_quote(argv[3]);
	pipe_input(fd, argv[3], envp);
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
	pipex(argv, envp);
	return (0);
}
