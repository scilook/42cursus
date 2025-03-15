/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:00:52 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/15 17:06:06 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_input(char *file)
{
	int	fdin;

	fdin = open(file, O_RDONLY);
	if (fdin < 0)
	{
		perror("pipex");
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
		perror("pipex");
		exit(-1);
	}
	dup2(fdout, STDOUT_FILENO);
	close(fdout);
}
