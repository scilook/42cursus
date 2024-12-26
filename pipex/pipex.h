/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:28:37 by hyeson            #+#    #+#             */
/*   Updated: 2024/12/26 12:53:58 by hyeson           ###   ########.fr       */
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
void	pipex(char **argv, char **envp);
char	*seek_path(char *cmd, char **env);

#endif