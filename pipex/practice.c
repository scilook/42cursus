int main(int ac, char **av, char **env)
{
	char *buf;
	char *path = "file";
	int fd_pipe[2];
	pipe(fd_pipe);
	int fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	pid_t pid = fork();
	if (pid == 0)
	{
		dup2(fd_pipe[0], 0);
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		if (read(fd_pipe[1], buf, 1024) < 0)
			perror("ERROR");
		printf("%s\n", buf);
	}
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	if (execve(seek_path(av[0], env), av, env) < 0)
		exit(-1);
}
