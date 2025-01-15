/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:28:37 by hyeson            #+#    #+#             */
/*   Updated: 2025/01/15 18:10:27 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

# include "libft/libft.h"

void	redirect_input(char *file);
void	redirect_output(char *file);
void	here_doc_output(char *file);
void	pipe_input(int *fd, char *argv, char **envp);
void	pipe_output(int *fd, char *argv, char **envp);
void	seek_quote(char *arg);
void	space_restore(char **split);
char	*seek_path(char *cmd, char **env);

#endif