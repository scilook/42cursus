/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:06:49 by hyeson            #+#    #+#             */
/*   Updated: 2025/05/27 15:59:54 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	*seek_path(char *cmd)
{
	char	**path_env;
	char	*path;
	char	*tmp;
	size_t	i;

	tmp = getenv("PATH");
	path_env = ft_split(tmp, ':');
	i = 0;
	while (path_env[i])
	{
		tmp = ft_strjoin(path_env[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(path, X_OK))
		{
			free_split(path_env);
			return (path);
		}
		free(path);
		i++;
	}
	free_split(path_env);
	return (cmd);
}
/* 
int main()
{
	char *line;
	char *path;
	pid_t pid;

	while (1)
	{
		line = readline("sh> ");
		path = seek_path(line);
		signal()
		printf("%s\n", path);
		pid = fork();
		if (pid == 0)
			if(execve(path, &path, NULL))
				perror(path);
		wait(NULL);
		free(line);
	}
} */
