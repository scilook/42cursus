/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:25:39 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 21:20:31 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"

char	*minishell_getenv(t_minishell *shell, char *key)
{
	int		i;
	size_t	key_size;

	i = -1;
	while (++i < shell->envp_size)
	{
		key_size = ft_strlen(key);
		if (ft_strncmp(key, shell->envp_table[i].key, key_size + 1) == 0)
			return (shell->envp_table[i].value);
	}
	return (NULL);
}

char	**minishell_getpath(t_minishell *shell)
{
	char	*path;
	char	**paths;
	char	**org;

	path = minishell_getenv(shell, "PATH");
	if (path == NULL)
		return (NULL);
	paths = ft_split(path, ":");
	org = paths;
	while (*paths != NULL)
	{
		path = ft_strjoin(*paths, "/");
		free(*paths);
		*paths = path;
		++paths;
	}
	return (org);
}

void	minishell_destroyenv(t_minishell *shell)
{
	int	i;

	i = -1;
	while (++i < shell->envp_size)
	{
		free(shell->envp[i]);
		free(shell->envp_table[i].key);
		if (shell->envp_table[i].value != NULL)
			free(shell->envp_table[i].value);
	}
	free(shell->envp);
	free(shell->envp_table);
	shell->envp = NULL;
}
