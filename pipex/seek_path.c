/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:33:11 by hyeson            #+#    #+#             */
/*   Updated: 2024/12/26 12:47:39 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

char	*seek_path(char *cmd, char **env)
{
	char	**path_env;
	char	*path;
	char	*tmp;
	size_t	i;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	env[i] = env[i] + 5;
	path_env = ft_split(env[i], ':');
	i = 0;
	while (path_env[i] != NULL)
	{
		tmp = ft_strjoin(path_env[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(path, X_OK))
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}
