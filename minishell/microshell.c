#include "minishell.h"


void	exec(int i, int j, char **argv, char **envp)
{
	char **args;
	int k;

	args = malloc(sizeof(char *) * (i - j));
	k = 0;
	while (k < i - j)
	{
		args[k] = argv[j + k];
		printf("%s\n", args[k]);
		k++;
	}
	execve(seek_path(argv[j]), args, envp);
}

int	main(int argc, char **av, char **envp)
{
	int i;
	int j;
	int cnt;
	int *fd;
	pid_t pid;

	char *line = readline("sh> ");
	char **argv = ft_split(line, ' ');
	add_history(line);
	free(line);

	if (!strncmp(argv[0], "exit", 5))
	{
		if (argv[1])
			exit(atoi(argv[1]));
		else
			exit(0);
	}
	cnt = 1;
	i = 0;
	while(argv[i])
		if (!strcmp(argv[i++], "|"))
			cnt++;
	fd = malloc(sizeof(int) * cnt);
	i = 0; // minishell에서는 0
	j = 0;
	cnt = 0;
	while (argv[i])
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
	free(fd);
	//if (strncmp(argv[i - 1], ";", 2))
		execve(seek_path(argv[j + 1]), &argv[j + 1], envp);
	return 0;
}

void ft_sigint(void)
{
	
}

/* int	main(int argc, char **argv, char **envp)
{
	char	*line;

	while (1)
	{
		line = readline("sh> ");
		signal(SIGINT, exit(130));
		signal(SIGKILL, exit(0));
		signal(SIGQUIT, exit(131));
		semantic_express(line, envp);
		add_history(line);
		free(line);
	}
} */
