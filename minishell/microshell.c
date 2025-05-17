#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>

void	exec(int i, int j, char **argv, char **envp)
{
	char **args;
	int k;

	args = malloc(sizeof(char *) * (i - j));
	k = 0;
	while (k < i - j)
	{
		args[k] = argv[j + k];
		k++;
	}
	execve(argv[j], args, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int i;
	int j;
	int cnt;
	pid_t pid;
	int fd[100];

	i = 1; // minishell에서는 0
	j = 0;
	cnt = 0;
	while (i < argc)
	{
		wait(0);
		if (strncmp(argv[i], ";", 2) == 0)
		{
			if (!strncmp(argv[j + 1], "cd", 3))
				chdir(argv[j + 2]);
			else
			{
				pid = fork();
				if (pid == 0)
					exec(i, j + 1, argv, envp);
				j = i;
			}
		}
		else if (strncmp(argv[i], "|", 2) == 0)
		{
			pipe(fd + cnt);
			pid = fork();
			if (pid == 0)
			{
				close(fd[cnt]);
				dup2(fd[cnt + 1], 1);
				close(fd[cnt + 1]);
				exec(i, j + 1, argv, envp);
			}
			close(fd[cnt + 1]);
			dup2(fd[cnt], 0);
			close(fd[cnt]);
			j = i;
			cnt++;
		}
		i++;
	}
	if (strncmp(argv[i - 1], ";", 2))
		execve(argv[j + 1], &argv[j + 1], envp);
}
