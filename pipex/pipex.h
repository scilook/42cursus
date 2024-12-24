/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:28:37 by hyeson            #+#    #+#             */
/*   Updated: 2024/12/24 15:45:50 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# include "libft/libft.h"

char	*seek_path(char *cmd, char **env);

#endif