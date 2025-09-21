/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:50:08 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:09:12 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int	ft_env(t_minishell *shell)
{
	int	i;

	i = 0;
	while (shell->envp[i])
	{
		if (shell->envp_table[i].flag & 0b10)
			printf("%s\n", shell->envp[i]);
		i++;
	}
	return (0);
}
