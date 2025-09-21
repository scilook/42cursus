/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 23:10:29 by hyeson            #+#    #+#             */
/*   Updated: 2025/09/17 00:33:04 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_envp(t_minishell *shell, int i)
{
	free(shell->envp_table[i].key);
	free(shell->envp_table[i].value);
	free(shell->envp[i]);
	while (shell->envp_table[i].key != NULL)
	{
		shell->envp_table[i].key = shell->envp_table[i + 1].key;
		shell->envp_table[i].value = shell->envp_table[i + 1].value;
		shell->envp[i] = shell->envp[i + 1];
		i++;
	}
	shell->envp_table[i].key = NULL;
	shell->envp_table[i].value = NULL;
	shell->envp[i] = NULL;
	shell->envp_size--;
}

int	ft_unset(t_minishell *shell, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j] != NULL)
	{
		if (ft_strncmp(shell->envp_table[i].key, argv[j], ft_strlen(argv[j])
				+ 1) == 0)
		{
			unset_envp(shell, i);
			i = 0;
			j++;
			continue ;
		}
		i++;
		if (shell->envp_table[i].key == NULL)
		{
			i = 0;
			j++;
		}
	}
	return (0);
}
