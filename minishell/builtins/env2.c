/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:22:34 by hyeson            #+#    #+#             */
/*   Updated: 2025/05/17 05:07:59 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// 환경변수를 수정하고 그 상태에서 프로그램을 실행(exec)
int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		idx;
	char	**env;

	i = 0;
	while(envp[i])
		i++;
	env = malloc(sizeof(char *) * (i + 1));
	ft_bzero(env, sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		env[i] = envp[i];
		i++;
	}
	i = 1;
	while (i < argc)
	{
		if (ft_strnstr(argv[i], "=", ft_strlen(argv[i])))
		{
			idx = 0;
			while (env[idx] && ft_strncmp(argv[i], env[idx], ft_strchr(argv[i], '=') - argv[i]))
				idx++;
			if (!env[idx])
				ft_realloc(env, sizeof(char *) * (idx + 1));
			env[idx] = argv[i];
		}
		else
			execve(argv[i], argv + i, env); //절대경로 입력
		i++;
	}
	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i++]);
	}
	free(env);
	return (0);
}
