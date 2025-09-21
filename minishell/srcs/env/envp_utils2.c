/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.k>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:48:15 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 21:25:35 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"

void		handle_add_env(t_minishell *shell, char *env, t_var_flag flag,
				char **tmp);

static void	free_split(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	minishell_initenv(t_minishell *shell, char **envp)
{
	int		i;
	char	**tmp;

	shell->envp_size = 0;
	shell->envp = ft_malloc(sizeof(char *) * 1000);
	shell->envp_table = ft_malloc(sizeof(t_envp_table) * 1000);
	i = -1;
	while (envp[++i] != NULL)
	{
		tmp = ft_split(envp[i], "=");
		handle_add_env(shell, envp[i], 0b11, tmp);
		free_split(tmp);
	}
}

t_bool	handle_duplicate_env(t_minishell *shell, char *env, t_var_flag flag,
		char **tmp)
{
	int	i;

	i = -1;
	while (++i < shell->envp_size)
	{
		if (ft_strncmp(tmp[0], shell->envp_table[i].key, ft_strlen(tmp[0])
				+ 1) == 0)
		{
			if (ft_strchr(env, '=') != NULL)
			{
				free(shell->envp[i]);
				if (shell->envp_table[i].value != NULL)
					free(shell->envp_table[i].value);
				shell->envp[i] = ft_strdup(env);
				shell->envp_table[i].value = ft_strdup(ft_strchr(env, '=') + 1);
			}
			shell->envp_table[i].flag = shell->envp_table[i].flag | flag;
			free_split(tmp);
			return (TRUE);
		}
	}
	return (FALSE);
}

void	handle_add_env(t_minishell *shell, char *env, t_var_flag flag,
		char **tmp)
{
	shell->envp[shell->envp_size] = ft_strdup(env);
	shell->envp_table[shell->envp_size].key = ft_strdup(tmp[0]);
	if (ft_strchr(env, '=') != NULL && tmp[1] == NULL)
		shell->envp_table[shell->envp_size].value = ft_strdup("");
	else if (tmp[1] == NULL)
		shell->envp_table[shell->envp_size].value = NULL;
	else
		shell->envp_table[shell->envp_size].value = ft_strdup(tmp[1]);
	shell->envp_table[shell->envp_size].flag = flag;
	shell->envp[shell->envp_size + 1] = NULL;
	shell->envp_table[shell->envp_size + 1].key = NULL;
	shell->envp_table[shell->envp_size + 1].value = NULL;
	shell->envp_size++;
}

void	minishell_putenv(t_minishell *shell, char *env, t_var_flag flag)
{
	int		i;
	char	**tmp;

	tmp = ft_split(env, "=");
	i = 0;
	while (ft_isalnum(tmp[0][i]))
		i++;
	if (tmp[0][i] != '\0')
	{
		ft_putstr_fd("export: \'", 2);
		ft_putstr_fd(env, 2);
		ft_putstr_fd("\': not a valid identifier\n", 2);
		return ;
	}
	if (ft_strchr(env, '=') != NULL)
		flag = flag | 0b10;
	if (handle_duplicate_env(shell, env, flag, tmp))
		return ;
	handle_add_env(shell, env, flag, tmp);
	free_split(tmp);
}
