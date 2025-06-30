/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:23:20 by hyeson            #+#    #+#             */
/*   Updated: 2025/05/23 12:02:47 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//지우세요 현위치 테스트용
void	cd_test(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	ft_putstr_fd(buf, 1);
	write(1, "\n", 1);
	free(buf);
}

// fork()하지 않고 작업을 수행
int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		chdir(getenv("HOME"));
		cd_test(); // 지우세요
		return (0);
	}
	if (argc > 2)
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
	cd_test(); // 지우세요
	return (0);
}

// cd는 shell에서 지원하는 기능임 $PATH아래 어느 하나에 위치하지 않음
// cd는 error control을 shell 에서 한다. 아래는 예시
// when argc > 2;
// bash> bash: cd: too many arguments
// fish> cd: too many arguments
// zsh > cd: string not in pwd: <input>

// when argv[1] is wrong path
// bash> bash: cd: <input>: No such file or directory
// fish> cd: The directory "<input>" does not exist
// zsh > cd: no such file or directory: <input>

