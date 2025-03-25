/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:28:37 by hyeson            #+#    #+#             */
/*   Updated: 2025/01/17 13:18:42 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

# include "libft/libft.h"

void	redirect_input(char *file);
void	redirect_output(char *file);
void	pipe_input(int *fd, char *argv, char **envp);
void	pipe_output(int *fd, char *argv, char **envp);
void	seek_quote(char *arg);
void	space_restore(char **split);
char	*seek_path(char *cmd, char **env);
int		free_split(char **split);

#endif