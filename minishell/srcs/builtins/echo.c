/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:00:06 by hyeson            #+#    #+#             */
/*   Updated: 2025/09/16 23:02:27 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_opt(char *opt)
{
	int	i;

	if (opt[0] != '-')
		return (0);
	i = 1;
	while (opt[i] == 'n')
		i++;
	if (opt[i] == '\0')
		return (1);
	else
		return (0);
}

int	ft_echo(char **argv)
{
	int	i;
	int	opt;

	opt = 0;
	i = 1;
	while (argv[i] != NULL && is_opt(argv[i]) != 0)
	{
		opt = 1;
		i++;
	}
	while (argv[i] != NULL)
	{
		ft_putstr_fd(argv[i], 1);
		i++;
		if (argv[i] != NULL)
			ft_putchar_fd(' ', 1);
	}
	if (opt == 0)
		ft_putchar_fd('\n', 1);
	return (0);
}
