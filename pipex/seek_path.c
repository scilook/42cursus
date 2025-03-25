/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:33:11 by hyeson            #+#    #+#             */
/*   Updated: 2025/01/17 13:18:24 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (1);
}

char	*seek_path(char *cmd, char **env)
{
	char	**path_env;
	char	*path;
	char	*tmp;
	size_t	i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	tmp = env[i] + 5;
	path_env = ft_split(tmp, ':');
	i = 0;
	while (path_env[i])
	{
		tmp = ft_strjoin(path_env[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(path, X_OK) && free_split(path_env))
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}
