/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:00:52 by hyeson            #+#    #+#             */
/*   Updated: 2025/01/21 14:19:06 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	redirect_input(char *file)
{
	int	fdin;

	fdin = open(file, O_RDONLY);
	if (fdin < 0)
	{
		perror("pipex");
		exit(1);
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
		perror("pipex");
		exit(1);
	}
	dup2(fdout, STDOUT_FILENO);
	close(fdout);
}

void	here_doc_input(char *limit)
{
	int		fd[2];
	char	*line;
	size_t	length;

	pipe(fd);
	length = ft_strlen(limit);
	write(STDOUT_FILENO, "> ", 3);
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (!ft_strncmp(line, limit, length) && ft_strlen(line) == length + 1)
			return ;
		write(STDOUT_FILENO, "> ", 3);
		line = get_next_line(STDIN_FILENO);
	}
}

void	here_doc_output(char *file)
{
	int	fdout;

	fdout = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fdout < 0)
	{
		perror("pipex");
		exit(1);
	}
	dup2(fdout, STDOUT_FILENO);
	close(fdout);
}
