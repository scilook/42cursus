/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:04:14 by hyeson            #+#    #+#             */
/*   Updated: 2025/01/15 18:29:23 by hyeson           ###   ########.fr       */
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
	pipex(argv, envp);
	return (0);
}
