/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:00:06 by hyeson            #+#    #+#             */
/*   Updated: 2025/06/28 19:40:00 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int	main(int argc, char **argv)
{
	int	i;
	int	opt;

	opt = 0;
	i = 1; // built-in으로 바꾸면 변경 될 수 있음
	while (i < argc && is_opt(argv[i]))
	{
		opt = 1;
		i++;
	}
	while (i < argc)
	{
		ft_putstr_fd(argv[i], 1);
		i++;
		if (i != argc)
			ft_putchar_fd(' ', 1);
	}
	if (opt == 0)
		ft_putchar_fd('\n', 1);
	return (0);
}
