/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:00:52 by hyeson            #+#    #+#             */
/*   Updated: 2025/01/17 12:19:04 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	redirect_input(char *file)
{
	int	fdin;

	fdin = open(file, O_RDONLY);
	if (fdin < 0)
	{
		perror("ft_sh");
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
		perror("ft_sh");
		exit(1);
	}
	dup2(fdout, STDOUT_FILENO);
	close(fdout);
}

void	here_doc_input(char *limit)
{
	char	*line;

	line = NULL;
	if (ft_strncmp(limit, line, ft_strlen(limit)))
		return ;
}

void	here_doc_output(char *file)
{
	int	fdout;

	fdout = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fdout < 0)
	{
		perror("ft_sh");
		exit(1);
	}
	dup2(fdout, STDOUT_FILENO);
	close(fdout);
}
