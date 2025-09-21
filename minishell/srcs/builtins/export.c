/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:50:08 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:52:41 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"
#include <stdio.h>

static t_envp_table	*str_order_ascend(t_envp_table *table, int size)
{
	t_envp_table	*sorted;
	t_envp_table	tmp;
	int				i;
	int				j;

	sorted = ft_malloc(sizeof(t_envp_table) * size);
	ft_memcpy(sorted, table, sizeof(t_envp_table) * size);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strncmp(sorted[i].key, sorted[j].key,
					ft_strlen(sorted[i].key) + 1) > 0)
			{
				tmp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (sorted);
}

void	_only_print(t_minishell *shell, char **argv)
{
	t_envp_table	*sorted;
	int				i;

	if (argv[1] == NULL)
	{
		sorted = str_order_ascend(shell->envp_table, shell->envp_size);
		i = 0;
		while (i < shell->envp_size)
		{
			if ((sorted[i].flag & 0b01) != 0)
			{
				printf("declare -x %s", sorted[i].key);
				if ((sorted[i].flag & 0b10) != 0)
					printf("=\"%s\"", sorted[i].value);
				printf("\n");
			}
			i++;
		}
		free(sorted);
	}
}

int	ft_export(t_minishell *shell, char **argv)
{
	int	i;

	_only_print(shell, argv);
	i = 1;
	while (argv[i] != NULL)
	{
		minishell_putenv(shell, argv[i], EXPORT_FLAG);
		i++;
	}
	return (0);
}
