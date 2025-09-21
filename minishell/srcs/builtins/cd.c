/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:23:20 by hyeson            #+#    #+#             */
/*   Updated: 2025/09/17 01:07:14 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int	ft_cd(t_minishell *shell, char **argv)
{
	if (argv[1] == NULL)
	{
		chdir(minishell_getenv(shell, "HOME"));
		return (0);
	}
	if (argv[2] != NULL)
	{
		write(2, "bash: cd: too many arguments\n", 29);
		return (1);
	}
	if (chdir(argv[1]))
	{
		write(2, "bash: cd: ", 10);
		perror(argv[1]);
		return (1);
	}
	return (0);
}
